#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED


/** \brief obtiene una cadena de caracteres aceptando solo letras y espacios
 *
 * \param direccion de memoria a guardar el dato
 * \param mensaje espesificando tipo de dato y su max caracteres
 * \param mensajeError en caso de que no respete el parametro max
 * \param cantidad maxima de caracteres
 * \param cantidad de reintentos posibles; -1 en caso de ser ilimitado
 * \return -1(menos uno) error | 0 (cero) operacion con exito.
 *
 */
int utn_getString(char* pResultado,char* mensaje,char* mensajeError,int maximo,int reintentos);

/** \brief obtiene una cadena de char
 *
 * \param puntero a char (string)
 * \param longitud del string
 * \return -1(menos uno) error | 0 (cero) operacion con exito.
 *
 */
int getString(char* pCadena,int len);

/** \brief verifica que sea un string
 *
 * \param vector de char
 * \param longitud del vector
 * \return -1(menos uno) error | 0 (cero) operacion con exito.
 *
 */
int esString(char* cadena,int len);

/** \brief Calcula el mayor entre 2 numeros y devuelve el resultado por referencia
 *
 * \param Direccion de memoria donde se guardara (en el caso de que exista un mayor) el numero mayor.
 * \param valor del primero numero.
 * \param valor del segundo numero.
 * \return -1 = Error , 0 = si existe paridad , 1 = si el 1º numero es mayor , 2 = si el 2º numero es mayor
 *
 */
int calcularMayor(int* pResultado,int num1,int num2);

/** \brief Carga por referencia el con contenido de STDIN.
 *
 * \param puntero a char(se cargar lo del buffer de entrada)
 * \param tamaño limite maximo de char.
 * \return -1 ERROR ó 0 si se realizo la tarea con exito.
 *
 */
int myGets(char* cadena,int len);

/** \brief obtiene un char en un rando estimado, validando que sea char.
 *
 * \param Requiere una direccion de memoria en donde se gruardara el dato. (char)
 * \param Mensaje principal (dando una breve instruccion).
 * \param Mensaje de eRror.
 * \param Limite Minimo del caracter aceptado.
 * \param Limite Maximo del caracter aceptado.
 * \param cantidad de reintentos. Con -1 los reintentos son ilimitados.
 * \return -1 en caso de eRror ó cero (0) si realizo todo con exito.
 *
 */
 int utn_getCaracter( char * pResultado,char * mensaje,char * mensajeError,char minimo,char maximo,int reintentos);


/** \brief Obtiene un numero validando entre el rango estimado.
 *
 * \param Requiere una direccion de memoria en donde se gruardara el dato. (int)
 * \param Mensaje principal (dando una breve instruccion).
 * \param Mensaje de eRror.
 * \param Limite Minimo del numero aceptado.
 * \param Limite Maximo del numero aceptado.
 * \param cantidad de reintentos. Con -1 los reintentos son ilimitados.
 * \return -1 en caso de eRror ó cero (0) si realizo todo con exito
 *
 */
int utn_getNumero( int * pResultado,char * mensaje,char * mensajeError,int minimo,int maximo,int reintentos);

/** \brief verifica que el dato ingresado corresponda a un valor numerico en ASCII.
 *
 * \param cadena de caracteres a evaluar.
 * \return 0 (cero)= dato invalido.  1 (uno)= dato valido.
 *
 */
int esNumerica(char* cadena);

/** \brief Toma un un valor y lo combiente de char a int.
 *
 * \param Direccion de memoria en donde se guardara dicho valor.
 * \return -1 eRror ó 0 si logro realizar la operaxion con exito.
 *
 */
int getInt(int* pResultado);

/** \brief  carga un array de enteros.
 *
 * \param puntero a entero (vector/array de interos);
 * \param Tamaño del array. (parametro en entero para no sobreescribir fuera del array);
 * \return -1 Error ó 0 realizo la tarea con exito;
 *
 */
int cargarArrayInt(int* arrayInt,int len);

/** \brief Obtiene un numero flotante validando entre el rango estimado.
 *
 * \param Requiere una direccion de memoria en donde se gruardara el dato. (float)
 * \param Mensaje principal (dando una breve instruccion).
 * \param Mensaje de eRror.
 * \param Limite Minimo del numero aceptado.
 * \param Limite Maximo del numero aceptado.
 * \param cantidad de reintentos. Con -1 los reintentos son ilimitados.
 * \return -1 en caso de eRror ó cero (0) si realizo todo con exito
 *
 */
int utn_getNumeroFlotante( float * pResultado,char * mensaje,char * mensajeError,float minimo,float maximo,int reintentos);

/** \brief verifica si su equivalente en ASCII es valido para su combercion a flotante
 *
 * \param cadena char*
 * \return -1 = Error ó 0 = se logro realizar con exito.
 *
 */
int esFlotante(char* cadena);

/** \brief obtiene un string y lo combiente a flotante
 *
 * \param retorna por referencia el dato.
 * \return -1 = Error ó 0 = se logro realizar con exito.
 *
 */
int getFloat(float* pResultado);

