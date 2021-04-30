#ifndef __TEDDY_H
#define __TEDDY_H
#include "good.h" 


struct teddy {
  char name[MAX_TEDDY_NAME + 1];  
  struct wallet w;  
  int priority;
  int time ;           // time when a teddy is activated 
};

#endif
