#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "UTN.h"



Employee* employee_new()
{
    Employee* auxEmpleado;

    auxEmpleado = (Employee*)malloc(sizeof(Employee));

    if(auxEmpleado == NULL)
    {
        printf("No se pudo conseguir memoria ( funcion Employee* employee_new() )\n");
    }
    return auxEmpleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* nuevoEmpleado;

    nuevoEmpleado=employee_new();

    if(nuevoEmpleado!=NULL)
    {
        nuevoEmpleado->id=atoi(idStr);
        strcpy(nuevoEmpleado->nombre,nombreStr);
        nuevoEmpleado->horasTrabajadas=atoi(horasTrabajadasStr);
        nuevoEmpleado->sueldo=atoi(sueldoStr);
    }
    else
    {
        free(nuevoEmpleado);
        nuevoEmpleado=NULL;
    }

    return nuevoEmpleado;
}
int employee_setId(Employee* this,int id)
{
    int todoOk=0;

    if(this!=NULL )
    {
        this->id =id;
        todoOk=1;
    }
    return todoOk;
}
int employee_getId(Employee* this,int* id)
{
    int todoOk=0;

    if(this!=NULL && id!= NULL)
    {
        *id=this->id;
        todoOk=1;
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* auxNombre)
{
    int todoOk=0;

    if(this!=NULL && auxNombre!= NULL)
    {
        strcpy(this->nombre,auxNombre);
        todoOk=1;
    }

    return todoOk;
}
int employee_getNombre(Employee* this,char* auxNombre)
{

    int todoOk=0;

    if(this!=NULL && auxNombre!= NULL)
    {
        strcpy(auxNombre,this->nombre);
        todoOk=1;
    }

    return todoOk;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk=0;

    if(this!=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        todoOk=1;
    }
    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk=0;
    if(this!=NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        todoOk=1;
    }
    return todoOk;
}
int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk=0;

    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        todoOk=1;
    }
    return todoOk;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk=0;
    if(this!=NULL && sueldo!= NULL)
    {
        *sueldo=this->sueldo;
        todoOk=1;
    }
    return todoOk;
}

int buscarEmployeeBtId(LinkedList* pArrayListEmployee,int id)
{
    int todoOk=-1;
    int auxId;
    int len=ll_len(pArrayListEmployee);
    Employee* pAuxEmp;

    if(pArrayListEmployee!=NULL )// entro si losparametros NO son nulos
    {
        for(int i=0 ; i<len ; i++)//Recorro el arrayList
        {
            pAuxEmp= (Employee*) ll_get(pArrayListEmployee,i);//obtengo cada elemento arralyList

            if(pAuxEmp!=NULL)//Verifico el que lpuntero NO sea nulo
            {
                if( (employee_getId(pAuxEmp,&auxId))==1 )//ontengo el ID del elemento actual
                {
                    if(auxId==id)// comparo IDs
                    {
                        todoOk=i;
                        break;
                    }
                }
            }
        }
    }

    return todoOk;
}

int printfEmployee(Employee* emp1)
{
    int todoOk=-1;
    Employee auxEmp;

    if(emp1 != NULL)
    {
        employee_getId(emp1,&auxEmp.id);
        employee_getNombre(emp1,auxEmp.nombre);
        employee_getHorasTrabajadas(emp1,&auxEmp.horasTrabajadas);
        employee_getSueldo(emp1,&auxEmp.sueldo);

        printf("%04d %10s  %04d  %04d\n",auxEmp.id,auxEmp.nombre,auxEmp.horasTrabajadas,auxEmp.sueldo);
        todoOk=0;
    }

    return todoOk;
}

int readNewId(int* id)
{
    int todoOk=-1;

    FILE* f = fopen("nextId.txt","rb");

    if(id!=NULL && f!=NULL)
    {
        fread(id,sizeof(int),1,f);

        todoOk=0;
        fclose(f);
    }
    else
    {
        *id=1001;
    }

    return todoOk;
}

int saveNewId(int id)
{
    int todoOk=-1;
    FILE* f = fopen("nextId.txt","wb");
    int auxId=id;
    auxId++;

    if(f!=NULL)
    {
        fwrite(&auxId,sizeof(int),1,f);
        fclose(f);
    }

    return todoOk;
}

int buscarIdMax(LinkedList* pArrayListEmployee)
{
    int idMax;
    int auxId;
    int len=ll_len(pArrayListEmployee);
    int flag=1;
    Employee* pAuxEmp;

    if(pArrayListEmployee!=NULL )// verifico si el parametro NO es nulo
    {
        for(int i=0 ; i<len ; i++)//Recorro el arrayList
        {
            pAuxEmp= (Employee*) ll_get(pArrayListEmployee,i);//obtengo cada elemento arralyList

            if(pAuxEmp!=NULL)//Verifico el que lpuntero NO sea nulo
            {
                if( (employee_getId(pAuxEmp,&auxId))==1 )//ontengo el ID del elemento actual
                {
                    if(idMax<auxId || flag==1)// comparo IDs
                    {
                        idMax=auxId;
                        flag=0;
                    }
                }
            }
        }
    }
    return idMax;
}

int sortById(void* emp1,void* emp2)
{
    int mode;
    Employee* auxEmp1=(Employee*) emp1;
    Employee* auxEmp2=(Employee*) emp2;
    int auxId1;
    int auxId2;

    employee_getId(auxEmp1,&auxId1);
    employee_getId(auxEmp2,&auxId2);

//    printf(" (id emp 1): %d ",auxId1);
//    printf(" (id emp 2): %d \n",auxId2);


    if(auxId1 == auxId2)
    {
        mode=0;
    }
    else if (auxId1 > auxId2)
    {
        mode=-1;
    }
    else if (auxId1 < auxId2)
    {
        mode=1;
    }


    return mode;
}
int sortByName(void* emp1,void* emp2)
{
    int mode=-2;
    Employee* auxEmp1=(Employee*) emp1;
    Employee* auxEmp2=(Employee*) emp2;
    char name1[50];
    char name2[50];

    employee_getNombre(auxEmp1,name1);
    employee_getNombre(auxEmp2,name2);

    if(emp1!=NULL && emp2!=NULL)
    {
        if(strcmp(name1,name2)==0)
        {
            mode=0;
        }
        else if (strcmp(name1,name2)==-1)
        {
            mode=-1;
        }
        else if (strcmp(name1,name2)==1)
        {
            mode=1;
        }
    }
    else
    {
        printf("Error. alguno de los elementos es nulo\n");
    }
    return mode;
}
int sortByHsTrabajo(void* emp1,void* emp2)
{
    int mode;
    Employee* auxEmp1=(Employee*) emp1;
    Employee* auxEmp2=(Employee*) emp2;
    int auxHsTrabajo1;
    int auxHsTrabajo2;

    employee_getHorasTrabajadas(auxEmp1,&auxHsTrabajo1);
    employee_getHorasTrabajadas(auxEmp2,&auxHsTrabajo2);


    if(emp1!=NULL && emp2!=NULL)
    {
        if(auxHsTrabajo1 == auxHsTrabajo2)
        {
            mode=0;
        }
        else if (auxHsTrabajo1 > auxHsTrabajo2)
        {
            mode=-1;
        }
        else if (auxHsTrabajo1 < auxHsTrabajo2)
        {
            mode=1;
        }
    }
    else
    {
        printf("Error. alguno de los elementos es nulo\n");
    }
    return mode;
}
int sortBySuledo(void* emp1,void* emp2)
{
    int mode=-2;
    Employee* auxEmp1=(Employee*) emp1;
    Employee* auxEmp2=(Employee*) emp2;
    int auxSueldo1;
    int auxSueldo2;

    employee_getSueldo(auxEmp1,&auxSueldo1);
    employee_getSueldo(auxEmp2,&auxSueldo2);

    if(emp1!=NULL && emp2!=NULL)
    {
        if(auxSueldo1 == auxSueldo2)
        {
            mode=0;
        }
        else if (auxSueldo1 > auxSueldo2)
        {
            mode=-1;
        }
        else if (auxSueldo1 < auxSueldo2)
        {
            mode=1;
        }
    }
    else
    {
        printf("Error. alguno de los elementos es nulo\n");
    }
    return mode;
}


int menu()
{
    int indice;

    printf(" :::::::::::::: MENU PRINCIPAL ::::::::::::::\n\n");

    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n\n");

    utn_getNumero(&indice,"Ingrese una opcion: ","Error. Opcion inexistente",1,10,-1);

    return indice;
}

