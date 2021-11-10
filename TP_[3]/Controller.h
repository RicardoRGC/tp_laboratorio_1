
#include "B.h"
#include "Employee.h"
#include "parser.h"
/// @param path archivo
/// @param enteroId entero
/// @param id char
///  pasa a entero el id lo incrementa y  lo guarda en el archivo.
/// @return falla la funcion -1 0 si es correcto.
int autoincrementarId(char* path , int* enteroId,char* id);
/// @param path archivo
/// @param idmaximo id a guardar
///
/// @return falla la funcion -1 0 si es correcto.
int controller_saveTextId(char* path,int idmaximo);

/// carga los datos del id
/// @param path archivo
/// @param cadena dato del archivo
///
/// @return falla la funcion -1 0 si es correcto.
int controller_loadTextId(char* path,char* cadena);
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int falla la funcion -1 0 si es correcto.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int falla la funcion -1 0 si es correcto.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int falla la funcion -1 0 si es correcto.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int falla la funcion -1 0 si es correcto.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int falla la funcion -1 0 si es correcto.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int falla la funcion -1 0 si es correcto.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int falla la funcion -1 0 si es correcto.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int falla la funcion -1 0 si es correcto.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int falla la funcion -1 0 si es correcto.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


