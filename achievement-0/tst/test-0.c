#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../src/queue.h"

int test_good()
{
  printf("\n******Test sur les fonctions de good.c******\n\n");
  for(int i = 0; i < AVAILABLE_GOODS; i++)
    printf("la Ressource %s a pour équivalent-honey %d\n", good__string(i), good__value(i));
  return 1;
}

int test_stockex()
{
  printf("\n******Test sur les fonctions de stockex.c******\n\n");
  const struct stockex* s = starting_stockex();
  size_t num = stockex__num_transactions(s);
  printf("La place d'échange %s offre %zu transactions\n", stockex__name(s), num);
  for(size_t i = 0; i < num; i++){
    const struct transac* t = stockex__transaction(s, i);
    printf("\n\nLa transaction d'indice %zu est caractérisée par :\n", i);
    printf("in_wallet:\n");
    for(int j = 0; j < AVAILABLE_GOODS; j++)
      printf("%s: %d\t", good__string(j), transac__in_wallet(t).data[j]);  
    printf("\nout_wallet:\n");
    for(int j = 0; j < AVAILABLE_GOODS; j++)
      printf("%s: %d\t", good__string(j), transac__out_wallet(t).data[j]);  
  }
  return 1;
}

int test_queue()
{
 printf("\n******Test sur les fonctions de queue.c******\n\n");
  printf("\n***UN TEST SUR 4 OURS***\n");
  struct queue queue = init_queue();
  for(int i = 0; i < 4; i++){
    struct teddy* active_teddy = queue__pop(&queue);
    printf("\nBonjour, Je suis %s, ", active_teddy->name);
    const struct stockex* s = starting_stockex();
    int nb = stockex__num_transactions(s);
    int n = rand()%nb;
    printf("je choisis la transaction numéro %d\n", n);
    const struct transac* t = stockex__transaction(s, n);
    struct wallet w_t = active_teddy->w;
    struct wallet w_i = transac__in_wallet(t);
    int max = max_transaction(w_t, w_i);
    printf("Je peux la faire %d fois (Mais il choisira de la faire aléatoirement dans active_teddy_play).\n", max);
    int time_spent = active_teddy_play(n, s, active_teddy);
    printf("J'ai passé %d unité de temps à faire cette transaction\n", time_spent);
    int New_prio = active_teddy->priority + time_spent;
    int count = count_same_priority(queue.ours, New_prio, queue.count_teddy);
    int index = index_of_teddy(queue.ours, New_prio, queue.count_teddy);
    printf("Votre nouvelle priorité est %d et %d ours ont la même priorité que vous; Veuillez s'il vous plaît vous mettre à l'indice %d dans la queue.\n", New_prio, count, index);
    queue__push(&queue, time_spent, active_teddy);
  }
  return 1;
}

int main()
{
  srand(time(NULL));
  if(test_good() != 0)
    printf("\n_____PASSED_TEST_____\n");
  if(test_stockex() != 0)
    printf("\n\n_____PASSED_TEST_____\n");
  if(test_queue() != 0)
    printf("\n_____PASSED_TEST_____\n");
 
}
