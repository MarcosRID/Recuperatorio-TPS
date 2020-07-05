#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "UTN.h"



/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menu();


int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();
    char confirmar;
    int out=1;
    int trigger=0;

    do
    {
        system("cls");
        switch( menu())
        {
        case 1:
            if(!trigger)
            {
                system("cls");
                if(controller_loadFromText("data.csv",listaEmpleados)==0)//cargo los dato en Texto
                {
                    printf("Se logro cargar los datos Formato texto\n");
                    trigger=1;
                }
                else
                {
                    printf("Se produjo un eRror al cargar los datos en Formato Texto\n");
                }
            }
            else
            {
                printf("Solo se puede cargar una vez los datos\n");
            }
            system("pause");

            break;
        case 2:
            if(!trigger)
            {
                system("cls");
                if(controller_loadFromBinary("data.bin",listaEmpleados)==0)//cargo los dato en Texto
                {
                    printf("Se logro cargar los datos Formato Bionario\n");
                    trigger=1;
                }
                else
                {
                    printf("Se produjo un eRror al cargar los datos en Formato Binario\n");
                }
            }
            else
            {
                printf("Solo se puede cargar una vez los datos\n");
            }
            system("pause");
            break;
        case 3:
            if(trigger)
            {
                system("cls");
                printf("............... Alta Empleado ............... \n\n");
                if( !(controller_addEmployee(listaEmpleados)) )
                {
                    printf("Operacion exitosa (ALTA)\n");
                }
                else
                {
                    printf("Error en la operacion (ALTA)\n");
                }
            }
            else
            {
                printf("Para acceder primero carge los datos (modo TXT o BIN)\n");
            }
            system("pause");
            break;
        case 4:
            if(trigger)
            {
                system("cls");
                printf("........... Modificar empleado ...........\n");
                if( !(controller_editEmployee(listaEmpleados)) )
                {
                    printf("Operacion Exitosa (Modificar)\n");
                }
                else
                {
                    printf("Error en la operacion (MODIFICAR)\n");
                }
            }
            else
            {
                printf("Para acceder primero carge los datos (modo TXT o BIN)\n");
            }
            system("pause");
            break;
        case 5:
            if(trigger)
            {
                system("cls");
                printf("........... Baja empleado ...........\n");
                if( !(controller_removeEmployee(listaEmpleados)) )
                {
                    printf("Operacion exitosa (BAJA) \n");
                }
                else
                {
                    printf("Error en la operacion (BAJA)\n");
                }
            }
            else
            {
                printf("Para acceder primero carge los datos (modo TXT o BIN)\n");
            }
            system("pause");
            break;
        case 6:
            if(trigger)
            {
                system("cls");
                if( !(controller_ListEmployee(listaEmpleados)) )
                {
                    printf("\n");
                }
                else
                {
                    printf("\n");
                }
            }
            else
            {
                printf("Para acceder primero carge los datos (modo TXT o BIN)\n");
            }
            system("pause");
            break;
        case 7:
            if(trigger)
            {
                system("cls");
                if( !(controller_sortEmployee(listaEmpleados)) )
                {
                    controller_ListEmployee(listaEmpleados);
                    printf("Cambios realizados con exito (Reordenamiento)\n");
                }
                else
                {
                    printf("Error al intentar ordenar\n");
                }
            }
            else
            {
                printf("Para acceder primero carge los datos (modo TXT o BIN)\n");
            }
            system("pause");
            break;
        case 8:
            if(trigger)
            {
                system("cls");
                if( !( controller_saveAsText("data.csv",listaEmpleados)) )
                {
                    printf("Operacion exitosa (Save text)\n");
                }
                else
                {
                    printf("Error. operacion (Save text)\n");
                }
            }
            else
            {
                printf("Para acceder primero carge los datos (modo TXT o BIN)\n");
            }
            system("pause");
            break;
        case 9:
            if(trigger)
            {
                system("cls");
                if( !(controller_saveAsBinary("data.bin",listaEmpleados)) )
                {
                    printf("Operacion exitosa (Save binnary)\n");
                }
                else
                {
                    printf("Error. operacion (Save binary)\n");
                }
            }
            else
            {
                printf("Para acceder primero carge los datos (modo TXT o BIN)\n");
            }
            system("pause");
            break;
        case 10:

            utn_getCaracter(&confirmar,"confirmar la baja (S=SI  N=NO)\n","Error solo letras S o N\n",'N','s',-1);

            if(tolower(confirmar)== 's')
            {
                out=0;
            }
            break;
        }
    }
    while(out);
    return 0;
}
