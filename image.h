/*
                ***** image.h *****

Include file for connected components analysis.


Class:  CSC 315 Data Structures
Date:   Fall 2017
*/

#ifndef IMAGE_H
#define IMAGE_H
#include"firstPass.h"
// convenience data type
typedef unsigned char byte;

// function prototypes
byte** alloc2D( int nrows, int ncols );
int** alloc2D_32( int nrows, int ncols );
void free2D( byte** image );
byte** readPNG( char* filename, unsigned& width, unsigned& height );
byte** grayscale( unsigned width, unsigned height, byte** rgba );
byte** binaryThreshold( unsigned width, unsigned height, byte** image, unsigned thresh );
byte** pseudocolor( unsigned width, unsigned height, byte** image );
void initOpenGL( const char *filename, unsigned w, unsigned h, byte** imgRGBA, byte** imgGray, byte** imgBinThr, byte** imgPseudo , int threshval);

#endif
