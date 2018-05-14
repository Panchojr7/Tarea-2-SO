#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sthread.h"

#define RED      "\x1b[31m"
#define GREEN    "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE     "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN     "\x1b[36m"
#define RESET    "\x1b[0m"

typedef struct aka{
    int first;
    int last;
    int number[25];
}Arreglo;

void quicksort(void * ar){
    Arreglo * arri = (Arreglo *) ar;
    int i, j, pivot, temp;

    if(arri->first < arri->last){
        pivot=arri->first;
        i=arri->first;
        j=arri->last;

        while(i<j){
            while(arri->number[i] <= arri->number[pivot] && i < arri->last)
                i++;
            while(arri->number[j] > arri->number[pivot])
                j--;
            if(i<j){
                temp = arri->number[i];
                arri->number[i] = arri->number[j];
                arri->number[j] = temp;
            }
        }

        temp = arri->number[pivot];
        arri->number[pivot] = arri->number[j];
        arri->number[j] = temp;

        Arreglo * temp1 = (Arreglo *)malloc(sizeof(Arreglo));
        Arreglo * temp2 = (Arreglo *)malloc(sizeof(Arreglo));
        temp1 = arri;
        temp2 = arri;
        temp1->last = j-1;
        temp2->first = j+1;
        quicksort((void *) temp1);
        quicksort((void *) temp2);
        //free((void *) temp1);
        //free((void *) temp2);
    }
}

int main(){
    int i, count, numbr[25];
    Arreglo * arry = (Arreglo *)malloc(sizeof(Arreglo));
    arry->last = count-1;
    arry->first = 0;
    //sthread_t mainthread;

    printf(YELLOW "How many elements are u going to enter?: " RESET);
    scanf("%d",&count);

    printf(GREEN "Enter %d elements: " BLUE, count);
    for(i=0;i<count;i++){
        scanf("%d",&numbr[i]);
        arry->number[i]= numbr[i];
    }

    

    quicksort((void *) arry);

    printf(GREEN "Order of Sorted elements: " CYAN);
    for(i=0;i<count;i++)
        printf(" %d",number[i]);
    printf("\n" RESET);

    return 0;
}

