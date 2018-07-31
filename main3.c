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
    int * number;
    int first;
    int last;
}Arreglo;

void imprimir(int arreglo[], int largo){
    int i;
    for(i=0;i<largo;i++)
            printf(" %d", arreglo[i]);
        printf("\n" RESET);
}

void quicksort(Arreglo * arry){
    int i, j, pivot, temp;

    if(arry->first < arry->last){
        int *numeros = arry->number;
        pivot=arry->first;
        i=arry->first;
        j=arry->last;

        while(i<j){
            while(numeros[i] <= numeros[pivot] && i < arry->last)
                i++;
            while(numeros[j] > numeros[pivot])
                j--;
            if(i<j){
                temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }

        temp = numeros[pivot];
        numeros[pivot] = numeros[j];
        numeros[j] = temp;

        Arreglo temp1 = {numeros, arry->first, j-1};
        Arreglo temp2 = {numeros, j+1, arry->last};


        sthread_t hilo1, hilo2;
        sthread_create(&hilo1, (void*)&quicksort, (void*)&temp1);
        sthread_create(&hilo2, (void*)&quicksort, (void*)&temp2);

        sthread_join(hilo1);
        sthread_join(hilo2);

    }


}

int main(){
    int n, count; 

    printf(YELLOW "How many elements are u going to enter?: " RESET);
    scanf("%d",&count);

    int numbr[count];

    printf(GREEN "Enter %d elements: " BLUE, count);
    for(n=0;n<count;n++){
        scanf("%d",&numbr[n]);
    }

    Arreglo arry = {numbr,0,count-1};

    sthread_t hilo;
    sthread_create(&hilo, (void*)&quicksort, (void*)&arry);
    sthread_join(hilo);

    printf(GREEN "Order of Sorted elements: " CYAN);
    imprimir(numbr, count);

    return 0;
}

