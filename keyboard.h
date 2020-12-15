/** ***************************************************************************
 * @file
 *
 * @par Description:
 *      Adds keyboard functionality
 *
 * @author Raiza and Kalel
 * @date 11/6/19
 *
 ** ***************************************************************************/
#ifndef KEYBOARD_H
#define KEYBOARD_H
#define ESCAPE_KEY 27
#include "event.h"

class KeyboardEvent : public Event
{
   unsigned char key;
public:
   KeyboardEvent(unsigned char, int, int);
   void doAction(Canvas &);
};

#endif
