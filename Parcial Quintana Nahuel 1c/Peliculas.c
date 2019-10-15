#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Peliculas.h"


void hardCodearDatos(ePeliculas listaDePeliculas[], int TP,eGenero listaDeGeneros[], int TG)
{
    int codigoAux[] = {1,2,3};
    char descripcion[][50]= {"IT","Avengers","Que Paso Ayer"};
    float duracionAux [] = {2.30, 3, 2};
    int idAux[] = {1,2,3};
    char nombreGeneros[][50] = {"Terror","Accion","Comedia"};
    int i, j;
    for(i = 0; i < TP; i++)
    {
        listaDePeliculas[i].codigo = codigoAux[i];
        listaDePeliculas[i].duracion = duracionAux[i];
        strcpy(listaDePeliculas[i].descripcion,descripcion[i]);
        listaDePeliculas[i].idGenero = idAux[i];
    }
    for(j = 0; j < TG; j++)
    {
        listaDeGeneros[j].id = idAux[j];
        strcpy(listaDeGeneros[j].descripcion,nombreGeneros[j]);
    }
}

void mostrarPeliculasConGenero(ePeliculas listaDePeliculas[], int TP,eGenero listaDeGeneros[], int TG)
{
    int i,j;
    int flagEstado = 1;
    printf("Pelicula\t\Duracion\t\tGenero\t\tCodigo\n");
    for(i = 0; i < TP; i++)
    {
        for(j = 0; j < TG; j++)
        {
            if(listaDePeliculas[i].idGenero == listaDeGeneros[j].id)
            {
                printf("%-10s\t", listaDePeliculas[i].descripcion);
                printf("%-10.2f\t", listaDePeliculas[i].duracion);
                printf("%-10s\t", listaDeGeneros[j].descripcion);
                printf("%-10d\n", listaDePeliculas[i].codigo);
            }
        }

    }

}
