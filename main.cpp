#include <iostream>
#include "util.h"

using namespace std;

/***************************************************************************//**
 * @brief main function
 *
 * @param[in] argc - Integer describing the number of command line arguments
 * @param[in] argv - Array of character strings that stores command line args
 *
 * @returns 0 iff the program exits normally
 ******************************************************************************/
int main(int argc, char** argv)
{
   char *filename = nullptr;

   // Expect the user to give a path to a file to open
   if (argc != 2)
   {
      cout << "Usage: " << argv[0] << " image.png" << endl;
      return 1;
   }
   filename = argv[1];

   glutInit(&argc, argv);
   initOpenGL(filename);
   glutMainLoop();

   return 0;
}
