//#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "firstPass.h"

using namespace std;

typedef unsigned char byte;

/*byte** alloc2D( int nrows, int ncols );
byte **assignLabels(unsigned int w, unsigned int h, byte **binImage);*/

TEST_CASE("Test small sample image")
{
   byte **bImage = alloc2D(9, 9);
   bImage[0][0] = 1; bImage[0][1] = 1; bImage[0][2] = 1;
   bImage[1][0] = 1; bImage[1][1] = 1; bImage[1][2] = 1;
   bImage[2][0] = 1; bImage[2][1] = 1; bImage[2][2] = 1;

   bImage[4][0] = 1; bImage[4][1] = 1; bImage[4][2] = 1;
   bImage[5][0] = 1; bImage[5][1] = 1; bImage[5][2] = 1;
   bImage[6][0] = 1; bImage[6][1] = 1; bImage[6][2] = 1;

   byte **result = assignLabels(9, 9, bImage);

   for (int row = 0 ; row < 9 ; row++)
   {
      for (int col = 0 ; col < 9 ; col++)
         if (row < 4 && result[row][col] != 0)
            REQUIRE(result[row][col] == 1);
         else if (row > 3 && result[row][col] != 0)
            REQUIRE(result[row][col] == 2);
   }
}

TEST_CASE("Test small image with two squares")
{
	/*
	000000000
	000001110
	000001110
	000000000
	000110000
	000110000
	000110000
	000000000
	000000000
	*/
   byte **bImage = alloc2D(9, 9);
   for(int i=0; i<9; i++)
   {
	   bImage[0][i]= 0;
   }
   for(int i=0; i<5; i++)
   {
	   bImage[1][i]= 0;
   }
  
   bImage[1][5] = 1; bImage[1][6] = 1; bImage[1][7] = 1; bImage[1][8]=0;
   for(int i=0; i<5; i++)
   {
	   bImage[2][i]= 0;
   }
   bImage[2][5] = 1; bImage[2][6] = 1; bImage[2][7] = 1; bImage[2][8]=0;
   for(int i=0; i<9; i++)
   {
	   bImage[3][i]= 0;
   }
   for(int i=0; i<3; i++)
   {
	   bImage[4][i]= 0;
   }
   bImage[4][3] = 1; bImage[4][4] = 1; 
   for(int i=5; i<9; i++)
   {
	   bImage[4][i]= 0;
   }

	for(int i=0; i<3; i++)
   {
	   bImage[5][i]= 0;
   }
   bImage[5][3] = 1; bImage[5][4] = 1; 
   for(int i=5; i<9; i++)
   {
	   bImage[5][i]= 0;
   }
   for(int i=0; i<3; i++)
   {
	   bImage[6][i]= 0;
   }
   bImage[6][3] = 1; bImage[6][4] = 1; 
   for(int i=5; i<9; i++)
   {
	   bImage[6][i]= 0;
   }
   
   for(int i=7; i<9; i++)
   {
	   for(int j=0; j<9; j++)
		   bImage[i][j]=0;
   }
   byte **result = assignLabels(9, 9, bImage);
   

   REQUIRE(result[1][5] == result[1][6]);
   REQUIRE(result[1][6] == result[1][7]);
   REQUIRE(result[1][7] == result[2][5]);
   REQUIRE(result[2][5] == result[2][6]);
   REQUIRE(result[2][6] == result[2][7]);
   REQUIRE(result[5][3] == result[5][4]);
   REQUIRE(result[5][4] == result[6][3]);
   REQUIRE(result[6][3] == result[6][4]);
   REQUIRE(result[6][3] == result[4][3]);
   REQUIRE(result[6][3] == result[4][4]);
   
   REQUIRE(result[1][7] != result[5][4]);
   
}
