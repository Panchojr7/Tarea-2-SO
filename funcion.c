#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "sthread.h"

typedef struct operacion{
  int *numbers;
  char *operadores;
}Op;

void append(char* s, char c){
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

int *getNums(char op[]){
  printf("A usar: %s\t",op);
  int nums[200],i,k,len,count=0;
  len = strlen(op);
  //printf("len: %d\n",len);
  //nums = (int*)calloc(len,sizeof(int));
  nums[0] = 0;
  char j;
  char aConcat[500] = "0";

  for(i=0;i<len;i++){
    j = op[i];
    //printf("j= %c\n",j);
    if(j>='0' && j<='9'){
      append(aConcat,j);
      continue;
    }
    else if(strcmp(aConcat,"0")!=0){
    for(k=0;k<strlen(aConcat);k++){
      nums[count] = nums[count]*10 + (aConcat[k] - '0');
    }
    //printf("numerillo %d, count %d\n", nums[count], count);
    count += 1;
    strcpy(aConcat,"0");
  }
}
  //nums = (int *)realloc(nums,sizeof(int)*count);
  int *retorno = (int *)malloc(sizeof(int)*count);
  for(i=0;i<count;i++){
    retorno[i] = nums[i];
  }
  //largo = sizeof(retorno)/sizeof(retorno[0]);
  //printf("largo array: %d\n",largo);
  return retorno;
}

char *getOps(char array[]){
  char ops[100]="\0",j,aux[10]="\0";
  int i,len=strlen(array);

  for(i=5;i<len;i++){
    j=array[i];
    append(aux,j);
    //printf("%s\n", aux);

    if(strcmp(aux,"+")==0 || strcmp(aux,"-")==0){
      //printf("%s\n",aux);
      strcat(ops,aux);
      //printf("%s\n",ops);
    }
    else if(strcmp(aux,"a")>=0 && strcmp(aux,"z")<=0){
      //printf("%s\n",aux);
      if(array[i+1]=='(') strcat(ops,aux);
    }
    strcpy(aux,"\0");
  }
  char *retorno = (char *)malloc(sizeof(char)*strlen(ops));
  retorno = ops;
  return retorno;
}

void calculate(struct operacion *estruct){
  int *numeros = estruct->numbers;
  char *opers = estruct->operadores;
  int i,n = sizeof(numeros)/sizeof(numeros[0]);
  //printf("%d\n",n);
  for(i=0;i<n;i++){
    
  }
}

int main(){
  char buffer[200][200];
  int n,*numeros;
  struct operacion *operations = (Op *)malloc(sizeof(Op));
  FILE *fp= fopen("funciones.txt", "r");

  if(fp == NULL){
    printf("ERROR OPENING FILE\n");
    exit(1);
  }
  else printf("Funciones ingresadas!\n");

  printf("------------------------------------------\n");
  fgets(&buffer[0][0], sizeof(buffer), fp);
  n = (int)buffer[0][0] - '0';
  printf("Funciones: %d\n", n);

  for(int i=0;i<n;i++){
  fgets(buffer[i+1], sizeof(buffer), fp);
  printf("Funcion %d: %s", i+1, buffer[i+1]);
}
//printf("A usar: %s", buffer[2]);

  numeros = getNums(buffer[1]);
  printf("numeros[0]: %d\n", numeros[0]);
printf("------------------------------------------\n");
  char *O = getOps(buffer[1]);
  operations->numbers = numeros;
  operations->operadores = O;
  printf("OPS: %s\n",operations->operadores);
  calculate(operations);
  fclose(fp);
  return 0;
}
