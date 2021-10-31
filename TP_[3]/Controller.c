#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "B.h"

#define REINTENTOS 3

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
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
	int rtn=-1;

	  Employee* empleado = employee_new();
	    int id;
	    char nombre[30];
	    int horasTrabajadas;
	    int sueldo;
	    if(pArrayListEmployee != NULL)
	       {

	    	if(getNumero(&id, "ingrese id", "Error", 1, 1000,REINTENTOS)!=-1
	    			&&  employee_setId(empleado, id)!=-1
					&& getString(nombre, 30, "ingrese nombre", "Error", REINTENTOS) !=-1
					&& employee_setNombre(empleado, nombre) !=-1
					&& getNumero(&horasTrabajadas, "ingrese horas trabajadas", "Error", 1, 1000,REINTENTOS) !=-1
					&& employee_setHorasTrabajadas(empleado, horasTrabajadas) !=-1
					&& getNumero(&sueldo, "ingrese sueldo", "Error", 1, 1000,REINTENTOS) !=-1
					&& employee_setSueldo(empleado, sueldo)!= -1)
	    	{
	    		rtn = ll_add(pArrayListEmployee, empleado);
	    	}





	       }
	       else
	       {
	           printf("No hay Datos\n\n");
	       }


    return rtn;
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
    return 1;
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
    return 1;
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
	 int rtn=-1;
	    int len;
	    Employee* Aux;
	    len = ll_len(pArrayListEmployee);

	    if(pArrayListEmployee != NULL&& len != 0)
	    {

	            printf("Id  Nombre  Hs.Trab.  Sueldo\n\n");
	            for(int i = 0; i < len; i++)
	            {
	            	Aux=(Employee*)ll_get(pArrayListEmployee, i);

	                printf("%-5d %-5s %-5d %d \n",Aux->id,Aux->nombre,Aux->horasTrabajadas,Aux->sueldo);

	                rtn =0;

	            }


	    }
	    return rtn;
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
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

