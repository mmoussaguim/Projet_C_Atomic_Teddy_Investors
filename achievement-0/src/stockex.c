#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stockex.h"

// The type representing transactions
struct transac {
  struct wallet in_wallet; 
  struct wallet out_wallet; 
};

// The type representing stock exchanges

struct stockex {
  char name[MAX_STRING + 1];
  int count_transac;        //the number of available transactions
  struct transac transaction[MAX_TRANSAC];
};


static const struct stockex tab_stockex[MAX_STOCKEX] = {
  { "Catane", 2, {
      {.in_wallet = { .data = {10, 1, 0}} , .out_wallet = {.data = {0, 0, 1}} }, 
      {.in_wallet = {.data = {0, 0, 1}}, .out_wallet = {.data = {20, 0, 0}} } }
}
  };

// The starting stock exchange
const struct stockex* starting_stockex()
{
  return &(tab_stockex[0]);
}

// The name of the stock exchange
const char*           stockex__name(const struct stockex* s)
{
  return s->name;
}

// the number of available transactions
size_t                stockex__num_transactions(const struct stockex* t)
{
  return t->count_transac;
}

//return the transaction number 'num'
const struct transac* stockex__transaction(const struct stockex* t, size_t num)
{
  return &(t->transaction[num]);
}

// The goods bought by the stock exchange
struct wallet         transac__in_wallet(const struct transac* s)
{
  struct wallet w = s->in_wallet;
  return w;
}

// The goods sold by the stock exchange
struct wallet         transac__out_wallet(const struct transac* s)
{
  struct wallet w = s->out_wallet;
  return w;
}
