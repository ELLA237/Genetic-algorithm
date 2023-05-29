#include "Individu.h"
#include "Population.h"
#include <stdio.h>
#include <stdlib.h>
#define NGEN 2

//The main function of our program
int main()
{
    Population new1=NULL ;
    new1=NewPopulation();

  for (int i=0;i<NGEN;i++)
  {
      new1=CroiserPop(new1);
      quick_sort(new1,last_node(new1));
      new1=meilleur(new1);

  }

  printf ("Le meilleur Individu de population est : \n");
  PrintIndividu(new1->id);


}