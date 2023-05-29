#include "Population.h"
#include <stdlib.h>

//This function adds a new Individu to the head of Population.
Population ajoutert(Individu ind,Population pop)
{

    Population temp ;
    temp=malloc(sizeof(Population));
    temp->id=ind;
    temp->next=pop ;
    return temp ;

}

// This function creates a new Population by creating NB_IND new Individu and adding them to the list.
Population NewPopulation()
{
    Population new1=NULL ;

    for (int i=0;i<NB_IND;i++)
    {
        new1=ajoutert(NewIndividuIter(),new1);
    }
    return new1 ;
}


//This function returns a pointer to the last ind element in the Population. 
//return the last element
ind* last_node(ind* head)
{
    ind* temp = head;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

//This function divides the Population into two sub-populations at a given point in the list.
ind* DividePop(ind* first, ind* last)
{

    ind* pivot = first; // this one will be the benchmark and at starting, we'll put it in the head
    ind* current = first; // pointer for current element that we're checking

    Individu temp ;

    while (current != NULL && current != last) { ///Parcourir all the elements

        if (Qualite(Dec(current->id))> Qualite(Dec(last->id))) {//if element is bigger than the last element, we need to swap
            pivot = first;

            //swap the current and first value
            temp= first->id;
            first->id = current->id;
            current->id = temp;

            // increment the first
            first = first->next;
        }

        // increment the current
        current = current->next;
    }

    // Change last node value to current node
    temp = first->id;
    first->id = last->id;
    last->id= temp;

    //return pivot
    return pivot;
}


//This function sorts the elements of a Population object using the quick sort algorithm.
void quick_sort(ind* first, ind* last)
{
    //if only one element, then keep as it is
    if (first == last) {
        return;
    }

    //to divide the list
    ind* pivot = DividePop(first, last);


    //if there is still something after the pivot
    if (pivot != NULL && pivot->next != NULL) {
        quick_sort(pivot->next, last);
    }

    //if there is still something before the pivot
    if (pivot != NULL && first != pivot) {
        quick_sort(first, pivot);
    }
}

//This function returns the T_SELECT best Individu in a Population based on their quality.
Population meilleur (Population p)
{
    ind* head=p ;
    ind* chosen=p ;
    ind* stop=p ;

    for (int i=0;i<T_SELECT;i++)
    {
        head=head->next ;
        stop=stop->next ;
    }

    while (head!=NULL)
    {
        head->id=chosen->id;
        head=head->next ;

        if (chosen->next!=stop)
        {
            chosen=chosen->next ;
        }

        else chosen=p ;
    }

    return p ;
}


//This function performs crossover on Individu in a Population to create a new Population.
Population CroiserPop (Population p)
{

    Population PopCroise=NULL ;

    for (int i=0;i<NB_IND;i++)
    {
    int random1 = rand()%(NB_IND-1)+1 ;
    int random2 = rand()%(NB_IND-1)+1 ;

    ind* pointer1=p ;
    ind* pointer2=p ;


    for (int j=1;j<random1;j++)
    {
        pointer1=pointer1->next ;
    }

    for (int k=1;k<random2;k++)
    {
        pointer2=pointer2->next ;
    }

    PopCroise=ajoutert(CroiserInd(pointer1->id,pointer2->id),PopCroise);
    }

    return PopCroise ;






}

//This function prints the values of a Population to the console by iterating through its list of ind and 
//printing the values of the Individu they contain. 
void PrintPopulation(Population pop)
{

    int i =1 ;
    while (pop!=NULL)
    {
        printf ("%d ",i++);
        PrintIndividu(pop->id);
        pop=pop->next ;

    }

}

