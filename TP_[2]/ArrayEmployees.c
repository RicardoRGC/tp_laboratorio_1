/*
 * ArrayEmployees.c
 *
 *  Created on: 26 sep. 2021
 *      Author: riky
 */
#include "ArrayEmployees.h"
#include "B.h"
#include "BValidaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define TamArray 4
#define TamCaracteres 50
#define TRUE 1
#define FALSE 0
#define INTENTOS 3
int promedioSalarios(Employee* list, int len)
{
	int retorno = -1;
	int contSalario;
	float acumSalario;
	float promedio;
	int contador;
	contador = 0;

	contSalario = 0;
	acumSalario = 0;
	for (int i = 0; i < len; i++)
	{
		if (list[i].isEmpty == FALSE)
		{
			contSalario++;

			acumSalario += list[i].salary;
			retorno = 0;
		}
	}
	if (contSalario != 0)
	{

		promedio = acumSalario / contSalario;


		printf("Suma total de salarios %.2f \n"
						"Promedio salarios %.2f \n"
						, acumSalario, promedio);
		for (int i = 0; i < len; i++)
		{
			if (promedio < list[i].salary && list[i].isEmpty == FALSE)
			{
				contador++;
			}
		}
		if (contador == 0)
		{
			printf("no hay salario superiores al promedio.\n"
							"\n");
		}
		else
		{
			printf(" Salarios superiores al Promedio %d\n", contador);
		}

	}
	else
	{
		printf("no hay promedios a mostrar \n");
	}

	return retorno;
}

int sortEmployees(Employee* list, int len, int orden)
{
	int i;
	int j;
	Employee auxiliar;
	int retorno;
	retorno = -1;

	for (i = 0; i < len - 1; i++)
	{
		for (j = i + 1; j < len; j++)
		{

				if (orden == 1
								&& (strcmp(list[i].lastName, list[j].lastName) > 0
								|| ((strcmp(list[i].lastName, list[j].lastName) == 0)
																&& (list[j].sector < list[i].sector))))

				{
					auxiliar = list[i];
					list[i] = list[j];
					list[j] = auxiliar;
					retorno = 0;
				}
			else
			{
				if (strcmp(list[i].lastName, list[j].lastName) < 0
								|| ((strcmp(list[i].lastName, list[j].lastName) == 0)
												&& (list[j].sector > list[i].sector)))
				{
					auxiliar = list[i];
					list[i] = list[j];
					list[j] = auxiliar;
					retorno = 0;

				}

			}

		}
	}

	return retorno;
}

int modificarEmployee(Employee* list, int len, int id)
{
	char nombre[50];
	char apellido[50];
	float salario;
	int sector;
	int retorno = -1;
	int modifIde;
	modifIde = findEmployeeById(list, len, id);

	if (modifIde != -1 && list[modifIde].isEmpty == FALSE)
	{
		if ((getString(apellido, sizeof(apellido), "ingrese Apellido:", "\n Error\n", INTENTOS) == 0)
						&& getString(nombre, sizeof(nombre), "ingrese Nombre", "\n Error\n", INTENTOS) == 0
						&& (getNumero(&sector, "ingrese sector:", "\n Error\n", 1, 5, INTENTOS) == 0)
						&& (getNumeroFlotante(&salario, "ingrese salario:", "\n Error\n", 1, INT_MAX, INTENTOS)
										== 0))
		{
			strcpy(list[modifIde].name, nombre);
			strcpy(list[modifIde].lastName, apellido);
			list[modifIde].salary = salario;
			list[modifIde].sector = sector;
			retorno = 0;
		}
		else
		{
			printf("\n supero los intentos, No pudo cargar\n");

			}
	}


	return retorno;
}
/// @param list
/// @param len
/// @param id recibe el ide a eliminar
/// @return
int removeEmployee(Employee* list, int len, int id)
{
	int retorno = -1;
	int remoIde;
	remoIde = findEmployeeById(list, len, id);

	if (remoIde != -1 && list[remoIde].isEmpty == FALSE)
	{
		list[remoIde].isEmpty = TRUE;
		MostrarEmpleado(list[remoIde]);
		retorno = 0;
	}


	return retorno;
}

int findEmployeeById(Employee* list, int len, int id)
{
	int retorno = -1;
	
	for (int i = 0; i < len; i++)
	{
		if (list[i].id == id)
		{
			//MostrarEmpleado(list[i]);
			retorno = i;
		}

	}

	return retorno;
}


int initEmployees(Employee* list, int len)
{
	int retorno;
	retorno = -1;
	if (list != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (list[i].id > 0)
			{

			}
			else
			{
				list[i].isEmpty = TRUE;
				retorno = 0;
			}

		}
	}

	return retorno;
}
int CargarEmpleado(Employee lista[], int tam, int contadorId, int limitCarac)
{
	int retorno = -1;

	char nombre[limitCarac];
	char apellido[limitCarac];
	float salario;
	int sector;
	if (BuscarPrimerEspacioVacio(lista, tam) != -1)
	{
		if ((getString(apellido, limitCarac, "ingrese Apellido:", "\n Error\n", INTENTOS) == 0)
						&& getString(nombre, limitCarac, "ingrese Nombre", "\n Error\n", INTENTOS) == 0
						&& (getNumero(&sector, "ingrese sector:", "\n Error\n", 1, 5, INTENTOS) == 0)
						&& (getNumeroFlotante(&salario, "ingrese salario:", "\n Error\n", 1, INT_MAX, INTENTOS)
										== 0))
		{
			retorno = addEmployee(lista, tam, contadorId, nombre, apellido, salario, sector);

	}
		else
	{
			printf("\n supero los intentos, No pudo cargar\n");

	}
	}
	else
	{
		printf("lista llena");
	}
	





	return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary,
				int sector)
{
	int resultado;
	int espacioVacio;

	resultado = -1;
	espacioVacio = BuscarPrimerEspacioVacio(list, len);  //dentro de if

	if ((list != 0) && (len > 0) && (espacioVacio != -1)) // separar en 2 if..
	{
		list[espacioVacio].id = id;
		strcpy(list[espacioVacio].name, name);
		strcpy(list[espacioVacio].lastName, lastName);
		list[espacioVacio].salary = salary;
		list[espacioVacio].sector = sector;
		list[espacioVacio].isEmpty = FALSE;

		resultado = 0;
	}

	return resultado;
}

int BuscarPrimerEspacioVacio(Employee* lista, int tam)
{
	int espacioVacio;
	espacioVacio = -1;

	int i;

	for (i = 0; i < tam; i++)
	{
		if (lista[i].isEmpty == TRUE)
		{
			espacioVacio = i;
			break;
		}
	}

	return espacioVacio;
}


void MostrarEmpleado(Employee list)
{
	printf("\n%d %2s %10s %10.2f %5d\n", list.id, list.lastName, list.name, list.salary,
					list.sector
);
}
int printEmployees(Employee* lista, int largo)
{
	int retorno = -1;
	printf("                  LISTA DE EMPLEADOS\n"
					"----------------------------------------------------------\n"
					"ID   APELLIDO   NOMBRE   SUELDO   SECTOR\n"
					"-----------------------------------------------------------\n");

	if (lista != NULL && largo > 0)
	{
		for (int i = 0; i < largo; i++)
	{
			if ((lista[i].isEmpty == FALSE))
		{
			MostrarEmpleado(lista[i]);
				retorno = 0;
		}

	}
	}


	return retorno;
}

