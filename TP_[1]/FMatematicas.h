/*
 * FMatematicas.h
 *
 *  Created on: 25 sep. 2021
 *      Author: riky
 */

#ifndef FMATEMATICAS_H_
#define FMATEMATICAS_H_
#include <string.h>

/// @param numeroUno primer numero a sumar
/// @param numeroDos segundo numero a sumar;
/// @return retorna la suma de numeroUno y NumeroDos
float Sumar1(float, float);

/// @param numUNO se va a restar por numDOS.
/// @param numDOS numero para restar
/// @return retorna la resta de numUNO menos numDOS
float calcularResta(float, float);

/// @param numUNO numeros a multiplicar
/// @param numDOS numeros a multiplicar
/// @return retorna resultado de multiplicacion de numUNO y numDOS
float calcularMultiplicacion(float, float);

/// @param numUNO numero al q se lo va dividir por numDOS
/// @param numDOS numero divisor
/// @return reorna la division de numUNO en numDOS
float calcularDiv(float, float);

/// @param numero a factorizar .
/// @return retorna el resultado de la factorizacion.
double calcularFactorial(float);

#endif /* FMATEMATICAS_H_ */
