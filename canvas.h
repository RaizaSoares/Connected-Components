/********************************************************************//**
 * @file
 ***********************************************************************/
#ifndef CANVAS_H
#define CANVAS_H
#include <unordered_map>
#include "GL/freeglut.h"
#include "graphics.h"
#include "alloc2d.h"
#include "disjointSet.h"

using namespace std;

typedef unsigned char byte;

/********************************************************************//**
 * @class Canvas
 **********************************************************************/
class Canvas
{
public:
   byte **imageRGB;
   byte **imageMono;
   byte **imageBinThresh;
   byte **imagePseudo;
   byte **imageFiltered;
   byte **label;
   byte pal[3][256] = { 0 };

   int threshold;
   int filterSize;
   unsigned int width;
   unsigned int height;
   bool filter;
   DisjSets *set;
   unordered_map<int,int> histogram;

   Canvas();

   void assignLabels();
   void grayscale();
   void binaryThreshold();
   void display();
   void makePseudoColorImage();
   void pseudocolor();
   void DrawTextString( char *string, int x, int y, byte r, byte g, byte b );
};
#endif
