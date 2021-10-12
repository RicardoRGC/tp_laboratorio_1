/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Gonzalez Ricardo Celso
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "B.h"
#include "ArrayEmployees.h"
#include "BValidaciones.h"
#define TamArray 4
#define TamCaracteres 50
#define TRUE 1
#define FALSE 0
#define INTENTOS 3

int main(void)
{

	setbuf(stdout, NULL);
	int opcion;
	int opcionUNO;
	int flagUNO = 1; // bandera corregir44

	Employee list[TamArray] =

	{
	{ 1, "ricardo ", "gonzalez", 100, 5, FALSE },
	{ 2, "roberto", "gntares", 100, 2, FALSE },
	{ 3, "gasmin", "babof", 100, 3, FALSE } };
	int contadorId;

	int idModificacion;
	int idBaja;
	int orden;
	contadorId = 0;

	int CargaIsEmpty;

	CargaIsEmpty = initEmployees(list, TamArray);
	if (CargaIsEmpty == 0)
	{
		printf("Buen Dia\n");
	}
	else
	{
		printf("Error en carga \n");
	}

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
				contadorId++;
				flagUNO = 1;
				revisarResulado("\nError al cargar\n", "\nCarga Exitosa\n",
								CargarEmpleado(list, TamArray, contadorId, TamCaracteres));
				break;
			case 2: //modificacion
				if (flagUNO == 0)
				{
					printf("Primero dar ALTA\n");
				}
				else
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
						if (modificarEmployee(list, TamArray, idModificacion))
						{
							printf("no pudo modifcar");
						}
						else
						{
							printf("modificacion exitosa");
						}
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

					printEmployees(list, TamArray);

					if (getNumero(&idBaja, "\n Ingrese id para baja", "\nERROR\n", 1, INT_MAX, INTENTOS) != 0)
					{
						printf("\n"
										"supero el maximo de intentos");
					}
					if (removeEmployee(list, TamArray, idBaja) != -1)
					{
						printf("baja exitosa");

					}
					else
					{
						printf("no se puedo borrar");
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
					do
					{

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
				break;

			case 5:

				break;
		}
		
	}
	while (opcion != 0);
	
	puts("RIKY"); /* prints  */
	return EXIT_SUCCESS;
}

