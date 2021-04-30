#ifndef __QUEUE_H
#define __QUEUE_H
#include "stockex.h"
#include "teddy.h"


struct queue {
  int count_teddy;
  struct teddy ours[MAX_TEDDY];
};


//the number of teddy who have the same priority as the one who plays
int count_same_priority(struct teddy ours[], int priority, int len);

//return the index where should be placed the teddy who is playing 
int index_of_teddy(struct teddy ours[], int priority, int len);

// create new empty queue
struct queue queue__new();

// push teddy `t` into queue `h` with priority `priority`
void queue__push(struct queue* h, int priority, struct teddy* t);

//  return the priority teddy in the queue `h`
struct teddy* queue__top(struct queue* h);

// return and remove the priority teddy from the queue `h`
struct teddy* queue__pop(struct queue* h);

//initialization of the queue
struct queue init_queue();

//index of the desired transaction
int index_transac(const struct stockex* s, struct teddy* t);

//return and remove the priority teddy
struct teddy queuePop(struct queue* h);

//push teddy t with "priority = time_spent" when "time = global_time"
void queuePush(struct queue* q, struct teddy* t, int global_time, int time_spent);

//make play the teddy and return the time spent doing the exchange
int active_teddy_play(size_t n, const struct stockex* s, struct teddy* t);

//The maximum number of transactions a teddy can make
int max_transaction(struct wallet w_t, struct wallet w_i);

void display_results(struct queue q);

#endif
