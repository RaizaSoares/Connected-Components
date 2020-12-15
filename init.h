/***************************************************************************//**
 * @file init.h
 ******************************************************************************/
#ifndef INIT_H
#define INIT_H

#include "callbacks.h"
#include "lodepng.h"
#include "imageio.h"
#include <string>


/***************************************************************************//**
 * @class InitEvent
 ******************************************************************************/
class InitEvent : public Event
{
   char *fileName;
   byte threshold;
public:
   InitEvent(char *);
   void doAction(Canvas &);
};

#endif
