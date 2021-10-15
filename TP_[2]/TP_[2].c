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
#define TC 50 //tamaño de cadena
#define VACIO 1
#define CARGADO 0
#define INTENTOS 3

int main(void)
{
	setbuf(stdout, NULL);

	Employee list[TamArray] =

	{
	{ 1, "Ricardo ", "gonzalez", 100, 5, CARGADO },
	{ 2, "Roberto", "perez", 100, 2, CARGADO },
	{ 3, "Soledad", "pallares", 100, 3, CARGADO } };



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
mostrarMenu( list);

	puts("RIKY"); /* prints  */
	return EXIT_SUCCESS;
}

