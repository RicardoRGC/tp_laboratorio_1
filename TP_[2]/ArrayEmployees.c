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
#define TC 50
#define VACIO 1
#define CARGADO 0
#define INTENTOS 3
int verificarLista(Employee* list, int len)
{
	int retorno;
	retorno = -1;
	for (int i = 0; i < len; i++)
	{
		if (list[i].isEmpty == CARGADO)
		{
			retorno = 0;
			break;
		}

	}

	return retorno;
}
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
		if (list[i].isEmpty == CARGADO)
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
						"Promedio salarios %.2f \n", acumSalario, promedio);
		for (int i = 0; i < len; i++)
		{
			if (promedio < list[i].salary && list[i].isEmpty == CARGADO)
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

			if (orden == 1)
			{
				if (strcmp(list[i].lastName, list[j].lastName) > 0
								|| ((strcmp(list[i].lastName, list[j].lastName) == 0)
												&& (list[j].sector < list[i].sector)))
				{
					auxiliar = list[i];
					list[i] = list[j];
					list[j] = auxiliar;
					retorno = 0;

				}
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
	char nombre[TC];
	char apellido[TC];
	float salario;
	int sector;
	int retorno = -1;
	int modifIde;
	modifIde = findEmployeeById(list, len, id);

	if (modifIde != -1 && list[modifIde].isEmpty == CARGADO)
	{
		if ((getString(apellido, sizeof(apellido), "ingrese Apellido:", "\n Error\n", INTENTOS) == 0)
						&& getString(nombre, sizeof(nombre), "ingrese Nombre", "\n Error\n", INTENTOS) == 0
						&& (getNumero(&sector, "ingrese sector: de 1 a 5", "\n Error\n", 1, 5, INTENTOS) == 0)
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

int removeEmployee(Employee* list, int len, int id)
{
	int retorno = -1;
	int remoIde;
	remoIde = findEmployeeById(list, len, id);

	if (remoIde != -1 && list[remoIde].isEmpty == CARGADO)
	{
		list[remoIde].isEmpty = VACIO;
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
		if (list[i].id == id && list[i].isEmpty==CARGADO)
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
			/*list[i].isEmpty = VACIO;
							retorno = 0;*/
			if (list[i].id > 0)
			{

			}
			else
			{
				list[i].isEmpty = VACIO;
				retorno = 0;
			}

		}
	}

	return retorno;
}
int CargarEmpleado(Employee lista[], int tam, int* contadorId, int limitCarac)
{
	int retorno = -1;
	int auxContador;
	auxContador = *contadorId;
	char nombre[limitCarac];
	char apellido[limitCarac];
	float salario;
	int sector;
	if (BuscarPrimerEspacioVacio(lista, tam) != -1)
	{
		if ((getString(apellido, limitCarac, "ingrese Apellido:", "\n Error\n", INTENTOS) == 0)
						&& getString(nombre, limitCarac, "ingrese Nombre", "\n Error\n", INTENTOS) == 0
						&& (getNumero(&sector, "ingrese sector 1 a 5:", "\n Error\n", 1, 5, INTENTOS) == 0)
						&& (getNumeroFlotante(&salario, "ingrese salario:", "\n Error\n", 1, INT_MAX, INTENTOS)
										== 0))
		{
			auxContador++;

			retorno = addEmployee(lista, tam, auxContador, nombre, apellido, salario, sector);

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
*contadorId=auxContador;
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
		list[espacioVacio].isEmpty = CARGADO;

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
		if (lista[i].isEmpty == VACIO)
		{
			espacioVacio = i;
			break;
		}
	}

	return espacioVacio;
}

void MostrarEmpleado(Employee list)
{
	printf("\n%-4d %-10s %-10s %-10.2f %-10d\n", list.id, list.lastName, list.name, list.salary,
					list.sector);
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
			if ((lista[i].isEmpty == CARGADO))
			{
				MostrarEmpleado(lista[i]);
				retorno = 0;
			}

		}
	}

	return retorno;
}
int mostrarMenu(Employee* list)
{

	int retorno = -1;

	int opcion;
	int opcionUNO;
	int flagUNO = 0; // bandera corregir
	int idModificacion;
	int idBaja;
	int orden;
	int contadorId;
	contadorId = 100;
	do
	{
		if (getNumero(&opcion, "\n1. ALTAS \n2. MODIFICAR \n3. BAJA\n4. INFORMAR \n0. Salir\n", "ERROR",
						1, 4, INTENTOS) != 0)
		{
			printf("\n"
							"supero el maximo de intentos");
			opcion = 0;

		}

		switch (opcion)
		{
			case 1:
				//contadorId++;
				flagUNO = 1;
				revisarResulado("\nError al cargar\n", "\nCarga Exitosa\n",
								CargarEmpleado(list, TamArray, &contadorId, TC));
				break;
			case 2: //modificacion
				if (flagUNO == 0)
				{
					printf("Primero dar ALTA\n");
				}
				else
				{
					if (!verificarLista(list, TamArray))
					{
						printEmployees(list, TamArray);
						if (getNumero(&idModificacion, "\n ingrese id a modificar ", "no se puedo modifcar", 1,
						INT_MAX, 3) != 0)
						{
							printf("\n"
											"supero el maximo de intentos");
						}
						else
						{
							revisarResulado("no pudo modifcar", "modificacion exitosa",
											modificarEmployee(list, TamArray, idModificacion));

						}

					}
					else
					{
						printf("\nLISTA VACIA\n");
					}
				}
				break;
			case 3: //baja
				if (flagUNO == 0)
				{
					printf("Primero dar ALTA\n");
				}
				else
				{
					if (!verificarLista(list, TamArray))
					{

						printEmployees(list, TamArray);

						if (getNumero(&idBaja, "\n Ingrese id para baja", "\nERROR\n", 1, INT_MAX, INTENTOS)
										!= 0)
						{
							printf("\n"
											"supero el maximo de intentos");
						}
						revisarResulado("\nNO SE ENCONTRO ID\n", "\nBaja Exitosa\n", removeEmployee(list, TamArray, idBaja));
					/*	if (removeEmployee(list, TamArray, idBaja) != -1)
						{
							printf("baja exitosa");

						}
						else
						{
							printf("no se puedo borrar");
						}
*/
					}
					else
					{
						printf("\nLISTA VACIA\n");
					}
				}
				break;

			case 4:
				if (flagUNO == 0)
				{
					printf("Primero dar ALTA\n");
				}
				else
				{
					if (!verificarLista(list, TamArray))
					{
					do
					{
						if (printEmployees(list, TamArray) != 0)
						{
							printf("error");
						}
						if (getNumero(&opcionUNO, "\n1.Listado Empleados ordenados Alfabeticamente \n"
										"2.Total y promedio de los salarios, y "
										"cuántos empleados superan el salario promedio \n"
										"0.Para ATRAS\n", "\n ERROR", 0, 2, INTENTOS) != 0)
						{
							printf("\n"
											"supero el maximo de intentos");
						}
						switch (opcionUNO)
						{
							case 1:
								if (printEmployees(list, TamArray) != 0)
								{
									printf("error");
								}

								if (getNumero(&orden, "\n Para ordenar\n Ingrese 1 ascendente, 0 desendente",
												"ERROR", 0, 1, INTENTOS) != 0)
								{
									printf("\n"
													"supero el maximo de intentos");
								}
								if (sortEmployees(list, TamArray, orden))
								{
									printf("error");
								}

								if (printEmployees(list, TamArray) != 0)
								{
									printf("error");
								}

								opcionUNO = 0;
								break;
							case 2:
								if (promedioSalarios(list, TamArray) == -1)
								{
									printf("ERROR");
								}

								break;
						}

					}
					while (opcionUNO != 0);
				}
					else
					{
						printf("\nLISTA VACIA\n");
					}
				}
				break;

			case 5:

				break;
		}

	}
	while (opcion != 0);

	return retorno;
}

