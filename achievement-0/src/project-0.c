#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

// Global seed for the random number generator
static int seed = 0;
static int turns = 1000;
static int players = 20;

////////////////////////////////////////////////////////////////
// Function for parsing the options of the program
// Currently available options are :
// -s <seed> : sets the seed
// -n <players> : the number of players 
// -m <turns> : the number of turns
void parse_opts(int argc, char* argv[]) {
  int opt;
  while ((opt = getopt(argc, argv, "s:n:m:")) != -1) {
    switch (opt) {
    case 's':
      seed = atoi(optarg);
      break;
    case 'm':
      turns = atoi(optarg);
      break;
    case 'n':
      players = atoi(optarg);
      break;
    case '?':
      if (optopt == 's' || optopt == 'n' || optopt == 'x')
	fprintf(stderr, "Option -%c needs argument\n", optopt);
      else
	fprintf(stderr, "Unknown option -%c. \n", optopt);
      break;
    default: 
      fprintf(stderr, "getopt\n");
      exit(EXIT_FAILURE);
    }
  }
}

////////////////////////////////////////////////////////////////
int main(int argc,  char* argv[]) {
  parse_opts(argc, argv);
  printf("Seed : %d\n", seed);
  printf("Turns : %d\n", turns);
  printf("Number of players : %d\n", players);

  if(seed == 0)
   srand(time(NULL));
  else 
    srand(seed);
  int time_spent;
  struct queue queue = init_queue();
  queue.count_teddy = players;
  const struct stockex* s = starting_stockex();
  int global_time = 0;
  while (global_time < turns){
    struct teddy active_teddy =  queuePop(&queue);
    global_time = active_teddy.time;
    size_t n = rand()%stockex__num_transactions(s); // the index of the desired transaction
    time_spent = active_teddy_play(n, s, &active_teddy);
    queuePush(&queue, &active_teddy, global_time, time_spent);
  }
  display_results(queue);
  return EXIT_SUCCESS;
}
