#include <stdio.h>
#include <stdlib.h>
#include "Fecha.h"

typedef struct{
    int codigo;
    char descripcion[52];
    float duracion;
    int idGenero;
    eFecha unaFecha;
}ePeliculas;

typedef struct{

int id;
char descripcion[52];

}eGenero;


void mostrarPeliculasConGenero(ePeliculas listaDePeliculas[], int TP,eGenero listaDeGeneros[], int TG);
void hardCodearDatos(ePeliculas listaDePeliculas[], int TP,eGenero listaDeGeneros[], int TG);

