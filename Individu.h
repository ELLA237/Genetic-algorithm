//This is the header file of individu 
#ifndef INDIVIDU_H
#define INDIVIDU_H

#define A 0.1
#define B 5
#define LONGINDIV 16
#define PCROISE 0.5

#include <stdlib.h>
#include <stdio.h>

typedef unsigned char Bit ; 

typedef struct BitList
{
    Bit bit ; 
    struct BitList *next ; 
} BitList ;

typedef BitList *Individu ; 

Individu ajout_tete(Bit bit1,Individu ind1);
Individu NewIndividuIter();
Individu NewIndividuRecur(Individu new1, int taille);
void PrintIndividu(Individu ind);
int Dec (Individu ind);
float Qualite(int val);
float QualiteF1(int val);
Individu CroiserInd (Individu ind1, Individu ind2);

#endif