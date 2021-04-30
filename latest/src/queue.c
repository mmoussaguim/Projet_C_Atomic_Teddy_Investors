#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "queue.h"


//the number of teddy who have the same priority as the one who plays
int count_same_priority(struct teddy ours[], int priority, int len)
{
  int count = 0;
  for(int i = 0; i < len ; i++){
    if (ours[i].priority == priority)
      count++;
  }
  return count;
}

//return the index where should be placed the teddy who is playing 
int index_of_teddy(struct teddy ours[], int priority, int len)
{
  int i = 0;
  int count = count_same_priority(ours, priority, len);
  while( i < len ){
    if ( (ours[i]).priority < priority )
      i++;
    else {
      return i + count;
    }
  }
  return i;
}

// create new empty queue
struct queue queue__new() 
{
  struct queue q = {.count_teddy = 0};
  return q ;
}


// push teddy `t` into queue `h` with priority `priority`
void queue__push(struct queue* h, int priority, struct teddy* t)
{
  t->priority += priority;
  int j = h->count_teddy;
  int i = index_of_teddy(h->ours, t->priority, j);
  while ( j > i ) {
    (h->ours)[j] = (h->ours)[j-1];
    j--;
  }

  (h->ours)[j] = *t;
  h->count_teddy++;
}


// return the priority teddy in the queue `h`
struct teddy* queue__top(struct queue* h)  
{
  return &(h->ours)[0];
}


// return and remove the priority teddy from the queue `h`
struct teddy* queue__pop(struct queue* h)
{
  int l = h->count_teddy;
  int i = 0;
  struct teddy p = (h->ours)[i];
  while( i < l-1 ){
    (h->ours)[i] = (h->ours)[i+1];
    i++;
  }
  h->ours[i] = p;
  h->count_teddy--;
  return &(h->ours[i]); 
}
////////////////////////////////////////////////////

struct queue init_queue()
{
  struct queue q = queue__new();
  struct teddy t1 = {.name = "Teddy1", .w = {.data = {1000, 200, 75}}, .priority = 0, .time = 0, 0, {NULL}, starting_stockex()};
  struct teddy t2 = {.name = "Teddy2", .w = {.data = {1000, 200, 75}}, .priority = 0, .time = 0, 0, {NULL}, starting_stockex()};
  struct teddy t3 = {.name = "Teddy3", .w = {.data = {1000, 200, 75}}, .priority = 0, .time = 0, 0, {NULL}, starting_stockex()};
  struct teddy t4 = {.name = "Teddy4", .w = {.data = {1000, 200, 75}}, .priority = 0, .time = 0, 0, {NULL}, starting_stockex()};
  struct teddy t5 = {.name = "Teddy5", .w = {.data = {1000, 200, 75}}, .priority = 0, .time = 0, 0, {NULL}, starting_stockex()};
  struct teddy t6 = {.name = "Teddy6", .w = {.data = {1000, 200, 75}}, .priority = 0, .time = 0, 0, {NULL}, starting_stockex()};
  struct teddy t7 = {.name = "Teddy7", .w = {.data = {1000, 200, 75}}, .priority = 0, .time = 0, 0, {NULL}, starting_stockex()};
  struct teddy t8 = {.name = "Teddy8", .w = {.data = {1000, 200, 75}}, .priority = 0, .time = 0, 0, {NULL}, starting_stockex()};
  struct teddy t9 = {.name = "Teddy9", .w = {.data = {1000, 200, 75}}, .priority = 0, .time = 0, 0, {NULL}, starting_stockex()};
  struct teddy t10 = {.name = "Teddy10", .w = {.data = {1000, 200, 75}}, .priority = 0, .time = 0, 0, {NULL}, starting_stockex()};
  struct teddy t11 = {.name = "Teddy11", .w = {.data = {1000, 200, 75}}, .priority = 0, .time = 0, 0, {NULL}, starting_stockex()};
  struct teddy t12 = {.name = "Teddy12", .w = {.data = {1000, 200, 75}}, .priority = 0, .time = 0, 0, {NULL}, starting_stockex()};
  struct teddy t13 = {.name = "Teddy13", .w = {.data = {1000, 200, 75}}, .priority = 0, .time = 0, 0, {NULL}, starting_stockex()};
  struct teddy t14 = {.name = "Teddy14", .w = {.data = {1000, 200, 75}}, .priority = 0, .time = 0, 0, {NULL}, starting_stockex()};
  struct teddy t15 = {.name = "Teddy15", .w = {.data = {1000, 200, 75}}, .priority = 0, .time = 0, 0, {NULL}, starting_stockex()};
  struct teddy t16 = {.name = "Teddy16", .w = {.data = {1000, 200, 75}}, .priority = 0, .time = 0, 0, {NULL}, starting_stockex()};
  struct teddy t17 = {.name = "Teddy17", .w = {.data = {1000, 200, 75}}, .priority = 0, .time = 0, 0, {NULL}, starting_stockex()};
  struct teddy t18 = {.name = "Teddy18", .w = {.data = {1000, 200, 75}}, .priority = 0, .time = 0, 0, {NULL}, starting_stockex()};
  struct teddy t19 = {.name = "Teddy19", .w = {.data = {1000, 200, 75}}, .priority = 0, .time = 0, 0, {NULL}, starting_stockex()};
  struct teddy t20 = {.name = "Teddy20", .w = {.data = {1000, 200, 75}}, .priority = 0, .time = 0, 0, {NULL}, starting_stockex()};
  q.ours[0] = t1;
  q.ours[1] = t2;
  q.ours[2] = t3;
  q.ours[3] = t4;
  q.ours[4] = t5;
  q.ours[5] = t6;
  q.ours[6] = t7;
  q.ours[7] = t8;
  q.ours[8] = t9;
  q.ours[9] = t10;
  q.ours[10] = t11;
  q.ours[11] = t12;
  q.ours[12] = t13;
  q.ours[13] = t14;
  q.ours[14] = t15;
  q.ours[15] = t16;
  q.ours[16] = t17;
  q.ours[17] = t18;
  q.ours[18] = t19;
  q.ours[19] = t20;
  q.count_teddy = 20;
  return q;
}

//return and remove the priority teddy
struct teddy queuePop(struct queue* h)
{
  struct teddy active_teddy = *(queue__pop(h));
  return active_teddy;
}

void queuePush(struct queue* q, struct teddy* t, int global_time, int time_spent)
{
  int l = q->count_teddy;
  for(int i = 0; i < l; i++)
    (q->ours[i]).time = global_time + time_spent;
    queue__push(q, time_spent, t);
}

//return the equivalent in honey reported by the transaction
int equivalent_honey(const struct transac *t)
{
  struct wallet w_s_i = transac__in_wallet(t);
  struct wallet w_s_o = transac__out_wallet(t);
  int equivalent = 0;
  for (int i = 0; i < MAX_GOOD; i++){
    int v = good__value(i);
    equivalent += v* w_s_o.data[i] - v*w_s_i.data[i];
    }
  return equivalent;
}

//The maximum number of transactions a teddy can make
int max_transaction(struct wallet w_t, struct wallet w_i)
{
  int N = 0;
  int bool = 1;
  while( bool != 0 ){
    N++;
    for(int i = 0; i < MAX_GOOD; i++){
      int j = w_t.data[i] - N*w_i.data[i];
      if ( j < 0 )
	bool = 0;
    }
  }
  return N-1;
}

//index of the desired transaction 
int index_transac(const struct stockex* s, struct teddy* t)
{
  if ( t->count_stockex_done < MAX_STOCKEX ){
    t->stockex_done[t->count_stockex_done] = s;
    t->count_stockex_done++;
  }
  int benefic_transac[MAX_TRANSAC];
  int count_tr = 0;
  int x = t->count_stockex_done;
  int count = stockex__num_transactions(s);
  for(int i = 0; i < count; i++){
    int z = 0;
    const struct transac* tr = stockex__transaction(s, i);
    const struct stockex* q = transac__next_stockex(tr);
    for(int j = 0; j < x; j++){
      if (t->stockex_done[j] == q)
	z = 1;
    }
    if ( z == 0 ){
       benefic_transac[count_tr++] = i;
    }
  }
  if (count_tr != 0){
    int nb = rand()%count_tr;
    int n = benefic_transac[nb];
    t->accessible_stockex = transac__next_stockex(stockex__transaction(s, n));
    return n;
  }
  else {
  int n = rand()%count;
  t->accessible_stockex = transac__next_stockex(stockex__transaction(s, n));
  return n;
  }
}

//index of the desired transaction for the strategist teddy
int strategy_index_transac(const struct stockex* s, struct teddy* t)
{
  if ( t->count_stockex_done < MAX_STOCKEX ){
    t->stockex_done[t->count_stockex_done] = s;
    t->count_stockex_done++;
  }
  int benefic_transac[MAX_TRANSAC];
  int count_tr = 0;
  int x = t->count_stockex_done;
  int count = stockex__num_transactions(s);
  int index = 0;
  int max = 0;
  for(int i = 0; i < count; i++){
    int z = 0;
    const struct transac* tr = stockex__transaction(s, i);
    const struct stockex* q = transac__next_stockex(tr);
    for(int j = 0; j < x; j++){
      if (t->stockex_done[j] == q)
	z = 1;
    }
    if ( z == 0 ){
      benefic_transac[count_tr++] = i;
    }
  }
  if(count_tr == 0){
    int z = rand()%t->count_stockex_done;
    t->accessible_stockex = t->stockex_done[z];
    for(int l = 0; l < count; l++){
      int equivalent = equivalent_honey(stockex__transaction(s, l));
      if(max < equivalent){
	max = equivalent;
	index = l;
      }
    }
    return index;
 }
  else {
    for(int k = 0; k < count_tr; k++){
      int y = benefic_transac[k];
      int equivalent = equivalent_honey(stockex__transaction(s, y));
      if(max < equivalent){
	max = equivalent;
	index = y;
      }
    }
    t->accessible_stockex = transac__next_stockex(stockex__transaction(s, index));
    return index;
  }
}


int choice_of_strategy(const struct stockex* s, struct teddy* t)
{
  if((strcmp(t->name, "Teddy1") == 0) | (strcmp(t->name, "Teddy2") == 0)){
    return strategy_index_transac(s, t);
  }
  else
    return index_transac(s, t);
}

//make play the teddy and return the time spent doing the exchange
 int active_teddy_play(size_t n, const struct stockex* s, struct teddy* t)
{ 
  const struct transac* tr = stockex__transaction(s, n);
  struct wallet w_s_i = transac__in_wallet(tr);
  struct wallet w_s_o = transac__out_wallet(tr);
  struct wallet w_t = t->w;
  for (int i = 0; i < MAX_GOOD; i++){
    if (w_t.data[i] < w_s_i.data[i]){
      return 1;
    }
    else {
      (t->w).data[i]-= w_s_i.data[i];
      (t->w).data[i]+= w_s_o.data[i];
    }
  }
return  1;
}



void display_results(struct queue q)
{
  printf("\nLes ours stratéges choisis sont Teddy1 et Teddy2\n");
  int l = q.count_teddy;
  unsigned int max_equivalent_honey = 0;
  for(int i = 0; i < l; i++){
    unsigned int equivalent_honey = 0;
    for (int j = 0; j < MAX_GOOD; j++){
      equivalent_honey += good__value(j)*((q.ours[i]).w).data[j];
  }
    if (max_equivalent_honey < equivalent_honey){
      max_equivalent_honey = equivalent_honey;
    }
  }
  printf("\n****Le resultat est le suivant****\n");
  printf("Le ou les teddy gagnants:\n");
  for (int x = 0; x < l; x++){
    unsigned int equivalent = 0;
    for(int y = 0; y < MAX_GOOD; y++){
      equivalent += good__value(y)*((q.ours[x]).w).data[y];
    }
    if ( equivalent == max_equivalent_honey ){
      printf("- %s, avec une valeur de réference en honey de %d \n", (q.ours[x]).name, max_equivalent_honey);
    }
  }
}

