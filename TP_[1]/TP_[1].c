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

int main(void)
{

	setbuf(stdout, NULL);
	int opcion;
	int N;
	float sumaUno;
	float restaUno;
	float divisionUno;
	float factorizacionUno;
	float factorizacionDos;
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

			if (flagOperandoUno == 1)
			{
				printf("\n"
								"\n"
								"\n1. Ingresar 1er operando A=x\n");

			}
			else
			{
				printf("\n"
								"\n"
								"\n"
								"1. ingresado A=%.2f\n", numeroUno);

			}
			if (flagOperandoDOS == 1)
			{
				printf("2. Ingresar 2do operando B=x\n");
			}
			else
			{
				printf("2. ingresado B=%.2f\n", numeroDOS);
			}

			if (flagCalculos == 1)
			{
				printf("3. Calcular todas las operaciones	\n");
			}
			else
			{
				printf("3. Calculos resueltos	\n");

			}

			printf("4. informar resultados \n");
			printf("5. SALIR: "
							"\n"
							"\n");

			//scanf("%d", &opcion);
			scanf("%s", validacion);
			N = ValidarNumeroEntero(validacion);
			//system("pause");
			system("pause");
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
			if (flagOperandoUno == 1 || flagOperandoDOS == 1)
			{
				printf("\n"
								"por favor ingrese los operando para continuar\n"
								"\n");
				system("pause");
			}

			if (flagCalculos == 1)
			{
				printf("\n"
								"por favor realizar calculos para continuar\n"
								"\n");
				system("pause");
			}
			else
			{
				printf("El resultado de %.2f+%.2f es: %.2f \n"
								"El resultado de %.2f-%.2f es: %.2f \n"
								"El resultado de %.2f*%.2f es: %.2f \n", numeroUno, numeroDOS, sumaUno, numeroUno,
								numeroDOS, restaUno, numeroUno, numeroDOS, multiplicacionUno);
				if (divisionUno == 'N')
				{
					printf("no se puede dividir por cero\n");
				}
				else
				{
					printf("El resultado de %.2f/%.2f es: %.2f\n", numeroUno, numeroDOS, divisionUno);
				}

				printf("El factorial de %.2f es: %.2f \n"
								"y El factorial de %.2f es: %.2f \n", numeroUno, factorizacionUno, numeroDOS,
								factorizacionDos);

				system("pause");
			}

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
