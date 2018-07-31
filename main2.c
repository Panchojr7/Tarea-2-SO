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

void imprimir(int arreglo[], int largo){
    int i;
    for(i=0;i<largo;i++)
            printf(" %d", arreglo[i]);
        printf("\n" RESET);
}

void quicksort(Arreglo * arry){
    int i, j, pivot, temp, k, caux;

    if(arry->first < arry->last){
        pivot=arry->first;
        i=arry->first;
        j=arry->last;
        k=j+1;

        while(i<j){
            while(arry->number[i] <= arry->number[pivot] && i < arry->last)
                i++;
            while(arry->number[j] > arry->number[pivot])
                j--;
            if(i<j){
                temp = arry->number[i];
                arry->number[i] = arry->number[j];
                arry->number[j] = temp;
            }
        }

        temp = arry->number[pivot];
        arry->number[pivot] = arry->number[j];
        arry->number[j] = temp;

        printf("el pivote es %d\n", temp);

        Arreglo * temp1 = (Arreglo *)malloc(sizeof(Arreglo));
        Arreglo * temp2 = (Arreglo *)malloc(sizeof(Arreglo));

        temp1->first = arry->first;
        temp1->last = j-1;

        temp2->first = j+1;
        temp2->last = arry->last;

        for(caux=0;caux<k;caux++){
            temp1->number[caux]= arry->number[caux];
            temp2->number[caux]= arry->number[caux];
        }

        sthread_t hilo1, hilo2;
        sthread_create(&hilo1, (void*)&quicksort, (void*)temp1);
        sthread_create(&hilo2, (void*)&quicksort, (void*)temp2);

        sthread_join(hilo1);
        sthread_join(hilo2);
    }
        printf("weakla\n");
        imprimir(arry->number, k+1);

}

int main(){
    int n, count;
    int numbr[25];
    Arreglo * arry = (Arreglo *)malloc(sizeof(Arreglo));
    
    arry->first = 0;

    printf(YELLOW "How many elements are u going to enter?: " RESET);
    scanf("%d",&count);

    arry->last = count-1;

    printf(GREEN "Enter %d elements: " BLUE, count);
    for(n=0;n<count;n++){
        scanf("%d",&numbr[n]);
        arry->number[n]= numbr[n];
    }

    sthread_t hilo;
    sthread_create(&hilo, (void*)&quicksort, (void*)arry);
    sthread_join(hilo);

    printf(GREEN "Order of Sorted elements: " CYAN);
    imprimir(arry->number, count);

    return 0;
}

