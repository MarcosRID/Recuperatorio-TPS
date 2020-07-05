#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bibloteca.h"


int sumar(int num1,int num2)
{
    return num1 + num2;
}
//------------------------------------------------------------------------
int restar(int num1,int num2)
{
    return num1 - num2;
}
//------------------------------------------------------------------------
int multiplicar(int num1,int num2)
{
    return num1 * num2;
}
//------------------------------------------------------------------------
int dividir(int num1,int num2)
{
    float resultado=-1;
    if(num2!=0)
    {
        resultado=(float)num1 / num2;
    }
    return resultado;
}
//------------------------------------------------------------------------
int factorial(int num1)
{
    int resultado;
    if(num1>=1)
    {
        if(num1==1)
        {
            resultado=1;
        }
        else
        {
            resultado= num1 * factorial(num1 - 1);
        }

    }
    else
    {
        resultado=-1;
    }

    return resultado;
}
//------------------------------------------------------------------------
void informarResultados(int suma,int resta,int mult,int facA,int facB,float div)
{
    printf("Suma = %d\n",suma);
    printf("Resta = %d\n",resta);
    printf("Multiplicacion = %d\n",mult);

    if(facA!=-1)
    {
        printf("Factorial A = %d\n",facA);
    }
    else
    {
        printf("(A) No es posible calcular un factorial menor a 1\n");
    }

    if(facB!=-1)
    {
        printf("Factorial B = %d\n",facB);
    }
    else
    {
        printf("(B) No es posible calcular un factorial menor a 1\n");
    }

    if(div!=-1)
    {
        printf("Division = %f\n",div);
    }
    else
    {
        printf("No es posible dividir por cero\n");
    }
}
//------------------------------------------------------------------------
int myGets(char* cadena,int len)
{
    int todoOk=-1;
    if(cadena!=NULL)
    {
        fflush(stdin);
        fgets(cadena,len,stdin);
        cadena[strlen(cadena)-1]='\0';
        todoOk=0;
    }
    return todoOk;
}
//-----------------------------------------------------------------------
int utn_getCaracter( char * pResultado,char * mensaje,char * mensajeError,char minimo,char maximo,int reintentos)
{
    int todoOk=-1;
    char bufferChar;

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && (reintentos>=0 || reintentos==-1))
    {
        do
        {
            printf("%s",mensaje);
            fflush(stdin);
            scanf("%c",&bufferChar);

            if(minimo<=bufferChar && bufferChar<=maximo)
            {
                todoOk=0;
                *pResultado=bufferChar;
                break;
            }
            else
            {
                printf("%s",mensajeError);
            }
            if(reintentos!=-1)
            {
                reintentos--;
            }
        }while(0<reintentos || reintentos==-1);
    }
    return todoOk;
}
//------------------------------------------------------------------------
int getInt(int* pResultado)
{
    int todoOk=-1;
    char buffer[400];
    fflush(stdin);

    if((myGets(buffer,400))==-1 && (esNumerica(buffer))==1)
    {
        todoOk=0;
        *pResultado=atoi(buffer);
    }
    return todoOk;
}
//------------------------------------------------------------------------
int esNumerica(char* cadena)

    int todoOk=1;
    int i=0;

    if(cadena[0]=='-')
    {
        i=1;
    }
    for(/*inicialice la i afuera*/; cadena[i]!='\0' ; i++)
    {
        if('9'<cadena[i] || cadena[i]<'0')
        {
            todoOk=0;
            break;
        }
    }
    return todoOk;
}
//------------------------------------------------------------------------
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
    int todoOk=-1;
    int bufferInt;

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && (reintentos>=0 || reintentos==-1))// si es -1 pasa a ser un bucle infinito
    {
        do
        {
            printf("%s",mensaje);

            if(getInt(&bufferInt)==0 && minimo<=bufferInt && bufferInt<=maximo)
            {
                todoOk=0;
                *pResultado=bufferInt;
                break;
            }
            else if(reintentos==-1)
            {
                printf("%s",mensajeError);
                system("pause");
                break;
            }else
            {
                printf("%s",mensajeError);
                system("pause");
                reintentos--;
            }
        }
        while(0<reintentos || reintentos==-1);
    }
    return todoOk;
}

