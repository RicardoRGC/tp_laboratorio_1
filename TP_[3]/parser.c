#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int rtn = -1;

	int conteoLineaArchivo = 0;
	char idStr[20];
	char nombreStr[20];
	char horasTrabajadasStr[20];
	char sueldoStr[20];

	if(pFile!=NULL)
	{
		fscanf(pFile,"[^\n],[^\n]\n");
	while (!feof(pFile))
	{
		conteoLineaArchivo = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n] \n", idStr, nombreStr,
						horasTrabajadasStr, sueldoStr);

		if (conteoLineaArchivo == 4)
		{
		Employee*empleado;
			/*
			empleado = employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);
			ll_add(pArrayListEmployee, empleado);*/


		    empleado= employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);

		    if(empleado!=NULL)
		    {

			ll_add(pArrayListEmployee, empleado);



		    }
			rtn = 0;
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

	if(pFile != NULL&& pArrayListEmployee!=NULL)
	{
		while (!feof(pFile))
		{

			{
				Employee* empleado = employee_new();

				rtn = fread(empleado, sizeof(Employee),1,pFile);

				if(rtn==1)
				{
					ll_add(pArrayListEmployee, empleado);

				}


			}
		}

		rtn = 0;
		printf("entro");
	}


		fclose(pFile);

		return rtn;
}
