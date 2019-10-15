/*(1)​ Las instancias validas son: 1​er​ Parcial (​PP​), Recuperatorio 1​er​ Parcial (​RPP​), 2​do​ Parcial (​SP​), Recuperatorio 2​do Parcial (​RSP​), Final (​FIN​) .Marque con una cruz.  (2)​ Campos a ser completados por el docente.
 Desarrollar en ANSI C: Se necesita administrar los alquileres de juegos infantiles, y para ello se deberá realizarunprogramadeacuerdoalo                    siguiente:
  ​Película:  Código  Descripción   Duración  idGenero

Género:  id  Descripción (máximo 51 caracteres)    (Accion, Terror, Romance, Suspenso)
  ​Actor:  Código (autoincremental)  Nombre (máximo 51 caracteres) ​Validar  Apellido(máximo 51 caracteres)​Validar  Sexo​ Validar
 Elenco:  Código de reparto(autoincremental)  Código de película ​Validar  Código de actor ​Validar  Valor contrato

Realizar un menú con las siguientes opciones: 1) Gestión de Actores:  A) Altas: No es necesario el ingreso de todos los actores. B) Modificar: Se ingresará el ​Código del actor ​ , permitiendo en un submenú modificar: ● Nombre ● Apellido ● Sexo
 C) Baja:   Se ingresará el ​Código de Actor ​ y se realizará una baja lógica. D) Listar: Hacer un único listado de todos los Actores ordenados por apellido y nombre.

2) Gestión de Elencos: A) Generar elenco:  ​Se dará de alta cada ocurrencia de Elenco (puede ser uno o varios actores para una película), relacionando Película – Actor, Valor de contrato. Verificar que no se repita el par película-actor. B) Listar Elencos (Con sus datos relacionados). Ordenados por Película y ante igualdad de criterio,  por actor.








NOTAS:  I. Se deberá desarrollar bibliotecas por cada entidad, las cuales contendránlasfuncionesAlta,Baja,Modificar               y Listar.  II. Las validaciones deberán estar en una biblioteca aparte.  III. El código deberá tener comentarios con la documentación de cada una de lasfuncionesyrespetarlasreglas                  de estilo de la cátedra.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Peliculas.h"
#include "validar.h"

#include "Actores.h"

#include "Elenco.h"
#define TA 10
#define TP 3
#define TG 3
#define TE 15

int main()
{
    eActor listadeActores[TA];
    ePeliculas listadePeliculas[TP];
    eGenero listaDeGeneros[TP];
    eElenco listaElencos[TE];
    initActores(listadeActores,TA);
    initElenco(listaElencos, TE);
    hardCodearDatos(listadePeliculas, TP, listaDeGeneros, TG);
    int opcion;
    do
    {
        getValidInt("1. Menu Actores\n2. Menu Elencos\n","Error Por favor Ingrese numeros Validos",0,3,&opcion);

        switch(opcion)
        {
        case 1:
            menuDeActores("1. Cargar Actor\n2. Modificar Actor\n3. Dar de baja un Actor\n4. Listar Actores\n5. volver al menu anterior\n",listadeActores, TA);
            break;
        case 2:
            menuDeElencos("1. Cargar Nuevo Elenco\n2. Mostrar Elencos\n3. Salir\n",listadeActores,TA,listadePeliculas,TP,listaDeGeneros,TG,listaElencos,TE);
            break;
        case 3:
            opcion = 3;
            break;
        }
        system("pause");
        system("cls");

    }
    while(opcion!=3);

    return 0;
}

