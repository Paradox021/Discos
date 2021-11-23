#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include "basedatos.h"
#include "portada.h"

int iniciar(struct unDisco *tabla,int *numero)
 {
	*numero = 0;
	char cad[80];
	FILE *fichero;
	fichero=fopen("records.txt","r");
	if (fichero !=NULL){
		while((fgets(cad,sizeof(cad),fichero))!=NULL) {		
			sscanf(cad,"%s %s %i %s %f",tabla[*numero].titulo,tabla[*numero].artista,&tabla[*numero].fecha,tabla[*numero].formato,&tabla[*numero].precio);
			
			*numero=(*numero)+1;
		

		}
		fclose(fichero);}
	else{fichero=fopen("records.txt","w");fclose(fichero);}

	return 0;
}
int finalizar(struct unDisco *tabla,int numero)
{
	int cont;	
	FILE *fichero;
	fichero=fopen("records.txt","w");
	for(cont=0;cont<numero;cont++)
	{fprintf(fichero,"%s %s %i %s %.2f\n",tabla[cont].titulo,tabla[cont].artista,tabla[cont].fecha,tabla[cont].formato,tabla[cont].precio);}
	fclose(fichero);
	return 0;
		

}

int validanumint(char numero[]){
	int i=1, j, v=0;
	j=strlen(numero);
	
		if(isdigit(numero[0])!=0)
		{
		  while(i<j && v==0)
	{
			if(isdigit(numero[i])!=0)
			{
				i++;
		
			}
			else
			{
				v=1;
			}
		}
		}
		else
		{
			v=1;
		}
	
	return v;
}

int validanum(char numero[]){
	int i=1, j, v=0, c=0;
	j=strlen(numero);
	
		if(isdigit(numero[0])!=0)
		{
		  while(i<j && v==0)
	{
			if(isdigit(numero[i])!=0||(numero[i]=='.'&&c<=1))
			{
				i++;
				if(numero[i]=='.')	c++;
			}
			else
			{
				v=1;
			}
		}
		}
		else
		{
			v=1;
		}
	
	return v;
}


int agregar(struct unDisco *tabla, int *numero){			//funcion agreagar
    int fecha, v;
    char cad[256];
    char cad2[256];
    int x;

    do{
    	strcpy(tabla[*numero].titulo, "");
    	fprintf(stdout, "\nDame el titulo del disco: ");
    	fgets(cad, sizeof(cad),stdin);
    	
    	if(strlen(cad)<34){
    	x=sscanf(cad, "%s%s", tabla[*numero].titulo, cad);
    	if(x==-1)printf("\nLongitud nula\n");
    	if(x==2)printf("\nCaracteres ilegales\n");
    	
    }
		else{
		 printf("\nLongitud excesiva\n");
    }
	}while (x!=1 || strlen(cad)>33);
	
    
    do{
    	strcpy(tabla[*numero].artista, "");
    	fprintf(stdout, "\nDame el nombre del artista: ");
    	fgets(cad, sizeof(cad),stdin);
    	
    	if(strlen(cad)<27){
    	x=sscanf(cad, "%s%s", tabla[*numero].artista, cad);
    	if(x==-1)printf("\nLongitud nula\n");
    	if(x==2)printf("\nCaracteres ilegales\n");
    	
    }
		else{
		 printf("\nLongitud excesiva\n");
    }
	}while (x!=1 || strlen(cad)>26);
    
    
    do{
    fprintf(stdout, "\nDame la fecha: ");
    fgets(cad, sizeof(cad),stdin);
    x=sscanf(cad, "%s%s", cad2, cad);
    fecha= validanumint(cad2);
    tabla[*numero].fecha = atoi (cad2);
    if (tabla[*numero].fecha<1900 || tabla[*numero].fecha>2018||x!=1||fecha==1){
      printf("\nValor dado incorrecto. Debe estar en [1900, 2018]\n");
    }
    }while(tabla[*numero].fecha<1900 || tabla[*numero].fecha>2018|| x!=1||fecha==1);
    
    fprintf(stdout, "\nDame el formato: ");
    fgets(cad, sizeof(cad),stdin);
    x=sscanf(cad, "%s%s", tabla[*numero].formato, cad);

    while((strcmp(tabla[*numero].formato, "LP")!=0 && strcmp(tabla[*numero].formato, "CD")!=0 && strcmp(tabla[*numero].formato, "DD")!=0 && strcmp(tabla[*numero].formato, "MC")!=0)|| x!=1)
	{
		printf("\nFormato no aceptado (LP, CD, DD o MC)\n");
		fprintf(stdout, "\nDame el formato: ");
		fgets(cad, sizeof(cad),stdin);
    x=sscanf(cad, "%s%s", tabla[*numero].formato, cad);
	}

	do{
    fprintf(stdout, "\nDame el precio: ");
    fflush(stdin);
    fgets(cad, sizeof(cad),stdin);
    x=sscanf(cad, "%s%s", cad2, cad);
    v=validanum(cad2);
    
    if(v==1)printf("\nValor dado incorrecto. Debe estar en [0.00, 250.00]\n");
    else{
    	tabla[*numero].precio= atof(cad2);
    	if (tabla[*numero].precio<0 || tabla[*numero].precio>250|| x!=1){
      printf("\nValor dado incorrecto. Debe estar en [0.00, 250.00]\n");
	}    
    }
    }while(tabla[*numero].precio<0 || tabla[*numero].precio>250|| v==1 || x!=1);
    printf("\nAgregado disco:");
		printf("\n>Titulo: %s\n", tabla[*numero].titulo);
		printf(">Artista: %s\n", tabla[*numero].artista);
		printf(">Fecha: %d\n", tabla[*numero].fecha);
		printf(">Formato: %s\n", tabla[*numero].formato);
		printf(">Precio: %.2f\n", tabla[*numero].precio);
    printf("\n");
    (*numero)++;
    
  return 0;
}


void listar(struct unDisco *tabla, int numero){						//funcion listar
 int i, x, y, v;
char cad[256];
char cad2[256];
char sel[256];
char buscar[26];
int blancart=25;
     int blancti=32;
     int error=0;
     int numbt, numba, j, fecha;
do{
do{
	do{
    fprintf(stdout, "\nG) general\n");
    fprintf(stdout, "A) por artista\n");
    fprintf(stdout, "F) por formato\n");
    fprintf(stdout, "Y) por fecha\n");
    
    printf("\nElige una opcion: ");
      fgets(cad, sizeof(cad),stdin);
      if(cad[0]==' '|| cad[1]==' ') printf ("\nHas elegido una opcion invalida\n");
  	}while(cad[0]==' '|| cad[1]==' ');
	  x=sscanf(cad, "%s%s", sel, cad);
     	  y=strlen(sel);
      if (x!=1 || y>1) printf ("\nHas elegido una opcion invalida\n");
    }while(x!=1 || y>1);

switch(toupper(sel[0])){
    case 'G':
     
     printf("\nListado general de discos:\n");  
     for (i=0; i<numero; i++)
     {
	numbt=blancti-strlen(tabla[i].titulo);
	for (j=0; j<numbt; j++)
	{
		printf(" ");
	}
	printf ("%s ", tabla[i].titulo);
	numba=blancart-strlen(tabla[i].artista);
	for (j=0; j<numba; j++)
	{
		printf(" ");
	}
	printf("%s ", tabla[i].artista);
	printf("%d ", tabla[i].fecha);
	printf("%s ", tabla[i].formato);
	printf("%6.2f\n", tabla[i].precio);
     }
     error=0;
     break;
    case 'A':
      do{
    	strcpy(buscar, "");
    	fprintf(stdout, "\nDame el nombre del artista: ");
    	fgets(cad, sizeof(cad),stdin);
    	if(strlen(cad)>26)printf("\nLongitud excesiva\n");
    	else{
    	x=sscanf(cad, "%s%s", buscar, cad);
    	if(x==-1)printf("\nLongitud nula\n");
    	if(x==2)printf("\nCaracteres ilegales\n");
    	
	}
		   	
	}while (x!=1 || strlen(cad)>26);
    printf("\nListado de discos del artista %s:\n", buscar);
	
	for(i=0; i<numero; i++){
		
		if(strcmp(tabla[i].artista, buscar)==0){
		numbt=blancti-strlen(tabla[i].titulo);
	for (j=0; j<numbt; j++)
	{
		printf(" ");
	}
	printf ("%s ", tabla[i].titulo);
	numba=blancart-strlen(tabla[i].artista);
	for (j=0; j<numba; j++)
	{
		printf(" ");
	}
	printf("%s ", tabla[i].artista);
	printf("%d ", tabla[i].fecha);
	printf("%s ", tabla[i].formato);
	printf("%6.2f\n", tabla[i].precio);
		
		
		}
	}

	error=0;
     break;
    case 'F':
     fprintf(stdout, "\nDame el formato: ");
    fgets(cad, sizeof(cad),stdin);
    x=sscanf(cad, "%s%s", cad2, cad);

while((strcmp(cad2, "LP")!=0 && strcmp(cad2, "CD")!=0 && strcmp(cad2, "DD")!=0 && strcmp(cad2, "MC")!=0)||x!=1)
	{
	printf("\nFormato no aceptado (LP, CD, DD o MC)\n");
	fprintf(stdout, "\nDame el formato: ");
	fgets(cad, sizeof(cad),stdin);
  	x=sscanf(cad, "%s%s", cad2, cad);
   	}
   	printf("\nListado de discos con formato %s:\n", cad2);
    for(i=0; i<numero; i++){
		
		if(strcmp(tabla[i].formato, cad2)==0){
		numbt=blancti-strlen(tabla[i].titulo);
	for (j=0; j<numbt; j++)
	{
		printf(" ");
	}
	printf ("%s ", tabla[i].titulo);
	numba=blancart-strlen(tabla[i].artista);
	for (j=0; j<numba; j++)
	{
		printf(" ");
	}
	printf("%s ", tabla[i].artista);
	printf("%d ", tabla[i].fecha);
	printf("%s ", tabla[i].formato);
	printf("%6.2f\n", tabla[i].precio);
		
		
		}
	} 
     
    error=0; 
     break;
    case 'Y':
     
	 do{
    fprintf(stdout, "\nDame la fecha: ");
    fgets(cad, sizeof(cad),stdin);
    x=sscanf(cad, "%s%s", cad2, cad);
    v= validanumint(cad2);
    fecha = atoi (cad2);
    if (fecha<1900 || fecha>2018||x!=1||v==1){
      printf("\nValor dado incorrecto. Debe estar en [1900, 2018]\n");
    }
    }while(fecha<1900 || fecha>2018|| x!=1||v==1);

	printf("\nListado de discos de la fecha %d:\n", fecha);

	for(i=0; i<numero; i++){
		
		if(tabla[i].fecha==fecha){
		numbt=blancti-strlen(tabla[i].titulo);
	for (j=0; j<numbt; j++)
	{
		printf(" ");
	}
	printf ("%s ", tabla[i].titulo);
	numba=blancart-strlen(tabla[i].artista);
	for (j=0; j<numba; j++)
	{
		printf(" ");
	}
	printf("%s ", tabla[i].artista);
	printf("%d ", tabla[i].fecha);
	printf("%s ", tabla[i].formato);
	printf("%6.2f\n", tabla[i].precio);
		
		
		}
	}
	error=0;
     break;
    default:
     fprintf(stdout, "\nHas elegido una opcion invalida\n");
     error=2;
	 break;
  }
  }while(error==2);
	printf("\n");
}


int ver(struct unDisco *tabla, int numero){								//funcion ver
	int x, i, k;
	char cad[256];
	char buscar[26];
	char buscat[33];
	bool ver, vert;
	if (numero==0)printf("\nNo existen discos");
  	else
 	{
	do{
    	strcpy(buscar, "");
    	fprintf(stdout, "\nDame el nombre del artista: ");
    	fgets(cad, sizeof(cad),stdin);
    	if(strlen(cad)>26)printf("\nLongitud excesiva\n");
    	else{
    	x=sscanf(cad, "%s%s", buscar, cad);
    	if(x==-1)printf("\nLongitud nula\n");
    	if(x==2)printf("\nCaracteres ilegales\n");
    	
	}
		   	
	}while (x!=1 || strlen(cad)>26);
	
	for(i=0; i<numero; i++){
		
		if(strcmp(tabla[i].artista, buscar)==0){
		
		ver=true;
		break;
		}
	}

	if(ver==true){
		do{
    	strcpy(buscat, "");
    	fprintf(stdout, "\nDame el titulo del disco: ");
    	fgets(cad, sizeof(cad),stdin);
    	if(strlen(cad)>33)printf("\nLongitud excesiva\n");
    	else{
    	x=sscanf(cad, "%s%s", buscat, cad);
    	if(x==-1)printf("\nLongitud nula\n");
    	if(x==2)printf("\nCaracteres ilegales\n");
    	
	}
		   	
	}while (x!=1 || strlen(cad)>33);
		for(k=i; k<numero; k++){
		if(strcmp(tabla[k].artista, buscar)==0&&strcmp(tabla[k].titulo, buscat)==0){
		printf("\nDatos del disco:\n");
		printf(">Titulo: %s\n", tabla[k].titulo);
		printf(">Artista: %s\n", tabla[k].artista);
		printf(">Fecha: %d\n", tabla[k].fecha);
		printf(">Formato: %s\n", tabla[k].formato);
		printf(">Precio: %.2f\n", tabla[k].precio);
		vert=true;
		break;
	}
	}
	if(vert==false) printf("\nNo existe ese disco");
	}
	else
	{
		printf ("\nNo hay discos de ese artista");
	}
}

	printf("\n");
	return 0;

}

int eliminar(struct unDisco *tabla, int *numero){					//Funcion eliminar
	int x, i, k, m;
	char cad[256];
	char buscar[26];
	char buscat[33];
	bool ver=false, vert=false;
	if (*numero==0)printf("\nNo existen discos");
  	else
 	{
	do{
    	strcpy(buscar, "");
    	fprintf(stdout, "\nDame el nombre del artista: ");
    	fgets(cad, sizeof(cad),stdin);
    	if(strlen(cad)>26)printf("\nLongitud excesiva\n");
    	else{
    	x=sscanf(cad, "%s%s", buscar, cad);
    	if(x==-1)printf("\nLongitud nula\n");
    	if(x==2)printf("\nCaracteres ilegales\n");
    	
	}
		   	
	}while (x!=1 || strlen(cad)>26);
	
	for(i=0; i<*numero; i++){
		
		if(strcmp(tabla[i].artista, buscar)==0){
		
		ver=true;
		break;
		}
	}

	if(ver==true){
		do{
    	strcpy(buscat, "");
    	fprintf(stdout, "\nDame el titulo del disco: ");
    	fgets(cad, sizeof(cad),stdin);
    	if(strlen(cad)>33)printf("\nLongitud excesiva\n");
    	else{
    	x=sscanf(cad, "%s%s", buscat, cad);
    	if(x==-1)printf("\nLongitud nula\n");
    	if(x==2)printf("\nCaracteres ilegales\n");
    	
	}
		   	
	}while (x!=1 || strlen(cad)>33);
		for(k=i; k<*numero; k++){
		if(strcmp(tabla[k].artista, buscar)==0&&strcmp(tabla[k].titulo, buscat)==0){
		printf("\nSe va a eliminar el disco:\n");
		printf(">Titulo: %s\n", tabla[k].titulo);
		printf(">Artista: %s\n", tabla[k].artista);
		printf(">Fecha: %d\n", tabla[k].fecha);
		printf(">Formato: %s\n", tabla[k].formato);
		printf(">Precio: %.2f\n", tabla[k].precio);
		if(confirmar("Eliminar el disco? (s/n):"))
		{
			for (m=k; m<*numero; m++)
			{
				tabla[m]=tabla[m+1];
				
			}
			(*numero)--;
			printf("\nDisco eliminado\n");
		}
		
		vert=true;
		break;
	}
	}
	if(vert==false) printf("\nNo existe ese disco");
	}
	else
	{
		printf ("\nNo hay discos de ese artista");
	}
}
	printf("\n");
	return 0;
}

int modificar(struct unDisco *tabla, int numero){ 									//funcion modificar
  int x, i, k, fecha, v;
	char cad[256];
	char cad2[256];
	char buscar[26];
	char buscat[33];
	bool ver=false, vert=false;
	if (numero==0)printf("\nNo existen discos");
  	else
 	{
	do{
    	strcpy(buscar, "");
    	fprintf(stdout, "\nDame el nombre del artista: ");
    	fgets(cad, sizeof(cad),stdin);
    	if(strlen(cad)>26)printf("\nLongitud excesiva\n");
    	else{
    	x=sscanf(cad, "%s%s", buscar, cad);
    	if(x==-1)printf("\nLongitud nula\n");
    	if(x==2)printf("\nCaracteres ilegales\n");
    	
	}
		   	
	}while (x!=1 || strlen(cad)>26);
	
	for(i=0; i<numero; i++){
		
		if(strcmp(tabla[i].artista, buscar)==0){
		
		ver=true;
		break;
		}
	}

	if(ver==true){
		do{
    	strcpy(buscat, "");
    	fprintf(stdout, "\nDame el titulo del disco: ");
    	fgets(cad, sizeof(cad),stdin);
    	if(strlen(cad)>33)printf("\nLongitud excesiva\n");
    	else{
    	x=sscanf(cad, "%s%s", buscat, cad);
    	if(x==-1)printf("\nLongitud nula\n");
    	if(x==2)printf("\nCaracteres ilegales\n");
    	
	}
		   	
	}while (x!=1 || strlen(cad)>33);
		for(k=i; k<numero; k++){
		if(strcmp(tabla[k].artista, buscar)==0&&strcmp(tabla[k].titulo, buscat)==0){
		printf("\n>Titulo: %s\n", tabla[k].titulo);
		
		if(confirmar("Cambiar el titulo? (s/n):"))
		{
			do{
    	strcpy(cad2, "");
    	fprintf(stdout, "\nDame el titulo del disco: ");
    	fgets(cad, sizeof(cad),stdin);
    	if(strlen(cad)>33)printf("\nLongitud excesiva\n");
    	else{
    	x=sscanf(cad, "%s%s", cad2, cad);
    	if(x==-1)printf("\nLongitud nula\n");
    	if(x==2)printf("\nCaracteres ilegales\n");
    	if(x==1&&strlen(cad2)<33)strcpy(tabla[k].titulo, cad2); 
	}
		   	
	}while (x!=1 || strlen(cad)>33);
		}
		
		printf("\n>Artista: %s\n", tabla[k].artista);
		
		if(confirmar("Cambiar el artista? (s/n):")){
			do{
    	strcpy(cad2, "");
    	fprintf(stdout, "\nDame el nombre del artista: ");
    	fgets(cad, sizeof(cad),stdin);
    	if(strlen(cad)>26)printf("\nLongitud excesiva\n");
    	else{
    	x=sscanf(cad, "%s%s", cad2, cad);
    	if(x==-1)printf("\nLongitud nula\n");
    	if(x==2)printf("\nCaracteres ilegales\n");
    	if(x==1&&strlen(cad2)<26)strcpy(tabla[k].artista, cad2);
		
	}
		   	
	}while (x!=1 || strlen(cad)>26);	
		}
		
		printf("\n>Fecha: %d\n", tabla[k].fecha);
		
		if(confirmar("Cambiar la fecha? (s/n):")){
			do{
    		fprintf(stdout, "\nDame la fecha: ");
    		fgets(cad, sizeof(cad),stdin);
    		x=sscanf(cad, "%s%s", cad2, cad);
    		v=validanumint(cad2);
   			fecha= atoi(cad2);
   			tabla[k].fecha = fecha;
   		
   	 		if (fecha<1900 || fecha>2018|| x!=1||v==1){
   	   			printf("\nValor dado incorrecto. Debe estar en [1900, 2018]\n");
  	  			}
   		}while(fecha<1900 || fecha>2018||x!=1|| v==1);
			
			
		}
		
		printf("\n>Formato: %s\n", tabla[k].formato);
		
		if(confirmar("Cambiar el formato? (s/n):")){
			fprintf(stdout, "\nDame el formato: ");
    	fgets(cad, sizeof(cad),stdin);
    	x=sscanf(cad, "%s%s", cad2, cad);
		if(strcmp(cad2, "LP")==0 || strcmp(cad2, "CD")==0 || strcmp(cad2, "DD")==0 || strcmp(cad2, "MC")==0|| x!=1)
   			{
   				strcpy(tabla[k].formato, cad2);
			   }
			   
		while((strcmp(cad2, "LP")!=0 && strcmp(cad2, "CD")!=0 && strcmp(cad2, "DD")!=0 && strcmp(cad2, "MC")!=0)||x!=1)
		{
			printf("\nFormato no aceptado (LP, CD, DD o MC)\n");
			fprintf(stdout, "\nDame el formato: ");
			fgets(cad, sizeof(cad),stdin);
   			x=sscanf(cad, "%s%s", cad2, cad);
   			if(strcmp(cad2, "LP")==0 || strcmp(cad2, "CD")==0 || strcmp(cad2, "DD")==0 || strcmp(cad2, "MC")==0|| x!=1)
   			{
   				strcpy(tabla[k].formato, cad2);
			   }
		}
			
		}
		
		
		printf("\nModificado disco:");
		printf("\n>Titulo: %s\n", tabla[k].titulo);
		printf(">Artista: %s\n", tabla[k].artista);
		printf(">Fecha: %d\n", tabla[k].fecha);
		printf(">Formato: %s\n", tabla[k].formato);
		printf(">Precio: %.2f\n", tabla[k].precio);
		vert=true;
		break;
	}
	}
	if(vert==false) printf("\nNo existe ese disco");
	}
	else
	{
		printf ("\nNo hay discos de ese artista");
	}
}
  
  printf("\n");
  return 0;
}
void todos(struct unDisco *tabla, int numero){                                  //Funcion todos
  int i=0, sal;
  if (numero==0)printf("\nNo existen discos");
  else
  {
	do
	{
	
		printf("\n>Titulo: %s\n", tabla[i].titulo);
		printf(">Artista: %s\n", tabla[i].artista);
		printf(">Fecha: %d\n", tabla[i].fecha);
		printf(">Formato: %s\n", tabla[i].formato);
		printf(">Precio: %.2f\n", tabla[i].precio);
		i++;
		if (i<numero) sal=confirmar("\nVer los datos de otro disco? (s/n): ");
		
	}while (i<numero && sal==1);
}
  printf("\n");
  
}


void salir(char frase[], int *sal, struct unDisco *tabla,int numero){
	*sal=confirmar(frase);
	if((*sal)==1)
	{
	finalizar(tabla, numero);
	}
	}
	
