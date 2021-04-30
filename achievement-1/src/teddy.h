#ifndef __TEDDY_H
#define __TEDDY_H
#include "define.h"
#include "good.h" 

struct teddy {
  char name[MAX_TEDDY_NAME + 1];
  struct wallet w;
  int priority;
  int time ;              // time when a teddy is activated 
  int count_stockex_done;  
  const struct stockex* stockex_done[MAX_STOCKEX];
  const struct stockex* accessible_stockex;  //the next stockex he'll visit
};

#endif
