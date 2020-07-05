#ifndef BIBLOTECA_TP1_H_INCLUDED
#define BIBLOTECA_TP1_H_INCLUDED



#endif // BIBLOTECA_TP1_H_INCLUDED

/** \brief suma 2 numeros.
 *
 * \param valor del primer numero.
 * \param valor del segundo numero.
 * \return retorna el resultado.
 *
 */
int sumar(int num1,int num2);

/** \brief resta 2 numeros.
 *
 * \param valor del primer numero.
 * \param valor del segundo numero.
 * \return retorna el resultado.
 *
 */
int restar(int num1,int num2);

/** \brief multiplica 2 numeros.
 *
 * \param valor del primer numero.
 * \param valor del segundo numero.
 * \return retorna el resultado.
 *
 */
int multiplicar(int num1,int num2);

/** \brief divide 2 numeros.
 *
 * \param valor del primer numero.
 * \param valor del segundo numero.
 * \return retorna el resultado ó -1 si el divisior es de valor cero (0).
 *
 */
int dividir(int num1,int num2);

/** \brief calcula el factorial de 1 numero
 *
 * \param valor del numero a calcular
 * \return retorna el resultado ó -1 si el valor es menor a 1.
 *
 */
int factorial(int num1);

/** \brief muestra por pantalla los resultados de cada operacion y sus variantes.
 *
 * \param resultado de la suma.
 * \param resultado de la resta.
 * \param resultado de la multiplicacion.
 * \param resultado del factorial del primer numero.
 * \param resultado del factorial del segundo numero.
 * \param resultado de la division.
 *
 */
void informarResultados(int suma,int resta,int mult,int facA,int facB,float div);

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
 * \param
 * \return
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


