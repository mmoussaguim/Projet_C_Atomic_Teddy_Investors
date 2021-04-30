#include <stdlib.h>
#include <stdio.h>
#include "good.h"


static const char *array[MAX_GOOD] = {"Honey", "Monkey wrench", "Outboard motor"
};

const char* good__string(enum good g)
{
  return array[g];
}

unsigned int good__value(enum good g)
{
  switch (g) {
  case 0:
    return 1;
  case 1:
    return 2;
  case 2:
    return 10;
  default :
    return 0;
  }
}
