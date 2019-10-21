#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VACIO 0
#define OCUPADO 1
#include "validar.h"
#include "Actores.h"
#include "Peliculas.h"
#include "Elenco.h"
int initActores(eActor list[], int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        list[i].estado = VACIO;
    }
    return 0;
}
int addActor(eActor list[], int len, ePais listaPaises[], int tam)
{
    char opcionAux;
    int idAux;
    int i;
    i = pedirIndiceLibre(list, len);
    if(i!=-1)
    {
        list[i].codigo = i+1;
        getValidString("Ingrese Nombre: ","Ingrese un Nombre Valido\n",1,50,list[i].nombre);
        list[i].nombre[0] = toupper(list[i].nombre[0]);
        getValidString("Ingrese Apellido: ","Ingrese un Apellido Valido\n",1,50,list[i].apellido);
        list[i].apellido[0] = toupper(list[i].apellido[0]);
        do
        {
            opcionAux = getChar("Ingrese el sexo del Actor ('M' o 'F'): ");
        }
        while(opcionAux != 'm' && opcionAux != 'f');
        list[i].sexo = opcionAux;
        mostrarPaises(listaPaises, tam);
        getValidInt("Ingrese Numero de Pais", "Ingrese un numero valido",0,5,&idAux);
        list[i].idPais = idAux;
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

int menuDeActores(char mensaje[], eActor list[], int tam,ePais listaPais[], int tamPaises)
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
            if(addActor(list, tam, listaPais, tamPaises) != -1)
            {
                printf("\nActor Cargado\n");
            }
            else
            {
                printf("\nError en la Carga del Actor\n");
            }
            break;
        case 2:
            printActores(list,tam, listaPais, tamPaises);
            getValidInt("Ingrese el codigo del Actor a Modificar","Ingrese un numero",0,1000,&codigoAux);
            findActorbyCodigo(list,tam,codigoAux);
            break;
        case 3:
            printActores(list,tam, listaPais, tamPaises);
            codigoAux = 0;
            getValidInt("\nIngrese el codigo del actor a dar de baja: ","Ingrese un numero",0,1000,&codigoAux);
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
            printActores(list,tam, listaPais, tamPaises);
            break;
        case 5:
            opcion = 5;
            break;
        }
        return 0;
    }
    while(opcion != 5);
}


int printActores (eActor list[], int len, ePais listaPaises[], int tam)
{
    int i;
    int flagEstado = 1;
    printf("Apellido\t\tNombre\t\tSexo\t\tPais\t\tID\n");
    for(i = 0; i < len; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            flagEstado = 0;
            mostrarActor(list[i], listaPaises, tam);
        }

    }
    if(flagEstado == 1)
    {
        printf("\nNo hay Actores Cargados\n");
    }
    return 0;
}
int mostrarActor (eActor unActor, ePais listaPaises[], int tam)
{
    printf("%-10s\t", unActor.apellido);
    printf("%-10s\t", unActor.nombre);
    printf("%15c\t", unActor.sexo);
    int i;
    for(i=0; i< tam; i++)
    {
        if(unActor.idPais == listaPaises[i].id)
        {
            printf("%-10s",listaPaises[i].descripcion);
        }
    }
    printf("%15d\n", unActor.codigo);
    return 0;
}

int removeActor(eActor list[], int len, int codigo)
{
    int i;
    int retorno = 0; /// Si existe actor 1 ---- Si no Existe actor 0
    int opcionAux;
    for(i = 0; i  < len ; i++)
    {
        if(list[i].codigo == codigo)
        {
            opcionAux = getChar("Esta seguro que desea dar de baja a este Empleado (s/n)");
            if(opcionAux == 's')
            {
                list[i].estado = VACIO;
                retorno = 1;
            }

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
    char opcion;
    getValidString("Ingrese el Nuevo Apellido: ","Ingrese un Apellido Valido",1,49,auxApellido);
    fflush(stdin);
    opcion = getChar("Desea completar la Modificacion (s/n)");
    if(opcion == 's')
    {
        strcpy(unActor->apellido,auxApellido);
        printf("Cambio Realizado");
    }

}

void modificarNombre(eActor* unActor)
{
    char auxNombre[50];
    char opcion;
    getValidString("Ingrese el Nuevo Nombre: ","Ingrese un Nombre Valido",1,49,auxNombre);
    fflush(stdin);
    opcion = getChar("Desea completar la Modificacion (s/n)");
    if(opcion == 's')
    {
        strcpy(unActor->nombre,auxNombre);
        printf("Cambio Realizado");
    }

}

void modificarSexo(eActor* unActor)
{
    char auxSexo;
    char opcion;
    getValidString("Ingrese el Nuevo Sexo(M o F): ","Ingrese un Sexo (M o F)",1,49, &auxSexo);
    fflush(stdin);
    opcion = getChar("Desea completar la Modificacion (s/n)");
    if(opcion == 's')
    {
        unActor->sexo = auxSexo;
        printf("Cambio Realizado");
    }

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

void hardCodearActores(eActor listaActores[])
{
    int codigoAux[] = {1,2,3};
    char nombreAux[][50] = {"Jose","Pedro","Maria"};
    char apellidoAux[][50] = {"Rodriguez","Fernandez","Ben"};
    char sexo[] = {'m','m','f'};
    int idPaisAux[] = {1,2,3};
    int i;
    for(i = 0; i < 3; i++)
    {
        listaActores[i].codigo = codigoAux[i];
        strcpy(listaActores[i].nombre, nombreAux[i]);
        strcpy(listaActores[i].apellido, apellidoAux[i]);
        listaActores[i].sexo = sexo[i];
        listaActores[i].estado = OCUPADO;
        listaActores[i].idPais = idPaisAux[i];
    }

}

void paisesElegir(ePais listaPaises[], int tam)
{
    char aux[][50] = {"Argentina","EEUU","Brazil","Espania"};
    int idaux[] = {1,2,3,4};

    int i;
    for(i = 0; i< tam; i++)
    {
        strcpy(listaPaises[i].descripcion, aux[i]);
        listaPaises[i].id = idaux[i];
    }
}

void mostrarPaises(ePais listaPaises[],int tam)
{
    printf("Pais\t\tID\n");
    int i;
    for(i = 0; i< tam; i++)
    {
        printf("%d\t\t",listaPaises[i].id);
        printf("%s\t\t\n",listaPaises[i].descripcion);
    }

}
