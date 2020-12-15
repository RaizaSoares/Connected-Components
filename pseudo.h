#ifndef PSEUDO_H
#define PSEUDO_H
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include "lodepng.h"
#include "image.h"

typedef unsigned char byte;

byte** grayscale(unsigned width, unsigned height, byte** rgba );
byte** binaryThreshold(unsigned, unsigned, byte**, unsigned);
byte** pseudocolor(unsigned, unsigned, byte**, int);

#endif
