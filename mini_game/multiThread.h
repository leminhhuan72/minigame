#ifndef _THREAD_H_
#define _THREAD_H_

#include "cGame.h"
#include <thread>
#include <stdlib.h>

using namespace std;
char MOVING;
CGAME cg;   
bool IS_RUNNING;//->> global variables
void exitGame(thread* t);     //
void SubThread();


#endif _THREAD_H_
