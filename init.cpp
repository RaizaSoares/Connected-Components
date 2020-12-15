#include "init.h"

InitEvent::InitEvent(char *f) : fileName(f) { }

void InitEvent::doAction(Canvas &canvas)
{
   // Read the PNG image and point to it with canvas.imageRGB
   canvas.imageRGB = readPNG(fileName, canvas.width, canvas.height);
 
   // Convert the color RGB image to a grayscale image.  This is not the
   // energy image, just a placeholder until you write the code to convert
   // the color image to the energy map
   canvas.grayscale();

   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
   glutInitWindowSize(canvas.width*2, canvas.height*2);
   glutInitWindowPosition(0, 0);
   glutCreateWindow(fileName);
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutReshapeFunc(reshape);
}
