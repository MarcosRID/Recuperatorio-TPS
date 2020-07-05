#ifndef ARRAYEMPLOYEES”_H_INCLUDED
#define ARRAYEMPLOYEES”_H_INCLUDED


typedef struct
{
    float salary;
    int id;
    char name[51];
    char lastName[51];
    int sector;
    int isEmpty;

} Employee;


typedef struct
{
    int id;
    char descripcion[20];

} Sector;

#endif // ARRAYEMPLOYEES”_H_INCLUDED


/** \brief calcula el total , promedio y cantidad de empleados que superan el salario promedio.
 *
 * \param vector de tipo Employee.
 * \param longitud del vector Employee.
 * \return -1 eRror ó 0 si logro realizar la operaxion con exito.
 *
 */
int calculateSalaryAverage(Employee* list,int length);

/** \brief modifica un campo de un elemento tipo Employee.
 *
 * \param vector de tipo Employee.
 * \param longitud del vector Employee.
 * \param valor del campo ID del elemento a modificar.
 * \param numero entero correspondiente al campo [1-nombre | 2-apellido | 3-sueldo | 4-sector].
 * \return -1 eRror ó 0 si logro realizar la operaxion con exito.
 *
 */
int modifyEmploye(Employee* list,int length,int id,int option);

/** \brief toma el id y opcion del campo a modificar (funcion digada a modifyEmploye)
 *
 * \param vector de tipo Employee
 * \param longitud del vector Employee
 * \param puntero a entero (se guardara el ID)
 * \param puntero a entero (se guardara la opcion)
 * \return -1 eRror ó 0 si logro realizar la operaxion con exito.
 *
 */
int selecDataEmployee(Employee* lista,int length,int* pId,int* pOption,Sector* listS,int lengthS);

/** \brief lista los de forma acendente/desendente por sector y apellido
 *
 * \param vector de tipo Employee
 * \param longitud del vecntor Employee
 * \param entero que determina el criterio de ordenamiento [0-desendente | 1-acendente]
 * \return -1 eRror ó 0 si logro realizar la operaxion con exito.
 *
 */
void reportListSectorLastname(Employee* list,int length,int criterion);

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
 free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief Busca el primer lugar vacio/Disponible (campo isEmpty en 1) y retorna su indice.
 *
 * \param array de Employee.
 * \param tamaño del array.
 * \return -1 (uno) No se encontro lugar , indice (entero) si logro encontrar un lugar libre.
 *
 */
int findFreeFirstSpace(Employee* list,int len);

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order);

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return -1(menos uno) error | 0 (cero) operacion con exito.
*
*/
int printEmployees(Employee* list, int length,Sector* listS,int lengthS);

/** \brief imprime un solo elemento de tipo Employee
 *
 * \param valor tipo Employee
 * \param vector de tipo Sector
 * \param tamaño del vector Sector
 * \return -1(menos uno) error | 0 (cero) operacion con exito.
 *
 */
int printEmployee(Employee element,Sector* listS,int lengthS);


/** \brief lista los sectores
 *
 * \param vector tipo Sector
 * \param tamaño del vector Sector
 * \param vector de tipo Sector
 * \param tamaño del vector Sector
 * \return void
 *
 */
void listSector(Sector* listS,int length);

/** \brief Carga la descripcion de un elemento en otro vector comparando sus CAMPOS IDs
 *
 * \param vector de char donde se guardara la descripcion
 * \param iD soliciotado para comparar
 * \param vector de tipo Sector
 * \param tamaño del vector Sector
 * \return void
 *
 */
void loadSector(char* desc,int id,Sector* listS,int length);

