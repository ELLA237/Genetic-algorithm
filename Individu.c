#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include "Individu.h"

//This function adds a new Bit value to the head of Individu list
Individu ajout_tete(Bit bit1,Individu ind1)
{

    Individu temp ;
    temp=malloc(sizeof(Individu));
    temp->bit=bit1 ;
    temp->next=ind1 ;
    return temp ;

}

//This function creates a new individual by iteratively adding bits to the linked list new with the function ajout_tete.
Individu NewIndividuIter ()
{
   Individu new1=NULL ;

    for (int i=0;i<LONGINDIV;i++)
    {
        new1=ajout_tete(rand()%2,new1);
    }
    return new1 ;


}

//This function creates a new individual by recursively adding bits to the ind linked list.
Individu NewIndividuRecur (Individu ind,int taille)
{
    ind=ajout_tete(rand()%2,ind);

    if (taille!=1) return NewIndividuRecur(ind,taille-1);
    return ind ;

}

//This function decodes the value of an individual by traversing its linked list of bits and converting them to an integer.
int Dec (Individu ind)
{
    int  res = 0;
    while (ind != NULL)
    {
        res = (res  *2) + ind->bit;
        ind = ind->next;
    }
    return res;
}


//This function returns a float value representing the quality of an individual based on its value.

float Qualite(int val)
{
  float x=(val/pow(2,8))*(B-A)+A ;
  return -log(x); 

}


float QualiteF1(int val)
{
    float x=(val/pow(2,8))*(B-A)+A ;
    return -(pow(x,2));
}


//This function produces a new individual by performing crossover on two individuals.
Individu CroiserInd (Individu ind1,Individu ind2)
{
    int prob = 1+rand()%99;

    if (ind1==NULL && ind2==NULL) return NULL ;

    if (prob<PCROISE*100)
    {
        return ajout_tete(ind1->bit,CroiserInd(ind1->next,ind2->next));
    }

    else
    {
        return ajout_tete(ind2->bit,CroiserInd(ind1->next,ind2->next));
    }
}

//This function prints the bits of an individual. 
void PrintIndividu(Individu ind)
{
    BitList* temp=ind ;
    while (temp!=NULL)
    {
        printf("%d",temp->bit);
        if(temp->next==NULL)
        {
            printf ("      ");
            printf ("Qualite : %f",Qualite(Dec(ind)));
            printf ("\n");
        }


        temp=temp->next;
    }
}