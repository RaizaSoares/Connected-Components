/** ***************************************************************************
 * @file
 *
 * @par Description:
 *      keyboard functionality functions
 *
 * @author Raiza and Kalel
 * @date 11/6/19
 *
 ** ***************************************************************************/
#include "keyboard.h"


KeyboardEvent::KeyboardEvent(unsigned char k, int x, int y) : Event(), key(k) {}

void KeyboardEvent::doAction(Canvas &canvas)
{
	 if (key == ESCAPE_KEY || key == 'q')
      glutLeaveMainLoop();

	if(key =='<')
	{
		canvas.threshold--;
		canvas.display();
	}
	if(key =='>')
	{
		canvas.threshold++;
		canvas.display();
	}
	
	
   glutPostRedisplay();
}
