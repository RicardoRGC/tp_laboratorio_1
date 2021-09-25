/*
 * tp1blibliotecaP.c
 *
 *  Created on: 1 sep. 2021
 *      Author: gonza
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tp1bibliotecaP.h"
#include "FMatematicas.h"

void MostrarMensaje(int flagCalculos, int flagOperandoUno, int flagOperandoDOS,
		float numeroUno, float numeroDOS, float divisionUno, float sumaUno,
		float multiplicacionUno, float restaUno, float factorizacionUno,
		float factorizacionDos) {
	if (flagOperandoUno == 1 || flagOperandoDOS == 1) {
		printf("\n"
				"por favor ingrese los operando para continuar\n"
				"\n");
		system("pause");
	}

	if (flagCalculos == 1) {
		printf("\n"
				"por favor realizar calculos para continuar\n"
				"\n");
		system("pause");
	} else {
		printf("El resultado de %.2f+%.2f es: %.2f \n"
				"El resultado de %.2f-%.2f es: %.2f \n"
				"El resultado de %.2f*%.2f es: %.2f \n", numeroUno, numeroDOS,
				sumaUno, numeroUno, numeroDOS, restaUno, numeroUno, numeroDOS,
				multiplicacionUno);
		if (divisionUno == 'N') {
			printf("no se puede dividir por cero\n");
		} else {
			printf("El resultado de %.2f/%.2f es: %.2f\n", numeroUno, numeroDOS,
					divisionUno);
		}
		if (factorizacionUno == 0) {
			printf("A no se puede factorizar\n");
		} else {
			printf("El factorial de %.2f es: %.2f \n", numeroUno,
					factorizacionUno);
		}

		if (factorizacionDos == 0) {
			printf("B no se puede factorizar\n");
		} else {
			printf("El factorial de %.2f es: %.2f \n", numeroDOS,
					factorizacionDos);
		}

		//printf("El factorial de %.2f es: %.2f \n", numeroDOS, factorizacionDos);

		system("pause");
	}
}

void MostrarMenu(int flagCalculos, int flagOperandoUno, int flagOperandoDOS,
		float numeroUno, float numeroDOS) {
	if (flagOperandoUno == 1) {
		printf("\n"
				"\n"
				"\n1. Ingresar 1er operando A=x\n");

	} else {
		printf("\n"
				"\n"
				"\n"
				"1. ingresado A=%.2f\n", numeroUno);

	}
	if (flagOperandoDOS == 1) {
		printf("2. Ingresar 2do operando B=x\n");
	} else {
		printf("2. ingresado B=%.2f\n", numeroDOS);
	}

	if (flagCalculos == 1) {
		printf(
				"3. Calcular todas las operaciones  <-------------------------	\n");
	} else {
		printf("3. Calculos resueltos	\n");

	}

	printf("4. informar resultados \n");
	printf("5. SALIR: "
			"\n"
			"\n");

}
int ValidarNumeroEntero(char numero[]) {
	int bandera = 1;
	int auxstr;
	auxstr = strlen(numero);
	int i;

	if ((numero[0] == '-' && auxstr != 1) || isdigit(numero[0])) {

		for (i = 1; i < auxstr; i++) {

			if (!(isdigit(numero[i])))

			{

				printf("error ingrese numero entero\n");
				system("pause");

				bandera = 0;
				break;

			}

		}

	} else {
		printf("error ingrese numero entero\n");
		system("pause");
		bandera = 0;
	}

	return bandera;
}

int validarDecimal(float flotante) {
	int ent = flotante;
	int N;

	if (flotante - ent) {
		N = 0;
	} else {
		N = 1;
	}
	return N;
}

float PedirNumeros(char mensaje[], float flotante) {

	printf(mensaje);
	scanf("%f", &flotante);
	return flotante;
}
