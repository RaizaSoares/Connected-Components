/********************************************************************//**
 * @file
 ***********************************************************************/
#include "canvas.h"

Canvas::Canvas() : threshold(128), filterSize(32)
{
    // generate random pseudocolor palette
    for ( unsigned i = 1; i < 256; ++i )
        for ( unsigned rgb = 0; rgb < 3; ++rgb )
		   pal[rgb][i] = rand() % 256;
}

void Canvas::display()
{
    glClear( GL_COLOR_BUFFER_BIT );

    // display four images
	
    displayMonochrome( width, 0, width, height, imageMono );
    binaryThreshold();
	
    displayMonochrome( width, height, width, height, imageBinThresh );
    assignLabels(); 
    filter = false;
    makePseudoColorImage();
    displayColor( 0, height, width, height, imagePseudo );
    filter = true;
    pseudocolor();
    displayColor( 0, 0, width, height, imagePseudo );
	char str[257];
	
	string s=std::to_string(threshold);
	char const *pchar = s.c_str();
	sprintf( str, "%s", pchar );
   DrawTextString( str, width, height+ height*0.9, 255, 255, 255 );
   sprintf( str, "Threshold: " );
    DrawTextString( str, width-width/4 +width/13, height +height*0.9, 255, 255, 255 );
	sprintf( str, "Filter size: 32" );
    DrawTextString( str, width-width/4 +width/12, height +height*0.85, 255, 255, 255 );
    sprintf( str, "Size filtered" );
    DrawTextString( str, 8, 8, 255, 255, 255 );
    sprintf( str, "Grayscale Image" );
    DrawTextString( str, width + 8, 8, 255, 255, 255 );
    sprintf( str, "Binary Thresholding" );
    DrawTextString( str, width + 8, height + 8, 255, 255, 255 );
    sprintf( str, "Connected components" );
    DrawTextString( str, 8, height + 8, 255, 255, 255 );

    glFlush();
}

void Canvas::DrawTextString( char *string, int x, int y, byte r, byte g, byte b )
{
    glColor3ub( r, g, b );
    glRasterPos2i( x, y );
    while ( *string )
    {
        glutBitmapCharacter( GLUT_BITMAP_8_BY_13, *string );
        string++;
    }
}

void Canvas::assignLabels()
{
   set = new DisjSets(width*height);

    label= alloc2D(height, width);

    for(unsigned i = 0; i < height; i++)
    {
        for(unsigned j = 0; j < width; j++)
        {
            label[i][j] =  imageBinThresh[i][j];
        }
    }

    for(unsigned row=0; row<height; row++)
    {
        for(unsigned col=1; col< width; col++)
        {
            if(label[row][ col] != 0 && label[row][ col-1]!=0)
                set->unionSets(row*width +col, row*width +col-1);
        }
    }

    for(unsigned row=1; row<height; row++)
    {
        for(unsigned col=0; col< width; col++)
        {
            //(row, col), and (row-1, col)
            if(label[row][ col] != 0 && label[row-1][ col]!=0)
                set->unionSets(row*width +col, (row-1)*width +col);
        }
    }
}

void Canvas::binaryThreshold()
{
    unsigned nrows = height;
    unsigned ncols = width;
    imageBinThresh = alloc2D( nrows, ncols );

    // generate binary thresholded image 
    for ( unsigned row = 0; row < nrows; ++row )
        for ( unsigned col = 0; col < ncols; ++col )
            imageBinThresh[row][col] = imageMono[row][col] < threshold ? 0 : 255;
}

// Create a 8-bit grayscale intensity image from 24-bit RGB color image
void Canvas::grayscale()
{
    imageMono = alloc2D( height, width );
    byte* img = *imageRGB;
    for ( unsigned row = 0; row < height; ++row )
    {   
        for ( unsigned col = 0; col < width; ++col )
        {   
            int r = *img++;
            int g = *img++;
            int b = *img++;
            imageMono[row][col] = 0.3 * r + 0.6 * g + 0.1 * b + 0.5;
            img++;
        }
    }
}

void Canvas::makePseudoColorImage()
{
    unsigned row, col;
    unsigned countLabel=1;

    int *array = new int[width*height];

    for(row=0; row<height; row++)
    {
        for(col=0; col<width; col++)
        {
            if(label[row][col]!=0)
            {
                int root=set->find(row*width +col);
                if(array[root]==0)
                    array[root]=countLabel++;
                label[row][col]=array[root];
            }
        }
    }

    for(unsigned row = 0 ; row < height ; row++)
       for (unsigned col = 0 ; col < width ; col++)
          if (histogram.find(label[row][col]) == histogram.end())
             histogram[label[row][col]] = 1;
          else
             histogram[label[row][col]]++;
 
    delete array;
    pseudocolor();
}

// generate random pseudocolor image from an 8-bit grayscale image
void Canvas::pseudocolor()
{
    // create 32-bit color image (array of RGBA values)
    unsigned nrows = height;
    unsigned ncols = width;
    imagePseudo = alloc2D( nrows, ncols * 4 );
    byte* pixels = *imagePseudo;

    // generate pseudocolored image
    for ( unsigned row = 0; row < nrows; ++row )
	{ for ( unsigned col = 0; col < ncols; ++col )
        {
            byte pix = label[row][col];
            byte clear = (filter) ? 0 : pix;
            for ( unsigned rgb = 0; rgb < 3; ++rgb )
                *pixels++ = (histogram[pix] < filterSize) ? clear : pal[rgb][pix];
            pixels++;       // skip alpha channel
        }
	}
}
