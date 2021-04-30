#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stockex.h"


// The type representing transactions
struct transac {
  int index_stockex;
  int index_accessible_stockex;
  struct wallet in_wallet; //
  struct wallet out_wallet; //
};

// The type representing stock exchanges

struct stockex {
  char name[MAX_STRING + 1];
  int count_transac;
  struct transac transaction[MAX_TRANSAC];
};

static const struct stockex tab_stockex[MAX_STOCKEX] = {
{ "Catane", 3, {
    {0, 1, .in_wallet = { .data = {10, 1, 0}} , .out_wallet = {.data = {0, 0, 1}} }, 
    {0, 3, .in_wallet = {.data = {0, 0, 1}}, .out_wallet = {.data = {20, 0, 0}} },
    {0, 2, .in_wallet = {.data = {0, 0, 2}}, .out_wallet = {.data = {30, 5, 0}} } 
}
},

{ "Palerme", 3, {
    {1, 3, .in_wallet = { .data = {0, 0, 1}} , .out_wallet = {.data = {50, 0, 0}} }, 
      {1, 0, .in_wallet = { .data = {50, 0, 0}}, .out_wallet = {.data = {0, 0, 1}} },
	{1, 2, .in_wallet = { .data = {5, 0, 1}}, .out_wallet = {.data = {0, 30, 0}} }
  }
},

{ "Syracuse", 2, {
    {2, 3, .in_wallet = { .data = {2, 0, 1}} , .out_wallet = {.data = {0, 10, 0}} }, 
      {2, 1, .in_wallet = { .data = {0, 0, 2}}, .out_wallet = {.data = {14, 8, 0}} }
}
},

{ "Etna", 3, {
    {3, 0, .in_wallet = { .data = {0, 0, 1}} , .out_wallet = {.data = {15, 2, 0}} }, 
      {3, 2, .in_wallet = { .data = {50, 0, 0}}, .out_wallet = {.data = {0, 15, 2}} },
	{3, 1, .in_wallet = { .data = {0, 0, 2}}, .out_wallet = {.data = {30, 0, 0}} } 
}
}

};


const struct stockex* starting_stockex()
{
  return &(tab_stockex[0]);
}

const char*           stockex__name(const struct stockex* s)
{
  return s->name;
}

size_t                stockex__num_transactions(const struct stockex* t)
{
  return t->count_transac;
}

const struct transac* stockex__transaction(const struct stockex* t, size_t num)
{
  return &(t->transaction[num]);
}

struct wallet         transac__in_wallet(const struct transac* s)
{
  struct wallet w = s->in_wallet;
  return w;
}

struct wallet         transac__out_wallet(const struct transac* s)
{
  struct wallet w = s->out_wallet;
  return w;
}

const struct stockex* transac__stockex(const struct transac* s)
{
  int i = s->index_stockex;
  return &(tab_stockex[i]);
}

const struct stockex* transac__next_stockex(const struct transac* s)
{
  int i = s->index_accessible_stockex;
  return &(tab_stockex[i]);
}
