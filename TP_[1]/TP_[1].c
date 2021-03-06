/*
 ============================================================================
 Name        : TP_[1].c

 Author      : Gonzalez Ricardo 1-F
 1. Ingresar 1er operando (A=x)
 2. Ingresar 2do operando (B=y)
 3. Calcular todas las operaciones
 a) Calcular la suma (A+B)
 b) Calcular la resta (A-B)
 c) Calcular la division (A/B)
 d) Calcular la multiplicacion (A*B)
 e) Calcular el factorial (A!)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tp1bibliotecaP.h"
#include "FMatematicas.h"

int main(void)
{

	setbuf(stdout, NULL);
	int opcion;
	int N;
	float sumaUno;
	float restaUno;
	float divisionUno;
	double factorizacionUno;
	double factorizacionDos;
	float multiplicacionUno;
	float numeroUno;
	float numeroDOS;
	int flagOperandoUno;
	int flagOperandoDOS;
	int flagCalculos;
	char validacion[5];

	flagCalculos = 1;
	flagOperandoUno = 1;
	flagOperandoDOS = 1;

	do
	{
		do
		{

			MostrarMenu(flagCalculos, flagOperandoUno, flagOperandoDOS, numeroUno, numeroDOS);

			scanf("%s", validacion);
			N = ValidarNumeroEntero(validacion);

		}
		while (N == 0);
		opcion = atoi(validacion);

		switch (opcion)
		{
		case 1:

			numeroUno = PedirNumeros("\n ingrese primer operando\n", numeroUno);

			flagOperandoUno = 0;
			flagCalculos = 1;

			break;

		case 2:

			if (flagOperandoUno == 1)
			{
				printf("\n" "\n" "\n"
								"por favor ingrese el primer operando para continuar"
								"\n");

				system("pause");

			}
			else
			{

				numeroDOS = PedirNumeros(" \n ingresar operando 2 \n", numeroDOS);

				flagOperandoDOS = 0;
				flagCalculos = 1;

			}

			break;
		case 3:
			if (flagOperandoUno == 1 || flagOperandoDOS == 1)
			{
				printf("\n"
								"por favor ingrese los operando para continuar\n"
								"\n");
				system("pause");

			}
			else
			{

				sumaUno = Sumar1(numeroUno, numeroDOS);  // suma.
				restaUno = calcularResta(numeroUno, numeroDOS);  // division.
				multiplicacionUno = calcularMultiplicacion(numeroUno, numeroDOS);  // multiplicacion
				divisionUno = calcularDiv(numeroUno, numeroDOS);  //division
				factorizacionUno = calcularFactorial(numeroUno); // fatorial numeroUNO
				factorizacionDos = calcularFactorial(numeroDOS); // fatorial numeroDOS
				flagCalculos = 0;

			}
			break;
		case 4:

		 MostrarMensaje( flagCalculos,  flagOperandoUno,  flagOperandoDOS,
					 numeroUno,  numeroDOS,  divisionUno,  sumaUno,
					 multiplicacionUno,  restaUno,  factorizacionUno,
					 factorizacionDos);

			break;
		case 5:
			printf("Gracias hasta luego");

			break;

		default:

			printf("\n"
							"no ingreso caracter Correcto\n"
							"\n");
			system("pause");

			break;

		}

	}
	while (opcion != 5);

	return 0;
}
