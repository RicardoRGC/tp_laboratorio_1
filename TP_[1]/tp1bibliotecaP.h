/*
 * tp1bibliotecaP.h
 *
 *  Created on: 1 sep. 2021
 *      Author: gonza
 */

#ifndef TP1BIBLIOTECAP_H_
#define TP1BIBLIOTECAP_H_
#include <string.h>
/// @param flotante numero a validad si es decimal o entero
/// @return retorna 0 si es decimal .
int validarDecimal(float flotante);

/// @param numero se ingresa una cadena numerica y verifica q sea un numero entero
/// @return retorna 0 si el numero no es entero
int ValidarNumeroEntero(char numero[]);

/// @param mensaje mensaje al usuario para q ingrese un numero flotante
/// @param flotante donde se guarda el numero ingresado
/// @returnretarna el numero ingresado
float PedirNumeros(char mensaje[], float flotante);

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
float calcularFactorial(float);

#endif /* TP1BIBLIOTECAP_H_ */
