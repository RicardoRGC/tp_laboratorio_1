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
/*
 int ValidarNumero(char numero[])
 {
 int i;
 for (i = 0; i < strlen(numero); i++)
 {
 if (!(isdigit(numero[i])))
 {
 printf("\n"
 "--------------------------------------------------------------\n"
 " por favor ingrese solo numeros\n");

 }
 }

 return 1;
 }
 */
int Sumar1(float numeroUno, int numeroDos) //sumar
{
	int suma;
	suma = numeroUno + numeroDos;
	
	return suma;
}
int calcularResta(float numUNO, int numDOS)  // restar
{
	int resultadoResta;
	resultadoResta = numUNO - numDOS;
	return resultadoResta;
}

int calcularMultiplicacion(float numUNO, int numDOS)   // multiplicar
{
	int resultadoMultip;
	resultadoMultip = numUNO * numDOS;
	return resultadoMultip;
}

float calcularDiv(float numUNO, int numDOS)    // dividir
{
	float division;
	if (numDOS != 0)
	{
		division = (float) numUNO / numDOS;
	}
	else
	{
		division = 'N';
	}
	return division;
}

int calcularFactorial(float numero)    // factorial
{
	int multiplicacion;
	int i;
	i = numero - 1;
	multiplicacion = numero;
	for (; i > 1; i--)
	{
		multiplicacion = multiplicacion * i;
		
	}
	return multiplicacion;
}
void PedirNumeros(float p[])
{
	int i;
	for (i = 0; i < 2; i++)
	{
		printf("ingrese numeros:");
		scanf("%f", &p[i]);
	}
	
}
