#ifndef ALLOC2D_H
#define ALLOC2D_H

typedef unsigned char byte;

int** alloc2D_32( int nrows, int ncols );
byte** alloc2D( int nrows, int ncols );
void free2D( byte** image );
#endif
