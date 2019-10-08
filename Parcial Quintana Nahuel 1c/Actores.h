#include <stdio.h>
#include <stdlib.h>
#include "Peliculas.h"
#include "Elenco.h"

typedef struct{

int codigo;
char nombre[52];
char apellido[52];
char sexo;
int estado; ///0 -> Vacio -- 1 -> Ocupado

}eActor;


int addActor(eActor listaDeActores[], int len);
int pedirIndiceLibre(eActor listaDeActores[], int tam);
int menuDeActores(char mensaje[], eActor listaDeActores[], int len);
int printActores (eActor listaDeActores[], int len);
int initActores(eActor listaDeActores[], int len);
int mostrarActor (eActor unActor);
int subMenu (eActor* unActor);
int removeActor(eActor listaDeActores[], int len, int codigo);
int findActorbyCodigo(eActor* listaDeActores, int len,int codigo);
void modificarApellido(eActor* unActor);
void modificarNombre(eActor* unActor);
void modificarSexo(eActor* unActor);
void sortActoresPorApellido(eActor listaDeActores[], int len);
