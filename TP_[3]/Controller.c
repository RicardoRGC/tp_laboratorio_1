#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
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
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
	int rtn = -1;

	FILE*pFile;
	pFile = fopen("data.csv", "r");

	if (pFile != NULL)
	{
		rtn = parser_EmployeeFromText(pFile, pArrayListEmployee);

	}

	return rtn;
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

	int rtn = -1;

	FILE*pFile = fopen("data.bin", "rb");

	if (pFile != NULL)
	{
		printf("entro");
		rtn = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
	}

	return rtn;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_addEmployee1(LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	char id[30];
	char nombre[30];
	char horasTrabajadas[30];
	char sueldo[30];

	if (pArrayListEmployee != NULL)
	{

		if (getStringInt(id, 30, "ingrese id", "error", REINTENTOS) != -1
						&& getStringNombreApellido(nombre, 30, "ingrese nombre", "error", REINTENTOS) != -1
						&& getStringInt(horasTrabajadas, 30, "ingrese horas trabajadas", "error", REINTENTOS)
										!= -1 && getStringInt(sueldo, 30, "ingrese sueldo", "error", REINTENTOS) != -1)
		{

			ll_add(pArrayListEmployee, employee_newParametros(id, nombre, horasTrabajadas, sueldo));
			rtn = 0;
		}

	}

	return rtn;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = -1;

	Employee*empleado = employee_new();
	int id;
	char nombre[30];
	int horasTrabajadas;
	int sueldo;
	if (pArrayListEmployee != NULL)
	{

		if (getNumero(&id, "ingrese id", "Error", 1, 1000, REINTENTOS) != -1
						&& employee_setId(empleado, id) != -1
						&& getString(nombre, 30, "ingrese nombre", "Error", REINTENTOS) != -1
						&& employee_setNombre(empleado, nombre) != -1
						&& getNumero(&horasTrabajadas, "ingrese horas trabajadas", "Error", 1, 1000, REINTENTOS)
										!= -1 && employee_setHorasTrabajadas(empleado, horasTrabajadas) != -1
						&& getNumero(&sueldo, "ingrese sueldo", "Error", 1, 1000,
						REINTENTOS) != -1 && employee_setSueldo(empleado, sueldo) != -1)
		{
			rtn = ll_add(pArrayListEmployee, empleado);
		}

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
	int rtn = -1;

	int id;
	int idAEditar;
	char nombre[20];
	int horasTrabajadas;
	int sueldo;
	int tamLista;

	Employee*empleadoAux = employee_new();

	if (pArrayListEmployee != NULL)
	{
		tamLista = ll_len(pArrayListEmployee);

		getNumero(&idAEditar, "ingrese id a editar", "error id", 0, 1000, REINTENTOS);

		for (int i = 0; i < tamLista; i++)
		{
			empleadoAux = (Employee*) ll_get(pArrayListEmployee, i);
			rtn = employee_getId(empleadoAux, &id);

			if (rtn != -1)
			{
				if (id == idAEditar)
				{
					mostrarUnEmpleado(empleadoAux);
					int menu;

					getNumero(&menu, "1. nombre\n"
									"2. horas trabajadas\n"
									"3. sueldo\n"
									"0.salir"

									, "error ", 0, 3, REINTENTOS);
					switch (menu)
					{

					case 1:
						getString(nombre, 30, "ingrese nombre", "Error", REINTENTOS);

												employee_setNombre(empleadoAux, nombre) ;


						break;
					case 2:
						getNumero(&horasTrabajadas, "ingrese horas trabajadas", "Error", 1, 1000, REINTENTOS);

						employee_setHorasTrabajadas(empleadoAux, horasTrabajadas) ;


						break;
					case 3:
						 getNumero(&sueldo, "ingrese sueldo", "Error", 1, 1000,REINTENTOS) ;
						 employee_setSueldo(empleadoAux, sueldo) ;


						break;


					}
					rtn = ll_set(pArrayListEmployee, i, empleadoAux);
					break;
				}
			}
		}
	}
	else
	{
		printf("No hay Datos\n\n");
	}

	return rtn;
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
	 int rtn=-1;

	    char seguir;
	    int id = 0;

	    int tamLista;
	    int idABorrar;

	    if(pArrayListEmployee != NULL)
	    {
	    	Employee*auxEmpleado;
	    	tamLista = ll_len(pArrayListEmployee);
	    	getNumero(&idABorrar, "ingrese id a eliminar", "error id", 0, 1000, REINTENTOS);

	        for(int i = 0; i < tamLista; i++)
	        {

	        	auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
	            rtn = employee_getId(auxEmpleado, &id);

	            if(id == idABorrar)
	            {
	                 mostrarUnEmpleado(auxEmpleado);

	                 printf("\nConfima borrado s/n: ");
	                 fflush(stdin);
	                 scanf("%c", &seguir);

	                 if(seguir == 'n')
	                 {
	                     printf("Baja cancelada\n\n");

	                 }
	                 else

	                 {
	                     ll_remove(pArrayListEmployee, i);
	                     printf("Borrado exitoso\n\n");

	                 }

	                break;
	            }
	        }
	     }

	    return rtn;
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
	int rtn = -1;
	int len;
	Employee*Aux;
	len = ll_len(pArrayListEmployee);

	if (pArrayListEmployee != NULL && len != 0)
	{

		printf("Id  Nombre  Hs.Trab.  Sueldo\n\n");
		for (int i = 0; i < len; i++)
		{

			Aux = (Employee*) ll_get(pArrayListEmployee, i);

			mostrarUnEmpleado(Aux);

			rtn = 0;

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
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
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
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
	int rtn;

	FILE*pFile;
	pFile = fopen(path, "w+b");
	Employee*empleado;

	int tamLista = ll_len(pArrayListEmployee);

	if (pArrayListEmployee != NULL)
	{
		if (tamLista != 0)
		{
			for (int i = 0; i < tamLista; i++)
			{
				empleado = (Employee*) ll_get(pArrayListEmployee, i);

				fwrite(empleado, sizeof(Employee), 1, pFile);
			}
			fclose(pFile);
			rtn = 0;
		}
		else
		{
			printf("No hay Archivo\n");
			system("pause");
		}
	}
	else
	{
		printf("No hay Datos\n");
	}

	return rtn;
}

