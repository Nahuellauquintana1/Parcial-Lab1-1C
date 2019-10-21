#include <stdio.h>
#include <stdlib.h>
#include "Pais.h"

typedef struct{

int codigo;
char nombre[52];
char apellido[52];
char sexo;
int estado; ///0 -> Vacio -- 1 -> Ocupado
int idPais;

}eActor;


int addActor(eActor listaDeActores[], int len, ePais listaPaises[], int tam);
int pedirIndiceLibre(eActor listaDeActores[], int tam);
int menuDeActores(char mensaje[], eActor listaDeActores[], int len, ePais listaPaises[], int tam);
int printActores (eActor listaDeActores[], int len, ePais listaDePais[], int tamPais);
int initActores(eActor listaDeActores[], int len);
int mostrarActor (eActor unActor, ePais listaDePais[], int tamPais);
int subMenu (eActor* unActor);
int removeActor(eActor listaDeActores[], int len, int codigo);
int findActorbyCodigo(eActor* listaDeActores, int len,int codigo);
void modificarApellido(eActor* unActor);
void modificarNombre(eActor* unActor);
void modificarSexo(eActor* unActor);
void sortActoresPorApellido(eActor listaDeActores[], int len);
void hardCodearActores(eActor listaActores[]);
void paisesElegir(ePais listaPaises[], int tam);
void mostrarPaises(ePais listaPaises[],int tam);
