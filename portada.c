#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "portada.h"

void lados(char car, int N){
  int i;
  printf("%c", car);
  for (i=0; i<(N-2); i++) printf(" ");
  printf("%c\n", car);
  return;
}



void plano(char car, int N){
  int i;
  for (i=0; i<N; i++) printf("%c", car);
  printf("\n");
  return;
}


int confirmar(char frase[]){
  char op[256];
  char cad[256];
  int x, y;
  int res=-1;
  do{
  do{
  	do{
  	printf("\n%s", frase);
  	fgets(cad, sizeof(cad),stdin);
    
  	}while(cad[0]==' '|| cad[1]==' ');
	  x=sscanf(cad, "%s%s", op, cad);
      y=strlen(op);
      
    }while(x!=1 || y>1);
    if(toupper(op[0])=='S') res=1;
    else if(toupper(op[0])=='N') res=0;
  }while (res==-1);
  fflush (stdin);
  return res;
}


void rotulo(char NOMBRE[], char car, int N){
  int NB, i;
  NB=((N-2)-strlen(NOMBRE))/2;
  printf("%c", car);
  for (i=0; i<NB; i++) printf(" ");
  printf ("%s", NOMBRE);
  for (i=0; i<NB; i++) printf(" ");
  printf("%c\n", car);
  return;
}
