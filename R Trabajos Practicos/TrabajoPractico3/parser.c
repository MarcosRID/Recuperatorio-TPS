#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "UTN.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk=-1;
    char datos[4][100];
    int cant;
    Employee* pAuxEmp;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        //BARRIDO FANTASMA PARA EL ENCABEZADO DEL LA LISTA
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",datos[0],datos[1],datos[2],datos[3]);
        printf("%s %s %s %s\n\n",datos[0],datos[1],datos[2],datos[3]);

        while( !feof(pFile))
        {
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",datos[0],datos[1],datos[2],datos[3]);

            if(cant == 4)
            {
                pAuxEmp=employee_newParametros(datos[0],datos[1],datos[2],datos[3]);

                ll_add(pArrayListEmployee,pAuxEmp);

                printf("%04d %10s %04d %04d\n",pAuxEmp->id,pAuxEmp->nombre,pAuxEmp->horasTrabajadas,pAuxEmp->sueldo);

                todoOk=0;
            }
        }
    }

    free(pAuxEmp);

    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile,LinkedList* pArrayListEmployee)
{
    int todoOk=-1;
    Employee* pAuxEmp;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        while( !feof(pFile))
        {
            //Creo un empleado vacio
            pAuxEmp=employee_new();

            if(pAuxEmp==NULL)
            {
                todoOk=-1;
                break;
            }
                //cargo el puntoro PAUXEMP con los datos leidos del archivo pFail.
           if( fread(pAuxEmp,sizeof(Employee),1,pFile)!=0)
            {
                printf("%04d %10s %04d %04d\n",pAuxEmp->id,pAuxEmp->nombre,pAuxEmp->horasTrabajadas,pAuxEmp->sueldo);
                ll_add(pArrayListEmployee,pAuxEmp);
            }

            todoOk=0;
        }
    }

    free(pAuxEmp);

    return todoOk;
}

