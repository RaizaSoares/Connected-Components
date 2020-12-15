/*
                ***** graphics.cpp *****

OpenGL/GLUT graphics module for image display.

Author: John M. Weiss, Ph.D.
Class:  CSC 315 Data Structures & Algorithms
Date:   Spring 2018
*/

// #include <iostream>
#include <cstdio>
#include <GL/glut.h>
#include <iostream>
using namespace std;

typedef unsigned char byte;

// symbolic constants
const int ESC = 27;

/******************************************************************************/

// display 24-bit color image
void displayColor( int x, int y, int w, int h, byte** image )
{
    glRasterPos2i( x, y );

    while (w % 4 != 0) w++;

    glDrawPixels( w, h, GL_RGBA, GL_UNSIGNED_BYTE, *image );
}

// display 8-bit monochrome image
void displayMonochrome( int x, int y, int w, int h, byte** image )
{
    glRasterPos2i( x, y );

    while (w % 4 != 0) w++;

    glDrawPixels( w, h, GL_LUMINANCE, GL_UNSIGNED_BYTE, *image );
}

// write a text string
void DrawTextString( char *string, int x, int y, byte r, byte g, byte b )
{
    glColor3ub( r, g, b );
    glRasterPos2i( x, y );
    while ( *string )
    {
        glutBitmapCharacter( GLUT_BITMAP_8_BY_13, *string );
        string++;
    }
}
