#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "UTN.h"
#include "parser.h"
#include <ctype.h>



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=-1;

    FILE* f = fopen(path,"r");

    if(path!=NULL && pArrayListEmployee!=NULL && f!=NULL)
    {


        if(parser_EmployeeFromText(f,pArrayListEmployee)==0)
        {
            todoOk=0;
        }
    }

    fclose(f);

    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=-1;

    FILE* f;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {

        f = fopen(path,"rb");

        if(parser_EmployeeFromBinary(f,pArrayListEmployee)==0)
        {
            todoOk=0;
        }
    }
    fclose(f);

    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=-1;
    Employee auxEmp;
    Employee* pAuxEmp;
    char datos[4][100];
    int validar[3][1];
    int saveId;

    if(pArrayListEmployee!=NULL)
    {
        // consigo id nuevo
        readNewId(&auxEmp.id);

        // slavo el is antes de cambiar su formato a char
        saveId=auxEmp.id;

        validar[0][0]=utn_getString(datos[1],"Ingrese nombre: ","Error nombre\n",50,-1);
        validar[1][0]=utn_getNumero(&auxEmp.horasTrabajadas,"Ingrese horas trabajadas: ","Error horas\n",0,10000,-1);
        validar[2][0]=utn_getNumero(&auxEmp.sueldo,"Ingrese sueldo: ","Error sueldo 8mil a 100mil\n",8000,100000,-1);

        if(validar[0][0]==1 || validar[1][0]==1 || validar[2][0]==1 )
        {
            printf("Se produjo un error en la operacion: Alta\n");
            return -1;
        }

        itoa(auxEmp.id,datos[0],10);
        itoa(auxEmp.horasTrabajadas,datos[2],10);
        itoa(auxEmp.sueldo,datos[3],10);

        pAuxEmp=employee_newParametros(datos[0],datos[1],datos[2],datos[3]);

        if((ll_add(pArrayListEmployee,pAuxEmp))==0)
        {
            //guardo y actualizo el aid en archivo
            saveNewId(saveId);

            return 0; // de no hacer esto me guardaba 2 veces el empleado
        }
    }

    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=-1;
    int idMaximo;
    char confirmar;
    int opcion;
    int auxInt;
    int indice;
    char auxNombre[20];
    Employee* pAuxEmp;

    //Busco el id maximo
    idMaximo=buscarIdMax(pArrayListEmployee);

    //Pido id del emleado a modificar
    controller_ListEmployee(pArrayListEmployee);
    utn_getNumero(&auxInt,"Ingrese id del empleado: ","Error ID inexistente\n",0,idMaximo,-1);

    //obtengo el INDICE del elemento del arrayList (si es que existe).
    indice=buscarEmployeeBtId(pArrayListEmployee,auxInt);

    if(indice!=-1)
    {
        //guardo el puntero a al estructura Eployee
        pAuxEmp=(Employee*)ll_get(pArrayListEmployee,indice);//obtengo el elemento del arrayList

        system("cls");
        printf("........... Modificar empleado ...........\n");
        //muestro el empleado y confirmo que sea el correcto a dat de baja
        printfEmployee(pAuxEmp);
        utn_getCaracter(&confirmar,"confirmar empleado a modifiar (S=SI  N=NO)\n","Error solo letras S o N\n",'N','s',-1);

        if(tolower(confirmar)=='s')
        {

            if(pArrayListEmployee!=NULL && pAuxEmp!=NULL)// verifico que parametros y el elemento a modificar No sean nulos
            {
                printf("1-nombre\n");
                printf("2-HsTrabajadas\n");
                printf("3-sueldo\n");

                utn_getNumero(&opcion,"Ingrese opcion: ","Error opcion enexistente\n",1,3,-1);

                switch(opcion)
                {
                case 1:
                    if(!(utn_getString(auxNombre,"Ingrese nuevo nombre: ","Errormax 50 caracteres\n",51,-1)))
                    {
                        if(employee_setNombre(pAuxEmp,auxNombre))
                        {
                            todoOk=0;
                        }
                    }
                    break;
                case 2:
                    if(!(utn_getNumero(&auxInt,"Ingrese nuevas horas: ","Error hs trabajo de 0 a 10.000\n",0,10000,-1)))
                    {
                        if(employee_setHorasTrabajadas(pAuxEmp,auxInt))
                        {
                            todoOk=0;
                        }
                    }
                    break;
                case 3:
                    if(!(utn_getNumero(&auxInt,"Ingrese nuevo sueldo: $","Error solo digitos (sueldo)\n",8000,100000,-1)))
                    {
                        if(employee_setSueldo(pAuxEmp,auxInt))
                        {
                            todoOk=0;
                        }
                    }
                    break;
                }
            }
        }
    }
    else
    {
        printf("El id no existe o esta dado de baja\n");
    }

    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=-1;
    int auxId;
    int idMax;
    int indice;
    char confirmar;
    Employee* auxEmp;

    if(pArrayListEmployee!=NULL)
    {
        //busco ID maximo
        idMax=buscarIdMax(pArrayListEmployee);

        //muestro lista de empleados
        controller_ListEmployee(pArrayListEmployee);

        //obtengo el id ingresado a eliminar
        utn_getNumero(&auxId,"Ingrese ID a Eliminar: ","Error Id inexistente\n",0,idMax,-1);

        //busco el indice del id de tal empleado y verificando si existe el id
        indice=buscarEmployeeBtId(pArrayListEmployee,auxId);

        if(indice!=-1)
        {
            system("cls");
            printf("........... Baja empleado ...........\n");
            auxEmp=(Employee*)ll_get(pArrayListEmployee,indice);
            printfEmployee(auxEmp);


            //remuevo el empleado del a lista
            utn_getCaracter(&confirmar,"confirmar la baja (S=SI  N=NO)\n","Error solo letras S o N\n",'N','s',-1);
            if(tolower(confirmar)=='s')
            {
                ll_remove(pArrayListEmployee,indice);
            }
            else
            {
                printf("Baja cancelada\n");
            }
            todoOk=0;
        }
        else
        {
            printf("El id es inexistente o esta dado de baja\n");
        }
    }

    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=-1;
    int len=ll_len(pArrayListEmployee);
    Employee* pAuxEmp;

    if(pArrayListEmployee!=NULL)
    {
        for(int i=0 ; i<len ; i++)
        {
            pAuxEmp = (Employee*) ll_get(pArrayListEmployee,i);

            if(pAuxEmp!=NULL)
            {
                printfEmployee(pAuxEmp);
            }
        }
    }

    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=-1;
    int opcion;
    int criterio;

    if(pArrayListEmployee!=NULL)
    {
        printf("1-ID\n");
        printf("2-Nombre\n");
        printf("3-HsTrabajadas\n");
        printf("4-Sueldo\n");

        utn_getNumero(&opcion,"Ingrese opcion: ","Error. Opcion inexistente\n",1,4,-1);
        utn_getNumero(&criterio,"\n0-Acendente \n1-Decendente\n-Ingrese Criterio: ","Error, criterio inexistente\n",0,1,-1);


        printf("Reordenando...\n");
        switch(opcion)
        {
        case 1:
            if(criterio==0)
            {
                ll_sort(pArrayListEmployee,sortById,criterio);
            }
            else
            {
                ll_sort(pArrayListEmployee,sortById,criterio);
            }
            todoOk=0;

            break;
        case 2:
            if(criterio==0)
            {
                ll_sort(pArrayListEmployee,sortByName,criterio);
            }
            else
            {
                ll_sort(pArrayListEmployee,sortByName,criterio);
            }
            todoOk=0;

            break;
        case 3:
            if(criterio==0)
            {
                ll_sort(pArrayListEmployee,sortByHsTrabajo,criterio);
            }
            else
            {
                ll_sort(pArrayListEmployee,sortByHsTrabajo,criterio);
            }
            todoOk=0;

            break;
        case 4:
            if(criterio==0)
            {
                ll_sort(pArrayListEmployee,sortBySuledo,criterio);
            }
            else
            {
                ll_sort(pArrayListEmployee,sortBySuledo,criterio);
            }
            todoOk=0;

            break;
        }

    }
    else
    {
        printf("Ocurrio un erro al cargar lista (lista =NULL)\n");
    }

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=-1;
    FILE* f = fopen(path,"w");
    Employee* pAuxEmp;

    // intente realizarlo con una matriz ,pero  de forma aleatoria los campos los trae con basura
    char auxNombre[20];
    char pasajeIdString[20];
    char pasajeHorasString[20];
    char pasajeSueldoString[20];
    int len=ll_len(pArrayListEmployee);
    char encabezado[4][20]={ "Id","Nombre","HsTrabajadas","Suledo" };

    system("pause");

    if(f!=NULL && pArrayListEmployee!=NULL  )
    {

        fprintf(f,"%s,%s,%s,%s\n",encabezado[0],encabezado[1],encabezado[2],encabezado[3]);
        printf("%s,%s,%s,%s\n",encabezado[0],encabezado[1],encabezado[2],encabezado[3]);

        for(int i=-1; i<len ; i++)
        {
            pAuxEmp=(Employee*)ll_get(pArrayListEmployee,i);

            if(pAuxEmp != NULL)
            {

                employee_getNombre(pAuxEmp,auxNombre);
                itoa(pAuxEmp->id,pasajeIdString,10);
                itoa(pAuxEmp->horasTrabajadas,pasajeHorasString,10);
                itoa(pAuxEmp->sueldo,pasajeSueldoString,10);

                fprintf(f,"%s,%s,%s,%s\n",pasajeIdString,auxNombre,pasajeHorasString,pasajeSueldoString);
                printf("%s %s %s %s\n",pasajeIdString,auxNombre,pasajeHorasString,pasajeSueldoString);
                todoOk=0;
            }
        }
    }
    free(pAuxEmp);

    fclose(f);
    return todoOk;

}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=-1;
    int len=ll_len(pArrayListEmployee);
    FILE* f = fopen(path,"wb");
    Employee* pAuxEmp;

    if(f!=NULL && pArrayListEmployee!=NULL && path!=NULL)
    {

        for(int i=-1; i<len ; i++)
        {
            pAuxEmp=(Employee*)ll_get(pArrayListEmployee,i);

            if(pAuxEmp != NULL)
            {
                fwrite(pAuxEmp,sizeof(Employee),1,f);
                todoOk=0;
            }
        }
    }

    return todoOk;
}


