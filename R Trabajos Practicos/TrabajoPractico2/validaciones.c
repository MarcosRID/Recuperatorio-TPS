#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"


//------------------------------------------------------------------------
//----------------------------STRING--------------------------------------
//------------------------------------------------------------------------
int utn_getString(char* pResultado,char* mensaje,char* mensajeError,int maximo,int reintentos)
{
    int todoOk=-1;
    char bufferString[maximo-1];

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && (reintentos>=0 || reintentos==-1))
    {
        do
        {
            printf("%s",mensaje);
            fflush(stdin);
            if(getString(&bufferString,sizeof(bufferString))==0 )
            {
                todoOk=0;
                strcpy(pResultado,bufferString);
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
        }
        while(0<reintentos || reintentos==-1);
    }
    return todoOk;
}
//------------------------------------------------------------------------
int getString(char* pCadena,int len)
{
    int todoOk=-1;
    char buffer[400];

    if(myGets(buffer,len)==0 && esString(buffer,len)==1)
    {
        todoOk=0;
        strcpy(pCadena,buffer);
    }
    return todoOk;
}
//------------------------------------------------------------------------
int esString(char* cadena,int len)
{
    int todoOk=0;

    if(cadena!=NULL && len>0)
    {
        for(int i=0 ; cadena[i]!='\0' ; i++)
        {
            //Si es un caracter o espacio es correcto y lo niego.
            if( !(('A'<=cadena[i] && cadena[i]<='Z') || ('a'<=cadena[i] && cadena[i]<='z') || cadena[i]== 32) )
            {
                todoOk=0;
                break;
            }
            todoOk=1;
        }
    }

    return todoOk;
}
//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
int calcularMayor(int* pResultado,int num1,int num2)
{
    int todoOk=-1;

    if(pResultado!=NULL)
    {
        if(num1==num2)
        {
            todoOk=0;
        }else
        {
            if(num1>num2)
            {
                *pResultado=num1;
                todoOk=1;
            }
            else
            {
                *pResultado=num2;
                todoOk=2;
            }
        }
    }
    return todoOk;
}
//------------------------------------------------------------------------

int myGets(char* cadena,int len)
{
    int todoOk=-1;
    fflush(stdin);
    int tam=400;
    char bufferString[tam];

    if(cadena!=NULL && len>0)
    {
        fgets(bufferString,tam,stdin);

        if(bufferString[strlen(bufferString)-1]=='\n')
        {
            bufferString[strlen(bufferString)-1]='\0';
            todoOk=todoOk+2;//queda en todoOK=1 sindo esto que cumpli el primer paso.
        }
        if(strlen(bufferString)<len)
        {
            strncpy(cadena,bufferString,len);

            if(todoOk==-1)//si no entra al pasi 1 la cadena es menor;
            {
                todoOk=0;

            }else//si queda en todoOk=0; se realizaron con exitos ambos pasos;
            {
                todoOk--;
            }
        }
    }

    return todoOk;
}
//-----------------------------------------------------------------------
int utn_getCaracter( char* pResultado,char * mensaje,char * mensajeError,char minimo,char maximo,int reintentos)
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

    if(myGets(buffer,400)==0 && esNumerica(buffer)==1)
    {
        todoOk=0;
        *pResultado=atoi(buffer);
    }
    return todoOk;
}
//------------------------------------------------------------------------
int esNumerica(char* cadena)//devuelve verdadero  o falso
{
    int todoOk=1;
    int i=0;

    if(cadena[0]=='-')
    {
        i=1;
    }
    for(/*inicialice la i afuera*/; cadena[i]!='\0' ; i++)
    {

        if( ('9'<cadena[i] || cadena[i]<'0'))//busco si hay caracteres.
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

    // si es -1 pasa a ser un bucle infinito
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && (reintentos>=0 || reintentos==-1))
    {
        do
        {
            printf("%s",mensaje);

//            scanf("%d",&bufferInt);

            if(getInt(&bufferInt)==0 && minimo<=bufferInt && bufferInt<=maximo)
            {
                todoOk=0;
                *pResultado=bufferInt;
                break;
            }
            else if(reintentos==-1)
            {
                printf("%s",mensajeError);
                break;
            }
            else
            {
                printf("%s",mensajeError);
                 reintentos--;
            }
        }
        while(0<reintentos || reintentos==-1);
    }
    return todoOk;
}
//------------------------------------------------------------------------
int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{

    int todoOk=-1;
    float bufferFloat;

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && (reintentos>=0 || reintentos==-1))
    {
        do
        {
            printf("%s",mensaje);

            if(getFloat(&bufferFloat)==0 && bufferFloat>=minimo && bufferFloat<=maximo)
            {
                todoOk=0;
                *pResultado=bufferFloat;
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
int esFlotante(char* cadena)//devuelve verdadero  o falso
{
    int todoOk=-1;
    int i=0;
    int contadorPuntos=0;


    if(cadena[0]=='-' || cadena[0]=='+' )
    {
        i=1;
    }
    for(/*inicialice la i afuera*/; cadena[i]!='\0' ; i++)
    {
        if('9'<cadena[i] || cadena[i]<'0')//busco si hay caracteres.
        {
            if(cadena[i]=='.')
            {
                contadorPuntos++;

                if(contadorPuntos>1)
                {
                    todoOk=-1;
                    break;
                }
            }else
            {
                todoOk=-1;
                break;
            }
        }
        todoOk=0;
    }

    return todoOk;
}
//------------------------------------------------------------------------
int getFloat(float* pResultado)
{
    int todoOk=-1;
    char buffer[400];
    fflush(stdin);

    if(myGets(buffer,400)==0 && esFlotante(buffer)==0)
    {
        todoOk=0;
        *pResultado=atof(buffer);

    }
    return todoOk;
}
//------------------------------------------------------------------------
int imprimirNumeros(int* arrayInt,int len)
{
    int todoOk=-1;

    if(arrayInt != NULL && len>0)
    {
        for(int i=0; i< len ; i++)
        {
            printf("indice: %d  valor:%d\n",i,arrayInt[i]);
        }
        todoOk=0;
    }
    return todoOk;
}
//------------------------------------------------------------------------
int cargarArrayInt(int* arrayInt,int len)
{
    int todoOk=-1;

    if(arrayInt != NULL)
    {
        for(int i=0; i< len ; i++)
        {
            utn_getNumero(&arrayInt[i],"\nIngrese un numero: ","\nERROR solo numeros entre -999 y 999",-999,999,-1);
        }
        todoOk=0;
    }
    return todoOk;
}
//------------------------------------------------------------------------
int borrarInpares(int* arrayInt,int len)
{
    int todoOk=-1;

    if(arrayInt != NULL)
    {
        for(int i=0; i< len ; i++)
        {
            if(arrayInt[i] % 2 !=0)
            {
                arrayInt[i]=0;
            }
        }
        todoOk=0;
    }
    return todoOk;
}
//------------------------------------------------------------------------
int borrarPares(int* arrayInt,int len)
{
    int todoOk=-1;

    if(arrayInt != NULL)
    {
        for(int i=0; i< len ; i++)
        {
            if(arrayInt[i] % 2 ==0)
            {
                arrayInt[i]=0;
            }
        }
        todoOk=0;
    }
    return todoOk;
}
