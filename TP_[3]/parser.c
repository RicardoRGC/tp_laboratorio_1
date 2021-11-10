#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "B.h"
#include "BValidaciones.h"
#include "Controller.h"

#define TAM 20

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee) // recorre el archivo y lo guardad en memoria dinamica heat
{


	int conteoLineaArchivo = 0;
	char idStr[TAM];
	char nombreStr[TAM];
	char horasTrabajadasStr[TAM];
	char sueldoStr[TAM];
	int rtn=-1;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "[^\n],[^\n]\n");
		while (!feof(pFile))
		{
			conteoLineaArchivo = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n] \n", idStr, nombreStr,
							horasTrabajadasStr, sueldoStr);

			if (conteoLineaArchivo == 4 && validarCadenaNumerica(idStr) && validarCadena(nombreStr)
							&& validarCadenaNumerica(horasTrabajadasStr) && validarCadenaNumerica(sueldoStr))
			{
				Employee*empleado;

				empleado = employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);

				if (empleado != NULL)
				{
// corregir
					ll_add(pArrayListEmployee, empleado);

					rtn=0;
				}

			}
		}

	}

	fclose(pFile);

	return rtn;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int rtn = -1;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		while (!feof(pFile))
		{

			{
				Employee*empleado = employee_new();

				rtn = fread(empleado, sizeof(Employee), 1, pFile);

				if (rtn == 1)
				{
					ll_add(pArrayListEmployee, empleado);
				}

			}
		}

		rtn = 0;
	}

	fclose(pFile);

	return rtn;
}
