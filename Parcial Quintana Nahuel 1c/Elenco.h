#include <stdio.h>
#include <stdlib.h>


typedef struct
{
int codigoPelicula;
int codigoActor;
int valorContrato;
int estado; ///1 si se cargo un elenco --- 0 si no
}eElenco;

void addElenco(eActor listaDeActores[], int TA, ePeliculas listaPeliculas[], int TP, eGenero listaDeGeneros[], int TG, eElenco listaElencos[],int TE, ePais listaPaises[], int tamPaises);
void menuDeElencos(char mensaje[],eActor listaDeActores[], int TA, ePeliculas listaPeliculas[], int TP, eGenero listaDeGeneros[], int TG, eElenco listaElencos[],int TE, ePais listaPaises[], int tamPaises);
int initElenco(eElenco listaDeElencos[], int len);
int pedirIndiceLibreElenco(eElenco listaDeElencos[], int tam);
int verificarPares(int indiceActor, int indicePelicula, eElenco listaDeElencos[], int TE);
void menuDeElencos(char mensaje[],eActor listaDeActores[], int TA, ePeliculas listaPeliculas[], int TP, eGenero listaDeGeneros[], int TG, eElenco listaElencos[],int TE, ePais listaPaises[], int tamPaises);
void sortElencos(eElenco listaDeElenco[], int TE, ePeliculas listaDePeliculas[], int TP,eActor listaActores[],int TA);
void mostrarElenco(eElenco listaDeElenco[],int TE, ePeliculas listaDePeliculas[],int TP,eActor listaDeActores[],int TA);
int removeElenco(eElenco listaElenco[], int len, int codigo);
void hardCodearElenco(eActor listaDeActores[], int TA, ePeliculas listaPeliculas[], int TP, eGenero listaDeGeneros[], int TG, eElenco listaElencos[],int TE, ePais listaPaises[], int tamPaises);
void menuDeInformes(char mensaje[],ePeliculas listadePeliculas[],int TP, eGenero listaDeGeneros[], int TG, eElenco listaDeElencos[], int TE, eActor listaDeActores[],int TA, ePais listaDePaises[],int TPAIS);
int mostrarPeliculasTerror(ePeliculas listaDePeliculas[], int TP, eGenero listaDeGeneros[], int TG);
void peliculasArgentino(eElenco listaDeElencos[],int TE, eActor listaDeActores[],int TA, ePais listaPaises[],int TPAIS, ePeliculas listaDePeliculas[],int TP);
void buscarPeliculaPorActor(eElenco listaDeElencos[],int TE, eActor listaDeActores[],int TA,ePeliculas listaDePeliculas[], int TP,int codigo, eGenero listaDeGeneros[], int TG);
void peliculasTerror(ePeliculas listaDePeliculas[], int TP, eGenero listaDeGeneros[], int TG);
void peliculasTerror(ePeliculas listaDePeliculas[], int TP, eGenero listaDeGeneros[], int TG);
