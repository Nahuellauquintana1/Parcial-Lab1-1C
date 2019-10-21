#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Peliculas.h"

void hardCodearDatos(ePeliculas listaDePeliculas[], int TP,eGenero listaDeGeneros[], int TG)
{
    int codigoAux[] = {1,2,3,4};
    char descripcion[][50]= {"Avengers","IT","Gen1","Run"};
    float duracionAux [] = {2.30, 3, 2, 1.30};
    int idAux[] = {1,2,3,4};
    char nombreGeneros[][50] = {"Accion","Terror","Romance","Suspenso"};
    int diaAux[] = {10, 20, 17,20};
    int mesAux[] = {2, 5, 7,1};
    int anioAux[] = {2010, 2019, 2008,2001};
    int i, j;
    for(i = 0; i < TP; i++)
    {
        listaDePeliculas[i].codigo = codigoAux[i];
        listaDePeliculas[i].duracion = duracionAux[i];
        strcpy(listaDePeliculas[i].descripcion,descripcion[i]);
        listaDePeliculas[i].idGenero = idAux[i];
        listaDePeliculas[i].unaFecha.dia = diaAux[i];
        listaDePeliculas[i].unaFecha.mes = mesAux[i];
        listaDePeliculas[i].unaFecha.anio = anioAux[i];
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
    printf("Pelicula\t\Duracion\t\tGenero\t\tFecha\t\tCodigo\n");
    for(i = 0; i < TP; i++)
    {
        for(j = 0; j < TG; j++)
        {
            if(listaDePeliculas[i].idGenero == listaDeGeneros[j].id)
            {
                printf("%-10s\t", listaDePeliculas[i].descripcion);
                printf("%-10.2f\t", listaDePeliculas[i].duracion);
                printf("%-10s\t", listaDeGeneros[j].descripcion);
                printf("%d/", listaDePeliculas[i].unaFecha.dia);
                printf("%d/", listaDePeliculas[i].unaFecha.mes);
                printf("%d\t", listaDePeliculas[i].unaFecha.anio);
                printf("%-10d\n", listaDePeliculas[i].codigo);
            }
        }

    }

}

