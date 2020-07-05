#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "ArrayEmployees”.h"



void listSector(Sector* listS,int length)
{
    if(length>0)
    {
        printf("ID Sector\n");
        for(int i=0 ; i<length ; i++)
        {
            printf("%d %s\n",listS[i].id,listS[i].descripcion);
        }
    }
}
void loadSector(char* desc,int id,Sector* listS,int length)
{
    if(length>0)
    {
        for(int i=0 ; i<length ; i++)
        {//printf("%d\n",i);
            if(listS[i].id==id)
            {
                strcpy(desc,listS[i].descripcion);
                break;
            }
        }
    }
}

int calculateSalaryAverage(Employee* list,int length)
{
    int todoOk=-1;
    float accumulater=0;
    int accountant=0;
    float average;
    int cantEmp=0;

    if(length>0)
    {
        for(int i=0 ; i<length ; i++)
        {
            if(list[i].isEmpty==0)
            {
                accumulater+=list[i].salary;
                accountant++;
                todoOk=0;
            }
        }

        average=accumulater/accountant;
    }

    for(int i=0 ; i<length ; i++)
    {
        if(list[i].salary>average)
        {
            cantEmp++;
        }
    }

    printf("Total sueldos: %.2f\n",accumulater);
    printf("Promero sueldo: %.2f\n",average);
    printf("Empleados que superan la media: %d\n",cantEmp);

    return todoOk;
}

int initEmployees(Employee* list, int len)
{
    int todoOk=-1;
    if(len>0)
    {
        for(int i=0 ; i<len ; i++)
        {
            list[i].isEmpty=1;

            todoOk=0;
        }
    }
    return todoOk;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int todoOk=-1;
    int indice = findFreeFirstSpace(list,len);

    if(len>0)
    {
        strcpy(list[indice].name,name);
        strcpy(list[indice].lastName,lastName);
        list[indice].id=id;
        list[indice].salary=salary;
        list[indice].sector=sector;
        list[indice].isEmpty=0;
    }
    return todoOk;
}

int findFreeFirstSpace(Employee* list,int len)
{
    int indice=-1;

    if(len>0)
    {
        for(int i=0 ; i < len; i++ )
        {
            if(list[i].isEmpty==1)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int indice=-1;

    if(len>0)
    {

        for(int i=0; i<len ; i++)
        {
            if(list[i].isEmpty==0 && list[i].id == id)
            {
                indice=i;
            }
        }
    }
    return indice;
}

int removeEmployee(Employee* list, int len, int id)
{
    int todoOk=-1;

    if(len>0)
    {
        for(int i=0 ; i<len ; i++)
        {
            if(list[i].isEmpty==0 && list[i].id==id)
            {
                list[i].isEmpty=1;
                todoOk=0;
                break;
            }
        }
    }

    return todoOk;
}
int sortEmployees(Employee* list, int len, int order)
{
    int todoOk=-1;
    Employee aux;

    if(len>0)
    {
        for(int i=0 ; i<len-1 ; i++)
        {
            for(int j=i+1 ; j<len ; j++)
            {
                switch(order)
                {
                case 0:
                    //Acendente
                    if(list[i].isEmpty==0 && list[j].isEmpty==0 && list[i].sector<list[j].sector)
                    {
                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                    }
                    else if(list[i].isEmpty==0 && list[j].isEmpty==0 && list[i].sector==list[j].sector && strcmp(list[i].lastName,list[j].lastName)==-1)
                    {
                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                    }
                    break;

                case 1:
                    //Desendente
                    if(list[i].isEmpty==0 && list[j].isEmpty==0 && list[i].sector>list[j].sector)
                    {
                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                    }
                    else if(list[i].isEmpty==0 && list[j].isEmpty==0 && list[i].sector==list[j].sector && strcmp(list[i].lastName,list[j].lastName)==1)
                    {
                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                    }

                    break;
                }
            }
        }
    }
    return todoOk;
}

int printEmployees(Employee* list, int length,Sector* listS,int lengthS)
{
    int todoOk=-1;

    if( length>0)
    {   printf("[ID]-------[Nombre]---[Apellido]-[Sueldo]--[Sector]\n");
        for(int i=0 ; i<length ; i++)
        {
            if(list[i].isEmpty==0)
            {
                printEmployee(list[i],listS,lengthS);
            }
        }
    }
    return todoOk;
}

int printEmployee(Employee element,Sector* listS,int lengthS)
{
    int todoOk=-1;
    char descripcion[20];

    loadSector(descripcion,element.sector,listS,lengthS);

    if(element.isEmpty==0)
    {
        printf("%d %13s%13s   %.2f  %s \n",element.id,element.name,element.lastName,element.salary,descripcion);
        todoOk=0;
    }
    return todoOk;
}

int selecDataEmployee(Employee* lista,int length,int* pId,int* pOption,Sector* listS,int lengthS)
{
    int todoOk=-1;
    printEmployees(lista,length,listS,lengthS);
    int auxId;
    int option;

    if((utn_getNumero(&auxId,"Ingrese ID: ","Error.ID seleccionado es inexistente\n",1000,length+1000,-1))==0 && (findEmployeeById(lista,length,auxId)!=-1))
    {
        *pId=auxId;

        system("cls");

        printf("---------Modificar campo----------\n\n");

        printf("1-Nombre\n");
        printf("2-Apellido\n");
        printf("3-Sueldo\n");
        printf("4-Sector\n");

        if( (utn_getNumero(&option,"1-Ingrese opcion: ","Error. Option seleccionado es inexistente\n",1,4,-1))==0 )
        {
            *pOption=option;
            todoOk=0;
        }
    }

    return todoOk;
}

int modifyEmploye(Employee* list,int length,int id,int option)
{
    int todoOk=-1;
    int indice=findEmployeeById(list,length,id);
    Employee auxEmp;

    switch(option)
    {
    case 1:
        if(utn_getString(auxEmp.name,"Ingrese nuevo nombre: ","Error solo caracteres (Max: 50)\n",51,-1)==0)
        {
            strcpy(list[indice].name,auxEmp.name);
            printf("Se realizo el cambio con exito\n");
            todoOk=0;
        }
        break;
    case 2:
        if(utn_getString(auxEmp.lastName,"Ingrese nuevo apellido: ","Error solo caracteres (Max: 50)\n",51,-1)==0)
        {
            strcpy(list[indice].lastName,auxEmp.lastName);
            todoOk=0;
        }
        break;
    case 3:
        if(utn_getNumeroFlotante(&auxEmp.salary,"Ingrese nuevo salario: ","Error solo digitos (entre 8mil a 200mil )\n",8000,200000,-1)==0)
        {
            list[indice].salary=auxEmp.salary;
            printf("Se reslizo el cambio con exito\n");
            todoOk=0;
        }
        break;
    case 4:
        if(utn_getNumero(&auxEmp.sector,"Ingrese nuevo sector: ","Error solo digitos(entre 1 y 3)\n",1,3,-1)==0)
        {
            list[indice].sector=auxEmp.sector;
            printf("Se reslizo el cambio con exito\n");
            todoOk=0;
        }
        break;
    }


    return todoOk;
}
