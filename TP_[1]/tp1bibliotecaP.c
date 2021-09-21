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

int ValidarNumeroEntero(char numero[])
{
	int bandera = 1;

	int i;

	for (i = 0; i < strlen(numero); i++)
	{
		if (!(isdigit(numero[i]))) //5.55

		{

			printf("error ingrese numero entero\n");

			//	return 0;
			bandera = 0;

		}

	}

	return bandera;
}

/// @param numeroUno primer numero a sumar
/// @param numeroDos segundo numero a sumar;
/// @return retorna la suma de numeroUno y NumeroDos
float Sumar1(float numeroUno, float numeroDos) //sumar
{
	float suma;
	suma = numeroUno + numeroDos;

	return suma;
}

float calcularResta(float numUNO, float numDOS)  // restar
{
	float resultadoResta;
	resultadoResta = numUNO - numDOS;
	return resultadoResta;
}

float calcularMultiplicacion(float numUNO, float numDOS)   // multiplicar
{
	float resultadoMultip;
	resultadoMultip = numUNO * numDOS;
	return resultadoMultip;
}

float calcularDiv(float numUNO, float numDOS)    // dividir
{
	float division;
	if (numDOS != 0)
	{
		division = numUNO / numDOS;
	}
	else
	{
		division = 'N';
	}
	return division;
}
int validarDecimal(float flotante)
{
	int ent = flotante;
	int N;

	if (flotante - ent)
	{
		N = 0;
	}
	else
	{
		N = 1;
	}
	return N;
}
float calcularFactorial(float numero)    // factorial
{
	int n;
	float multiplicacion;
	int i;
	n = validarDecimal(numero);
	if (n == 0)
	{
		multiplicacion = 0;
	}
	else
	{

		i = numero - 1;
		multiplicacion = numero;
		for (; i > 1; i--)
		{
			multiplicacion = multiplicacion * i;

		}
	}

	return multiplicacion;
}

float PedirNumeros(char mensaje[], float flotante)
{

	printf(mensaje);
	scanf("%f", &flotante);
	return flotante;
}
