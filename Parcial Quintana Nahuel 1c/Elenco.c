#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Peliculas.h"
#include "validar.h"
#include "Actores.h"
#include "Elenco.h"
#define VACIO 0
#define OCUPADO 1


void addElenco(eActor listaDeActores[], int TA, ePeliculas listaPeliculas[], int TP, eGenero listaDeGeneros[], int TG, eElenco listaElencos[],int TE)
{
    int codigoActorAux,codigoPeliculaAux,auxValor;
    int i;
    i = pedirIndiceLibreElenco(listaElencos, TE);
    if(i != -1)
    {
        system("cls");
        mostrarPeliculasConGenero(listaPeliculas, TP,listaDeGeneros, TG);
        getValidInt("Ingrese el codigo de la pelicula: ","Ingrese un codigo valido",0,TP,&codigoPeliculaAux);
        system("cls");
        printActores(listaDeActores, TA);
        getValidInt("\nIngrese el codigo del Actor para este Reparto: ","Ingrese un codigo valido",0,TA,&codigoActorAux);
        getValidInt("\nIngrese el valor del contrato del Actor: ","Ingrese un numero Valido",0,15000000,&auxValor);
        if (verificarPares(codigoActorAux,codigoPeliculaAux,listaElencos, TE) == 0)
        {
            listaElencos[i].codigoActor = codigoActorAux;
            listaElencos[i].codigoPelicula = codigoPeliculaAux;
            listaElencos[i].valorContrato = auxValor;
            listaElencos[i].estado = OCUPADO;
        }
        else
        {
            printf("\nYa existe esa Ocurrencia Actor-Pelicula\n");
        }
    }
    else
    {
        printf("\nNo hay mas espacio\n");
    }
}

void menuDeElencos(char mensaje[],eActor listaDeActores[], int TA, ePeliculas listaPeliculas[], int TP, eGenero listaDeGeneros[], int TG, eElenco listaElencos[],int TE)
{
    int opcion;
    do
    {
        getValidInt(mensaje,"Ingrese una opcion valida",0,4,&opcion);
        switch(opcion)
        {
        case 1:
            addElenco(listaDeActores,TA, listaPeliculas, TP, listaDeGeneros,  TG,  listaElencos, TE);
            break;
        case 2:
            sortElencos(listaElencos, TE,listaPeliculas,TP,listaDeActores,TA);
            mostrarElenco(listaElencos, TE, listaPeliculas, TP, listaDeActores, TA);
            break;
        case 3:
            opcion = 3;
            break;
        }

    }
    while(opcion != 3);
}

int pedirIndiceLibreElenco(eElenco listaDeElencos[], int tam)
{
    int i;
    for ( i = 0; i < tam ; i++)
    {
        if(listaDeElencos[i].estado == VACIO)
        {
            return i;
            break;
        }
    }
    return -1;
}

int initElenco(eElenco list[], int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        list[i].estado = VACIO;
    }
    return 0;
}

int verificarPares(int indiceActor, int indicePelicula, eElenco listaDeElencos[], int TE)
{
    int i;

    for(i = 0 ; i < TE ; i++)
    {
        if(listaDeElencos[i].codigoActor == indiceActor && listaDeElencos[i].codigoPelicula == indicePelicula)
        {
            return 1; /// YA EXISTE PAR
        }

    }
    return 0; /// NO EXISTE
}

void sortElencos(eElenco listaDeElenco[], int TE, ePeliculas listaDePeliculas[], int TP,eActor listaActores[],int TA)
{
    int i;
    int j;
    eElenco AuxElenco;
    for(i=0; i<TE-1; i++)
    {
        for(j=i+1; j<TE; j++)
        {
            if(listaDeElenco[i].estado == OCUPADO && listaDeElenco[j].estado == OCUPADO)
            {
                if(strcmp(listaDePeliculas[listaDeElenco[i].codigoPelicula-1].descripcion,listaDePeliculas[listaDeElenco[j].codigoPelicula-1].descripcion)>0)
                {
                    AuxElenco = listaDeElenco[i];
                    listaDeElenco[i] = listaDeElenco[j];
                    listaDeElenco[j] = AuxElenco;
                }
                else
                {
                    if(strcmp(listaDePeliculas[listaDeElenco[i].codigoPelicula-1].descripcion,listaDePeliculas[listaDeElenco[j].codigoPelicula-1].descripcion)==0)
                    {
                        if(listaActores[listaDeElenco[i].codigoActor-1].apellido>listaActores[listaDeElenco[j].codigoActor-1].apellido)
                        {
                            AuxElenco = listaDeElenco[i];
                            listaDeElenco[i] = listaDeElenco[j];
                            listaDeElenco[j] = AuxElenco;
                        }
                    }
                }
            }


        }
    }

}

void promedioElenco (eElenco listaDeElenco[],int TE, ePeliculas listaDePeliculas[], int TP)
{
    int i, j;
    int acumuladorAux = 0;
    int contador = 0;
    int totalFinal;
    for(i = 0; i < TE; i++)
    {
        for(j = 0; j < TP ; j++)
        {
            if(listaDeElenco[i].codigoPelicula == listaDePeliculas[j].codigo)
            {
                contador ++;
                acumuladorAux = listaDeElenco[i].valorContrato + acumuladorAux;
            }
        }
    }
    totalFinal = acumuladorAux / contador;
    printf("\n El promedio de valor del contrato de actores para esta pelicula es: %d", totalFinal);
}

void mostrarElenco(eElenco listaDeElenco[],int TE, ePeliculas listaDePeliculas[],int TP,eActor listaDeActores[],int TA)
{
    int i;
    for(i = 0; i < TE; i++)
    {
        if(listaDeElenco[i].estado == OCUPADO)
        {
            printf("PELICULA: %s\n",listaDePeliculas[listaDeElenco[i].codigoPelicula-1].descripcion);
            printf("Apellido: %s\t",listaDeActores[listaDeElenco[i].codigoActor -1].apellido);
            printf("Nombre: %s\t",listaDeActores[listaDeElenco[i].codigoActor -1].nombre);
            printf("Valor: %d\t\n",listaDeElenco[i].valorContrato);
        }

    }
}

