#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Peliculas.h"
#include "validar.h"
#include "Actores.h"
#include "Elenco.h"
#define TA 10
#define TP 4
#define TG 4
#define TE 15
#define TPAIS 4

int main()
{
    eActor listadeActores[TA];
    ePeliculas listadePeliculas[TP];
    eGenero listaDeGeneros[TP];
    eElenco listaElencos[TE];
    ePais listaDePaises[TP];
    initActores(listadeActores,TA);
    initElenco(listaElencos, TE);
    paisesElegir(listaDePaises, TPAIS);
    hardCodearActores(listadeActores);
    hardCodearDatos(listadePeliculas, TP, listaDeGeneros, TG);
    hardCodearElenco(listadeActores, TA, listadePeliculas, TP, listaDeGeneros, TG, listaElencos, TE, listaDePaises, TPAIS);
    int opcion;
    do
    {
        getValidInt("1. Menu Actores\n2. Menu Elencos\n3. Menu Informes\n","Error Por favor Ingrese numeros Validos",0,3,&opcion);

        switch(opcion)
        {
        case 1:
            menuDeActores("1. Cargar Actor\n2. Modificar Actor\n3. Dar de baja un Actor\n4. Listar Actores\n5. volver al menu anterior\n",listadeActores, TA,listaDePaises, TPAIS);
            break;
        case 2:
            menuDeElencos("1. Cargar Nuevo Elenco\n2. Mostrar Elencos\n3. Salir\n",listadeActores,TA,listadePeliculas,TP,listaDeGeneros,TG,listaElencos,TE, listaDePaises, TPAIS);
            break;
        case 3:
            menuDeInformes("1. Informe1\n2. Informe2\n3. Informe3\n4. Informe4\n5. Informe5\n6. Salir\n", listadePeliculas, TP, listaDeGeneros, TG, listaElencos,  TE,  listadeActores, TA,  listaDePaises, TPAIS);
            break;
        case 4:
           opcion = 5;
           break;
        }
        system("pause");
        system("cls");

    }
    while(opcion!=5);

    return 0;
}

