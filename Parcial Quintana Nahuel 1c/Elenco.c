#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Peliculas.h"
#include "validar.h"
#include "Actores.h"
#include "Elenco.h"
#define VACIO 0
#define OCUPADO 1


void addElenco(eActor listaDeActores[], int TA, ePeliculas listaPeliculas[], int TP, eGenero listaDeGeneros[], int TG, eElenco listaElencos[],int TE, ePais listaPaises[], int tamPaises)
{
    int codigoActorAux,codigoPeliculaAux,auxValor;
    int i;
    i = pedirIndiceLibreElenco(listaElencos, TE);
    if(i != -1)
    {
        system("cls");
        mostrarPeliculasConGenero(listaPeliculas, TP,listaDeGeneros, TG);
        getValidInt("Ingrese el codigo de la pelicula: ","Ingrese un codigo valido",0,1000,&codigoPeliculaAux);
        system("cls");
        printActores(listaDeActores, TA,listaPaises,tamPaises);
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

void menuDeElencos(char mensaje[],eActor listaDeActores[], int TA, ePeliculas listaPeliculas[], int TP, eGenero listaDeGeneros[], int TG, eElenco listaElencos[],int TE, ePais listaPaises[], int tamPaises)
{
    int opcion;
    do
    {
        getValidInt(mensaje,"Ingrese una opcion valida",0,4,&opcion);
        switch(opcion)
        {
        case 1:
            addElenco(listaDeActores,TA, listaPeliculas, TP, listaDeGeneros,  TG,  listaElencos, TE,listaPaises, tamPaises);
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
        if(listaDeElenco[i].estado == OCUPADO && listaDeActores[listaDeElenco[i].codigoActor -1].estado == OCUPADO)
        {
            printf("PELICULA: %s\n",listaDePeliculas[listaDeElenco[i].codigoPelicula-1].descripcion);
            printf("Apellido: %s\t",listaDeActores[listaDeElenco[i].codigoActor -1].apellido);
            printf("Nombre: %s\t",listaDeActores[listaDeElenco[i].codigoActor -1].nombre);
            printf("Valor: %d\t\n",listaDeElenco[i].valorContrato);
        }

    }
}

void hardCodearElenco(eActor listaDeActores[], int TA, ePeliculas listaPeliculas[], int TP, eGenero listaDeGeneros[], int TG, eElenco listaElencos[],int TE, ePais listaPaises[], int tamPaises)
{
    int codigoAux[] = {1,2,3};
    int codigoAuxPelicula[] = {1,2,3};
    float valorContrato[] = {10000,12452,12455};
    int i;
    for(i = 0; i < 3; i++)
    {
        listaElencos[i].codigoActor = codigoAux[i];
        listaElencos[i].codigoPelicula = codigoAuxPelicula[i];
        listaElencos[i].valorContrato = valorContrato[i];
        listaElencos[i].estado = OCUPADO;
    }

}

void menuDeInformes(char mensaje[],ePeliculas listadePeliculas[],int TP, eGenero listaDeGeneros[], int TG, eElenco listaDeElencos[], int TE, eActor listaDeActores[],int TA, ePais listaDePaises[],int TPAIS)
{
    int opcion, opcionAux;
    do
    {
        getValidInt(mensaje,"Ingrese una opcion valida",0,6,&opcion);
        switch(opcion)
        {
        case 1:
            peliculasTerror(listadePeliculas, TP,listaDeGeneros,TG);
            break;
        case 2:
            //peliculasArgentino(listaDeElencos, TE, listaDeActores, TA, listaDePaises, TPAIS, listadePeliculas, TP);
            break;
        case 3:

            printActores(listaDeActores, TA, listaDePaises, TP);
            getValidInt("Ingrese el Actor a buscar","Ingrese un id valida",0,TA,&opcionAux);
            buscarPeliculaPorActor(listaDeElencos, TE,listaDeActores,TA,listadePeliculas,TP,opcionAux, listaDeGeneros, TG);
            break;
        case 4:
            opcion = 4;
            break;
        }

    }
    while(opcion != 4);
}
int mostrarPeliculasTerror(ePeliculas listaDePeliculas[], int TP, eGenero listaDeGeneros[], int TG)
{
    int i;
    int idAux = -1;
    printf("Pelicula\t\Duracion\t\tGenero\t\tFecha\t\tCodigo\n");
    for(i = 0; i < TP; i++)
    {
        if((strcmp(listaDeGeneros[i].descripcion,"Terror")== 0) )
        {
            idAux = listaDeGeneros[i].id;
        }
    }

    return idAux;
}

void peliculasTerror(ePeliculas listaDePeliculas[], int TP, eGenero listaDeGeneros[], int TG)
{
    int i;
    int codigo;
    codigo = mostrarPeliculasTerror(listaDePeliculas, TP, listaDeGeneros,TG);

    for(i = 0; i < TP ; i++)
    {
        if(listaDePeliculas[i].idGenero == codigo && listaDePeliculas[i].unaFecha.anio > 2002)
        {
            printf("%-10s\t", listaDePeliculas[i].descripcion);
            printf("%-10.2f\t", listaDePeliculas[i].duracion);
            printf("%d/", listaDePeliculas[i].unaFecha.dia);
            printf("%d/", listaDePeliculas[i].unaFecha.mes);
            printf("%d\t", listaDePeliculas[i].unaFecha.anio);
            printf("%-10d\n", listaDePeliculas[i].codigo);
        }
    }



}

void buscarPeliculaPorActor(eElenco listaDeElencos[],int TE, eActor listaDeActores[],int TA,ePeliculas listaDePeliculas[], int TP,int codigo, eGenero listaDeGeneros[],int TG)
{
    int i;
    for(i = 0; i < TE; i++)
    {
        if(listaDeElencos[i].codigoActor == codigo)
        {
            printf("\nPELICULA: %s\n",listaDePeliculas[listaDeElencos[i].codigoPelicula-1].descripcion);

        }
    }
}
