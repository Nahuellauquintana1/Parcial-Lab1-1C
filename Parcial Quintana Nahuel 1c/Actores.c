#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "Actores.h"
#include "Peliculas.h"
#include "Elenco.h"
#define VACIO 0
#define OCUPADO 1

int initActores(eActor list[], int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        list[i].estado = VACIO;
    }
    return 0;
}
int addActor(eActor list[], int len)
{
    int i;
    i = pedirIndiceLibre(list, len);
    if(i!=-1)
    {
        list[i].codigo = i+1;
        getValidString("Ingrese Nombre: ","Ingrese un Nombre Valido\n",1,50,list[i].nombre);
        list[i].nombre[0] = toupper(list[i].nombre[0]);
        getValidString("Ingrese Apellido: ","Ingrese un Apellido Valido\n",1,50,list[i].apellido);
        list[i].apellido[0] = toupper(list[i].apellido[0]);
        list[i].sexo = getChar("Ingrese el sexo del Actor ('M' o 'F'): ");
        list[i].estado = OCUPADO;
        return 1;
    }
    else
    {
        return -1;
    }
}

int pedirIndiceLibre(eActor listaDeActores[], int tam)
{
    int i;
    for ( i = 0; i < tam ; i++)
    {
        if(listaDeActores[i].estado == VACIO)
        {
            return i;
            break;
        }
    }
    return -1;
}

int menuDeActores(char mensaje[], eActor list[], int tam)
{
    int opcion;
    int codigoAux;
    eActor listAux[tam];
    do
    {
        getValidInt(mensaje,"Ingrese una opcion valida",0,6,&opcion);
        system("cls");
        switch(opcion)
        {
        case 1:
            if(addActor(list, tam) != -1)
            {
                printf("\nActor Cargado\n");
            }
            else
            {
                printf("\nError en la Carga del Actor\n");
            }
            break;
        case 2:
            printActores(list,tam);
            getValidInt("Ingrese el codigo del Actor a Modificar","Ingrese un numero",0,10,&codigoAux);
            findActorbyCodigo(list,tam,codigoAux);
            break;
        case 3:
            printActores(list, tam);
            codigoAux = 0;
            getValidInt("\nIngrese el codigo del actor a dar de baja: ","Ingrese un numero",0,10,&codigoAux);
            if(removeActor(list,tam,codigoAux) != 0)
            {
                printf("\nActor dado de baja\n");
            }
            else
            {
                printf("\nNo existe Actor con ese codigo\n");
            }
            break;
        case 4:
            memcpy(listAux,list,sizeof(listAux));
            sortActoresPorApellido(listAux, tam);
            printActores(listAux, tam);
            break;
        case 5:
            opcion = 5;
            break;
        }
        return 0;
    }
    while(opcion != 5);
}


int printActores (eActor list[], int len)
{
    int i;
    int flagEstado = 1;
    printf("Apellido\t\tNombre\t\tSexo\t\tID\n");
    for(i = 0; i < len; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            flagEstado = 0;
            mostrarActor(list[i]);
        }

    }
    if(flagEstado == 1)
    {
        printf("\nNo hay Actores Cargados\n");
    }
    return 0;
}
int mostrarActor (eActor unActor)
{
    printf("%-10s\t", unActor.apellido);
    printf("%-10s\t", unActor.nombre);
    printf("%15c\t", unActor.sexo);
    printf("%15d\n", unActor.codigo);
    return 0;
}

int removeActor(eActor list[], int len, int codigo)
{
    int i;
    int retorno = 0; /// Si existe actor 1 ---- Si no Existe actor 0
    for(i = 0; i  < len ; i++)
    {
        if(list[i].codigo == codigo)
        {
            list[i].estado = VACIO;

            retorno = 1;
        }
    }
    return retorno;
}

int findActorbyCodigo(eActor* list, int len,int codigo)
{
    int i;
    int flag = 0;

    for(i = 0; i < len; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            if(list[i].codigo == codigo)
            {
                subMenu(&list[i]);
                flag = 1;
            }
        }
    }
    if(flag != 1)
    {
        printf("No existe Actor con ese CODIGO");
    }
    return codigo;
}
int subMenu (eActor* unActor)
{
    int opcion,retorno;
    system("cls");
    do
    {
        getValidInt("1. Apellido\n2. Nombre\n3. Sexo\n4. Volver al Menu Anterior\n","Por favor Ingrese una Opcion Valida",1,4,&opcion);

        switch(opcion)
        {
        case 1:
            modificarApellido(unActor);
            retorno = 1;
            break;
        case 2:
            modificarNombre(unActor);
            retorno = 1;
            break;
        case 3:
            modificarSexo(unActor);
            retorno = 1;
            break;
        case 4:
            opcion = 4;
            break;
        }
        system("cls");
    }
    while(opcion != 4);
    return retorno;

}

void modificarApellido(eActor* unActor)
{
    char auxApellido[50];
    getValidString("Ingrese el Nuevo Apellido: ","Ingrese un Apellido Valido",1,49,auxApellido);
    fflush(stdin);
    strcpy(unActor->apellido,auxApellido);
}

void modificarNombre(eActor* unActor)
{
    char auxNombre[50];
    getValidString("Ingrese el Nuevo Nombre: ","Ingrese un Nombre Valido",1,49,auxNombre);
    fflush(stdin);
    strcpy(unActor->nombre,auxNombre);
}

void modificarSexo(eActor* unActor)
{
    char auxSexo;
    getValidString("Ingrese el Nuevo Sexo(M o F): ","Ingrese un Sexo (M o F)",1,49, &auxSexo);
    fflush(stdin);
    unActor->sexo = auxSexo;
}
void sortActoresPorApellido(eActor list[], int len)
{
    int i;
    int j;
    eActor auxActor;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(list[i].estado == OCUPADO)
            {
                if(strcmp(list[i].apellido,list[j].apellido)>0)
                {
                    auxActor = list[i];
                    list[i] = list[j];
                    list[j] = auxActor;
                }
                else
                {
                    if(strcmp(list[i].apellido,list[j].apellido)==0)
                    {
                        if(list[i].nombre>list[j].nombre)
                        {
                            auxActor = list[i];
                            list[i] = list[j];
                            list[j] = auxActor;
                        }
                    }
                }
            }
        }
    }
}
int removeElenco(eElenco list[], int len, int codigo)
{
    int i;
    int retorno = 0; /// Si existe actor 1 ---- Si no Existe actor 0
    for(i = 0; i  < len ; i++)
    {
        if(list[i].codigoActor == codigo)
        {
            list[i].estado = VACIO;

            retorno = 1;
        }
    }
    return retorno;
}

