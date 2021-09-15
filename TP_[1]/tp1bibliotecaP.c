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

	int i;

	for (i = 0; i < strlen(numero); i++)
	{
		if (!(isdigit(numero[i])))

		{

			printf("error ingrese numero entero\n");

			return 0;
		}
	}

	return 1;
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
/// @param numUNO se va a restar por numDOS.
/// @param numDOS numero para restar
/// @return retorna la resta de numUNO menos numDOS
float calcularResta(float numUNO, float numDOS)  // restar
{
	float resultadoResta;
	resultadoResta = numUNO - numDOS;
	return resultadoResta;
}
/// @param numUNO numeros a multiplicar
/// @param numDOS numeros a multiplicar
/// @return retorna resultado de multiplicacion de numUNO y numDOS
float calcularMultiplicacion(float numUNO, float numDOS)   // multiplicar
{
	float resultadoMultip;
	resultadoMultip = numUNO * numDOS;
	return resultadoMultip;
}
/// @param numUNO numero al q se lo va dividir por numDOS
/// @param numDOS numero divisor
/// @return reorna la division de numUNO en numDOS
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
/// @param numero a factirizar .
/// @return retorna el resultado de la factorizacion.
float calcularFactorial(float numero)    // factorial
{
	float multiplicacion;
	int i;
	i = numero - 1;
	multiplicacion = numero;
	for (; i > 1; i--)
	{
		multiplicacion = multiplicacion * i;

	}
	return multiplicacion;
}
/// @param p  se guarda el pedido al usuario
float PedirNumeros(char mensaje[], float flotante)
{

	printf(mensaje);
	scanf("%f", &flotante);
	return flotante;
}
