#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int buscarEmployeeBtId(LinkedList* pArrayListEmployee,int id);
int buscarIdMax(LinkedList* pArrayListEmployee);

int printfEmployee(Employee* emp1);
int sortById(void* emp1,void* emp2);
int sortByName(void* emp1,void* emp2);
int sortByHsTrabajo(void* emp1,void* emp2);
int sortBySuledo(void* emp1,void* emp2);
int saveNewId(int id);
int readNewId(int* id);

#endif // employee_H_INCLUDED

