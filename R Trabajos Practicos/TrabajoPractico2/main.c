#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "ArrayEmployees”.h"
#include "dataWereHouse.h"

#define LEN_HARCODEO 7
#define LEN_L_EMPLOYE 50
#define INICIO_ID 1000
#define LEN_SECTOR 3


void harcodeoEmployee(Employee* list,int length);

int main()
{
    Employee mainList[LEN_L_EMPLOYE];
    Sector sectores[LEN_SECTOR]= { {1,"Soporte"},{2,"Limpieza"},{3,"RRHH"} };
    Employee auxEmp;
    int idAuto = INICIO_ID;//ID autoincremental;
    int opcion;//valor de la opcion elegida
    int respuesta;//validacion "opcion"
    char confirmar;//validacion "salir"
    int continuar=0;//flag para salir
    int auxId;//var. utilizada por REMOVE_EMPLOYEE / SELEC_DATA_EMPLOYEE /opcion subMenu
    int opcionModificar;//var. utilizada por SELEC_DATA_EMPLOYEE
    int flag=0;

    initEmployees(mainList,LEN_L_EMPLOYE);

//----HARDCODEO----
    harcodeoEmployee(mainList,LEN_HARCODEO);
    idAuto+=LEN_HARCODEO;
//---FIN HARDCODEO---

    do
    {
        system("cls");
        printf("------------------MENU PRINCIPAL------------------\n\n");
        printf("1-Alta empleado\n");
        printf("2-Modificar empleado\n");
        printf("3-Baja empleado\n");
        printf("4-Informes\n");
        printf("5-Salir\n");

        printEmployees(mainList,LEN_L_EMPLOYE,sectores,LEN_SECTOR);

        respuesta=utn_getNumero(&opcion,"\nIngrese opcion: \n","Error\n",1,5,2);

        if(!respuesta)//Retorna cero ,negandolo
        {
            switch(opcion)
            {

            case 1:
                //ALTAS

                system("cls");
                printf("------------------ALTA EMPLEADO------------------\n\n");
                utn_getString(auxEmp.name,"Ingrese nombre: ","Error (Max: 50 caracteres)\n",51,-1);
                system("cls");
                printf("------------------ALTA EMPLEADO------------------\n\n");
                utn_getString(auxEmp.lastName,"Ingrese apellido: ","Error (Max: 50 caracteres)\n",51,-1);
                  system("cls");
                printf("------------------ALTA EMPLEADO------------------\n\n");
                utn_getNumeroFlotante(&auxEmp.salary,"Ingrese sueldo: $","Error (Solo digitos entre 8mil y 200mil)\n",8000,200000,-1);
                  system("cls");
                printf("------------------ALTA EMPLEADO------------------\n\n");
                listSector(sectores,LEN_SECTOR);
                utn_getNumero(&auxEmp.sector,"Ingrese sector: ","Error (Solo digitos 1, 2 o 3)",1,3,-1);

                if(addEmployee(mainList,LEN_L_EMPLOYE,idAuto,auxEmp.name,auxEmp.lastName,auxEmp.salary,auxEmp.sector))
                {
                    idAuto++;
                    printf("Se realizo la operacion con exito\n");
                    flag=1;
                }
                else
                {
                    printf("Error al cargar empleado\n");
                }
                system("pause");


                break;
            case 2:
                //MODIFICACIONES
                if(flag==1)
                {
                system("cls");
                printf("------------------MODIFICAR EMPLEADO------------------\n\n");

                if( selecDataEmployee(mainList,LEN_L_EMPLOYE,&auxId,&opcionModificar,sectores,LEN_SECTOR)!=-1 )
                {
                    if(modifyEmploye(mainList,LEN_L_EMPLOYE,auxId,opcionModificar)==0)
                    {
                        printf("Se realizo la operacion con exito\n");
                    }
                }

                system("pause");
                }
                else
                {
                    printf("Error. se debe dar de alta almenos 1 empleado\n");
                    system("pause");
                }
                break;
            case 3:
                //BAJAS
                if(flag==1)
                {
                system("cls");
                printf("------------------BAJA EMPLEADO------------------\n\n");
                printEmployees(mainList,LEN_L_EMPLOYE,sectores,LEN_SECTOR);

                utn_getNumero(&auxId,"Ingrese Id a dar de baja: ","Error id inexistente\n",1000,LEN_L_EMPLOYE+1000,-1);

                if(findEmployeeById(mainList,LEN_L_EMPLOYE,auxId)!=-1)
                {
                    removeEmployee(mainList,LEN_L_EMPLOYE,auxId);
                    printf("Se realizo la operacion con exito\n");
                }
                else
                {
                    printf("Ocurrio un error al dar de baja\n");
                }

                system("pause");
                }else{
                    printf("Error. se debe dar de alta almenos 1 empleado\n");
                    system("pause");
                }
                break;
            case 4:
                //INFORMES
                if(flag==1)
                {
                system("cls");
                printf("-------------------MENU INFORMES------------------\n\n");
                utn_getNumero(&auxId,"1-Listar Empleados (Criteros: Sector y Apellido)\n2-sueldos\n\nIngrese opcion: ","Error opcion incorrecta\n",1,2,-1);

                switch(auxId)//opcion subMenu
                {
                case 1:
                    if(utn_getNumero(&auxId,"Ordenar: \n        -acendente:  1(uno)\n        -Desendente: 0(cero)\n\nIngrese opcion: ","Error criterio inexistente\n",0,1,-1)==0)
                    {

                        sortEmployees(mainList,LEN_L_EMPLOYE,auxId);
                        if(auxId)
                        {
                            system("cls");
                            printf("----------Listado en Orden acendente---------\n\n");

                        }else
                        {
                            system("cls");
                            printf("----------Listado en Orden decendente---------\n\n");
                        }

                        printEmployees(mainList,LEN_L_EMPLOYE,sectores,LEN_SECTOR);
                    }
                    else
                    {
                        printf("Ocurrio un error al listar empleados\n");
                    }
                    break;
                case 2:
                    system("cls");
                    printf("--------------INFORME SUELDOS--------------\n");
                    calculateSalaryAverage(mainList,LEN_L_EMPLOYE);
                    break;
                }
                system("pause");
                }else{
                    printf("Error. se debe dar de alta almenos 1 empleado\n");
                    system("pause");
                }
                break;
            case 5:
                //SALIR
                utn_getCaracter(&confirmar,"Confirmar Salir. (S=Si  N=No)\n","Error Solo valido S o N \n",'N','s',2);

                if('s'==tolower(confirmar))
                {
                    continuar=1;
                }
                break;
            }
        }
    }
    while(continuar==0);

    return 0;
}



void harcodeoEmployee(Employee* list,int length)
{
    for(int i=0 ; i<length ; i++)
    {
        if(list[i].isEmpty==1)
        {
            list[i].id=id[i];
            strcpy(list[i].name,nombre[i]);
            strcpy(list[i].lastName,apellido[i]);
            list[i].salary=sueldos[i];
            list[i].sector=sectorN[i];
            list[i].isEmpty=0;
        }
    }
}


