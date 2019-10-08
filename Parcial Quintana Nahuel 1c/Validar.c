#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"

float getFloat(char* message)
{
    float aux;
    printf("%s",message);
    scanf("%f",&aux);
    return aux;
}



int getInt(char* message)
{
    int aux;
    printf("%s",message);
    scanf("%d",&aux);
    return aux;
}



char getChar(char* message)
{
    char aux;
    printf("%s",message);
    fflush(stdin);
    scanf("%c",&aux);
    return aux;
}

int isNumericFloat(char str[])
{
    int i=0;
    int cantidadPuntos=0;
    while(str[i] != '\0')
    {
        if (str[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}



int isNumeric(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}


int isJustLetters(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}



int isAlfaNumeric(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}



int isTelephone(char str[])
{
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}


void getString(char message[],char input[])
{
    printf("%s",message);
    scanf ("%s", input);
}


int getStringLetters(char message[],char input[])
{
    char aux[256];
    getString(message,aux);
    if(isJustLetters(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int getStringNumbers(char message[],char input[])
{
    char aux[256];
    getString(message,aux);
    if(isNumeric(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}



int getStringNumbersFloat(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(isNumericFloat(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

void getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit,int* input)
{
    char auxStr[256];

    while(1)
    {
        while(!getStringNumbers(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;
        }

        *input = atoi(auxStr);



        if(*input < lowLimit || *input > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        break;
    }

}

void pedirFloatValidado(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit,float* input)
{
    char auxStr[256];

    while(1)
    {
        while(!getStringNumbers(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;
        }

        *input = atoi(auxStr);



        if(*input < lowLimit || *input > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        break;
    }

}
void getValidString(char requestMessage[],char errorMessage[],int lowLimit, int hiLimit, char* input)
{
    int lenString;//verifica largo

    char auxString[256];

    while(1)
    {
        if (!getStringLetters(requestMessage,auxString))
        {
            printf ("%s\n",errorMessage);
            continue;
        }

        lenString=strlen(auxString);

        if(lenString < lowLimit || lenString > hiLimit)
        {
            printf ("El caracter del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        stringToLower(auxString);
        firstToUpper(auxString);
        strcpy(input,auxString);//si cumple con todas las  normativas recien lo asigno a input
        break;
    }

}

void firstToUpper(char name[])
{
    stringToLower(name);

    name[0] = toupper(name[0]);
    int j=0;

    while(name[j]!='\0')
    {

        if(name[j]==' ')
        {
            name[j+1]= toupper (name[j+1]);

        }
        j++;
    }
}
void stringToUpper (char letters[])
{
    int i;

    for (i=0; letters[i] != '\0'; i++)
    {
        letters[i] = toupper(letters[i]);
    }
}

void stringToLower (char letters[])
{
    int i;

    for (i=0; letters[i] != '\0'; i++)
    {
        letters[i] = tolower(letters[i]);
    }
}

