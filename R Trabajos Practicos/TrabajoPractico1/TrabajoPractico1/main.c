#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bibloteca.h"

int main()
{
    int opcion;
    int respuesta;
    char confirmar;
    int continuar=0;
    int flag=1;
    int trigger=1;
    int x;
    int y;
    int suma;
    int resta;
    int multiplicion;
    int factorial_A;
    int factorial_B;
    float division;

    do
    {
        system("cls");
        printf("---------Calculos aritmeticos---------\n\n");


        switch(flag)
        {
        case 1:
            printf("    A=x      B=y  \n");
            break;
        case 2:
            printf("    A=%d     B=y  \n",x);
            break;
        case 3:
            printf("    A=%d     B=%d  \n",x,y);
            break;
        }
        printf("1-Calcular todas las operaciones\n");
        printf("2-Informar resultados\n");
        printf("3-Salir\n");

        if(flag==1)//se inicia con un flag en la posicion 1 para cargar la variable (X) con el primer valor
        {
            respuesta=utn_getNumero(&x,"Ingrese pirmero operador\n","Error: solo se admiten numeros (-999 a 999)\n",-999,999,-1);

            if(respuesta==0)
            {
            flag=2;//Al cambiar flag a 2, paso a pedir el segundo valor (Y)
            }
        }
        else if (flag==2)
        {
            respuesta=utn_getNumero(&y,"Ingrese segundo operadorn\n","Error: solo se admiten numeros (-999 a 999)\n",-999,999,-1);

            if(respuesta==0)
            {
            flag=3;
            }
        }
        else
        {
            respuesta=utn_getNumero(&opcion,"Ingrese opcion\n","Error (Solo numeros del 1 al 3)\n",1,3,-1);

            if(!respuesta)
            {
                switch(opcion)
                {
                case 1:
                    if(trigger==1)//Calculo aritmetico;
                    {
                        suma=sumar(x,y);
                        resta=restar(x,y);
                        multiplicion=multiplicar(x,y);
                        factorial_A=factorial(x);
                        factorial_B=factorial(y);
                        division=dividir(x,y);

                        printf("Se realizaron las operaciones con exito\n");
                        system("pause");
                        trigger++;
                    }
                    else
                    {
                        printf("Solo se puede calcular 1 vez\n");
                        system("pause");
                    }

                    break;
                case 2:
                    if(trigger==2)//Informo los resultados
                    {
                        informarResultados(suma,resta,multiplicion,factorial_A,factorial_B,division);
                        flag=1;
                        system("pause");
                        trigger--;
                    }
                    else
                    {
                        printf("Se debe calcular antes de poder informar\n");
                        system("pause");
                    }
                    break;
                case 3:
                    utn_getCaracter(&confirmar,"Confirmar Salir. (S=Si  N=No)\n","Error Solo valido S o N \n",'N','s',-1);

                    if('s'==tolower(confirmar))
                    {
                        continuar=1;
                    }
                    break;
                }
            }
        }
    }
    while(continuar==0);

    return 0;
}

