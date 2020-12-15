#ifndef RESHAPE_H
#define RESHAPE_H
#include "event.h"

class ReshapeEvent : public Event
{
public:
   ReshapeEvent(int, int);
   void doAction(Canvas &);
};

#endif
