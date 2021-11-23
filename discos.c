#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "portada.h"
#include "basedatos.h"


int main() {
  	
  char sel[256];
  char cad[256];
  int sal=0;
  int x;
  int y;
  plano('-', 73);
  lados('|', 73);
  rotulo("DISCOTECA", '|', 73);
  lados('|', 73);
  plano('-', 73);
  int num;
  num=0;
  struct unDisco losDiscos[100];
  
  iniciar(losDiscos, &num);
        
        
  do{
    
    do{
    	
      
      do{
      	fprintf(stdout, "\nA) Agregar un disco nuevo\n");
    fprintf(stdout, "V) Ver datos de un disco\n");
    fprintf(stdout, "T) Ver los datos de todos los discos\n");
    fprintf(stdout, "L) Sacar un listado\n");
    fprintf(stdout, "E) Eliminar un disco\n");
    fprintf(stdout, "M) Modificar un disco existente\n");
    fprintf(stdout, "\nS) Salir del programa\n");
    printf("\nElige una opcion: ");
      fgets(cad, sizeof(cad),stdin);
      if(cad[0]==' '|| cad[1]==' ') printf ("\nHas elegido una opcion invalida\n");
  	}while(cad[0]==' '|| cad[1]==' ');
	  x=sscanf(cad, "%s%s", sel, cad);
      y=strlen(sel);
      if (x!=1 || y>1) printf ("\nHas elegido una opcion invalida\n");
    }while(x!=1 || y>1);
  
  switch(toupper(sel[0])){
    case 'A':
     agregar(losDiscos, &num);
     break;
    case 'V':
     ver(losDiscos, num);
     break;
    case 'L':
     listar(losDiscos, num);
     break;
    case 'T':
     todos(losDiscos, num);
     break;
    case 'E':
     eliminar(losDiscos, &num);
     break;
    case 'M':
     modificar(losDiscos, num);
     break;
    case 'S':
     salir("Seguro que desea salir del programa? (s/n): ", &sal, losDiscos, num);
     break;
    default:
     fprintf(stdout, "\nHas elegido una opcion invalida\n");
     break;
  }
  }while (sal==0);
  
  
  return 0;
}
