//This is the population part of the code
#ifndef POPULATION_H
#define POPULATION_H

#include <stdlib.h>
#include <stdio.h>
#include "Individu.h"
#define NB_IND 50
#define T_SELECT 10

typedef struct ind
{   Individu id ;
    struct ind *next;
} ind;

typedef ind *Population ;

Population ajoutert(Individu ind,Population pop);
Population NewPopulation();
void PrintPopulation(Population pop);
ind* last_node(ind* head);
ind* DividePop(ind* first, ind* last);
void quick_sort(ind* first, ind* last);
Population meilleur (Population p);
Population CroiserPop (Population p);

#endif
