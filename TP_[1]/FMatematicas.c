/*
 * FMatematicas.c
 *
 *  Created on: 25 sep. 2021
 *      Author: riky
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tp1bibliotecaP.h"
#include "FMatematicas.h"

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
	if(resultadoMultip==-0)
	{
		resultadoMultip=0;
	}
	return resultadoMultip;
}

float calcularDiv(float numUNO, float numDOS)    // dividir
{
	float division;
	if (numDOS != 0)
	{
		division = numUNO / numDOS;
		if(division==-0)
		{
			division=0;
		}
	}
	else
	{
		division = 'N';
	}
	return division;
}
double calcularFactorial(float numero)    // factorial
{
	int n;
	double multiplicacion;
	int i;
	n = validarDecimal(numero);
	if (n == 0 || numero < 0)
	{
		multiplicacion = 0;

	}
	else
	{
		if (numero == 0)
		{
			multiplicacion = 1;
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

	}

	return multiplicacion;
}
