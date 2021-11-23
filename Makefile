# ************************************************************************
#
# Programación I.  Curso 2018-2019
# Compilación del ejercicio  06 de la practica 6
#
# ************************************************************************
CC = gcc -Wall

all:  discos

portada.o:  portada.c  portada.h
	$(CC) -c  portada.c

basedatos.o:  basedatos.c basedatos.h portada.h
	$(CC) -c  basedatos.c

discos:  discos.c  portada.o basedatos.o
	$(CC) portada.o basedatos.o discos.c -o  discos

clean:
	rm -f  discos *.o *~ *.bak
