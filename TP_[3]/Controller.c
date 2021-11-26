#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "B.h"
#define TAM 20

#define REINTENTOS 3

int controller_loadTextId(char* path, char* cadena)
{
	int rtn = -1;
	FILE*pFile;

	if (path != NULL)
	{
		pFile = fopen(path, "r");

		fgets(cadena, TAM, pFile);

		fclose(pFile);
		rtn = 0;

	}

	return rtn;
}
int controller_saveTextId(char* path, int idmaximo)
{
	int rtn = -1;
	FILE*idArchivo;
	if (path != NULL)
	{
		idArchivo = fopen(path, "w");
		fprintf(idArchivo, "%d", idmaximo);
		fclose(idArchivo);
		rtn = 0;
	}
	return rtn;
}
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
	pFile = fopen(path, "r");

	if (pFile != NULL && pArrayListEmployee != NULL)
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

	FILE*pFile = fopen(path, "rb");

	if (pFile != NULL)
	{

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

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	char id[TAM];
	char nombre[TAM];
	char horasTrabajadas[TAM];
	char sueldo[TAM];
	int intId;

	if (pArrayListEmployee != NULL)
	{

		if (getStringNombreApellido(nombre, TAM, "ingrese nombre", "error",
		REINTENTOS) != -1
						&& getStringInt(horasTrabajadas, TAM, "ingrese horas trabajadas",
										"error", REINTENTOS) != -1
						&& getStringInt(sueldo, TAM, "ingrese sueldo", "error",
						REINTENTOS) != -1
						&& autoincrementarId("archivoId.txt", &intId, id) != -1)
		{

			if (ll_add(pArrayListEmployee,
							employee_newParametros(id, nombre, horasTrabajadas, sueldo)) == 0)
			{
				controller_saveTextId("archivoId.txt", intId);
				rtn = 0;
			}

		}

	}

	return rtn;
}
int autoincrementarId(char* path, int* enteroId, char* id)
{
	int rtn = -1;
	if (path != NULL && enteroId != NULL && id != NULL)
	{
		controller_loadTextId(path, id);
		//------
		*enteroId = atoi(id) + 1;
		itoa(*enteroId, id, 10);
		//-------
		rtn = 0;
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
	char nombre[TAM];
	int horasTrabajadas;
	int sueldo;
	int tamLista;
	int idIntMax;
	char idMax[TAM];
	if (controller_loadTextId("archivoId.txt", idMax) != -1)
	{
		idIntMax = atoi(idMax);
	}
	Employee*empleadoAux = employee_new();

	if (pArrayListEmployee != NULL)
	{
		tamLista = ll_len(pArrayListEmployee);

		if (getNumero(&idAEditar, "ingrese id a editar\n", "error id", 0, idIntMax,
		REINTENTOS) != -1)
		{

			for (int i = 0; i < tamLista; i++)
			{
				empleadoAux = (Employee*) ll_get(pArrayListEmployee, i);
				rtn = employee_getId(empleadoAux, &id);

				if (rtn != -1)
				{
					if (id == idAEditar)
					{
						printOne(empleadoAux);
						int menu;
						do
						{
							if (getNumero(&menu, "1. nombre\n"
											"2. horas trabajadas\n"
											"3. sueldo\n"
											"0.salir"

							, "error ", 0, 3, REINTENTOS) == -1)
							{
								menu = 0;
							}

							switch (menu)
							{

							case 1:

								if (getString(nombre, TAM, "ingrese nombre", "Error",
								REINTENTOS) != -1
												&& employee_setNombre(empleadoAux, nombre) != -1)
								{
									printf("modificacion Exitosa\n");
								}

								break;
							case 2:

								getNumero(&horasTrabajadas, "ingrese horas trabajadas", "Error",
												1, 1000, REINTENTOS);
								if (employee_setHorasTrabajadas(empleadoAux, horasTrabajadas)
												!= -1)
								{
									printf("modificacion Exitosa\n");
								}

								break;
							case 3:
								getNumero(&sueldo, "ingrese sueldo", "Error", 1, 500000,
								REINTENTOS);
								if (employee_setSueldo(empleadoAux, sueldo) != -1)
								{
									printf("modificacion Exitosa\n");
								}

								break;

							}
						}
						while (menu != 0);

						rtn = ll_set(pArrayListEmployee, i, empleadoAux);
						break;
					}
				}
				else
				{
					free(empleadoAux);
				}
			}
		}
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
	int rtn = -1;

	char seguir;
	int id = 0;
	int tamLista;
	int idABorrar;
	int idIntMax;
	char idMax[TAM];
	if (controller_loadTextId("archivoId.txt", idMax) != -1)
	{
		idIntMax = atoi(idMax);
	}

	if (pArrayListEmployee != NULL)
	{
		Employee*auxEmpleado;
		tamLista = ll_len(pArrayListEmployee);
		if (getNumero(&idABorrar, "ingrese id a eliminar", "error id", 0, idIntMax,
		REINTENTOS) != -1)
		{
			for (int i = 0; i < tamLista; i++)
			{

				auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
				rtn = employee_getId(auxEmpleado, &id);

				if (id == idABorrar)
				{
					printOne(auxEmpleado);
					if (getString(&seguir, 20, "\nConfima borrado s/n: ", "error \n",
					REINTENTOS) != -1)
					{

						if (seguir == 'n')
						{
							printf("Baja cancelada\n\n");
						}
						else

						{

							ll_remove(pArrayListEmployee, i);
							employee_delete(auxEmpleado);

						}
					}
					break;
				}
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

		printf("Id    Nombre       Hs.Trab.  Sueldo\n\n");
		for (int i = 0; i < len; i++)
		{

			Aux = (Employee*) ll_get(pArrayListEmployee, i);

			printOne(Aux);

		}
		rtn = 0;
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
	int rtn = -1;
	int menu;
	if (pArrayListEmployee != NULL
					&& getNumero(&menu, "1. ordenarId menor a mayor \n"
									"2. ordenarId mayor a menor\n"
									"3. ordenar por Nombre a-z\n"
									"4. ordenar por Nombre z-a\n"
									"5. ordenar por horas trabajadas menor a mayor\n"
									"6. ordenar por horas trabajadas mayor a menor\n"
									"7. ordenar por sueldo  menor a mayor  \n"
									"8. ordenar por sueldo mayor a menor \n"
									"0.salir"

					, "error\n ", 0, 8, REINTENTOS) != -1)
	{

		switch (menu)
		{
		case 1:

			ll_sort(pArrayListEmployee, employee_comparebyId, 1);
			controller_ListEmployee(pArrayListEmployee);
			break;
		case 2:
			ll_sort(pArrayListEmployee, employee_comparebyId, 0);
			controller_ListEmployee(pArrayListEmployee);

			break;
		case 3:
			ll_sort(pArrayListEmployee, employee_comparebyname, 1);
			controller_ListEmployee(pArrayListEmployee);

			break;
		case 4:
			ll_sort(pArrayListEmployee, employee_comparebyname, 0);
			controller_ListEmployee(pArrayListEmployee);

			break;
		case 5:
			ll_sort(pArrayListEmployee, employee_comparebyHorasTrabajadas, 1);
			controller_ListEmployee(pArrayListEmployee);
			break;
		case 6:
			ll_sort(pArrayListEmployee, employee_comparebyHorasTrabajadas, 0);
			controller_ListEmployee(pArrayListEmployee);
			break;
		case 7:
			ll_sort(pArrayListEmployee, employee_comparebySueldo, 1);
			controller_ListEmployee(pArrayListEmployee);
			break;
		case 8:
			ll_sort(pArrayListEmployee, employee_comparebySueldo, 0);
			controller_ListEmployee(pArrayListEmployee);
			break;
		}
	}
	else
	{
		printf("No hay datos\n");
	}

	return rtn;
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
	int rtn = -1;
	int tamLista;
	int id;
	char nombre[TAM];
	int horasTrabajadas;
	int sueldo;

	if (path != NULL && pArrayListEmployee != NULL)
	{

		tamLista = ll_len(pArrayListEmployee);

		FILE*pFile = fopen(path, "w");

		if (pFile != NULL)
		{

			Employee*pEmployee = employee_new();
			fprintf(pFile, "%s,%s,%s,%s\n", "id", "nombre", "horas", "sueldo");
			for (int i = 0; i < tamLista; i++)
			{
				pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
				if (employee_getId(pEmployee, &id) != -1
								&& employee_getNombre(pEmployee, nombre) != -1
								&& employee_getHorasTrabajadas(pEmployee, &horasTrabajadas)
												!= -1 && employee_getSueldo(pEmployee, &sueldo) != -1)
				{
					fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo); //Se escribe al archivo
				}

			}
			rtn = 0;
			fclose(pFile);
		}

	}

	return rtn;
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
	int rtn = -1;

	FILE*pFile;
	pFile = fopen(path, "wb");
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

