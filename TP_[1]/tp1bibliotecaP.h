/*
 * tp1bibliotecaP.h
 *
 *  Created on: 1 sep. 2021
 *      Author: gonza
 */

#ifndef TP1BIBLIOTECAP_H_
#define TP1BIBLIOTECAP_H_
#include <string.h>



/// @param flagCalculos bandera que cambia el mensaje al usuario opcion 3 realizar calculos
/// @param flagOperandoUno bandera que informa si el usuario ingreso el primer operando
/// @param flagOperandoDOSbandera que informa si el usuario ingreso el primer operando
/// @param numeroUno numero 1 flotante. al cambiar el estado de bandera muestra el valor ingresado
/// @param numeroDOS numero 2 flotane .al cambiar el estado de bandera muestra el valor ingresado
void MostrarMenu(int flagCalculos, int flagOperandoUno,int flagOperandoDOS,float numeroUno,float numeroDOS);

/// @param flotante numero a validad si es decimal o entero
/// @return retorna 0 si es decimal .
int validarDecimal(float flotante);

/// @param numero se ingresa una cadena numerica y verifica q sea un numero entero
/// @return retorna 0 si el numero no es entero 1 si lo es.
int ValidarNumeroEntero(char numero[]);

/// @param mensaje mensaje al usuario para q ingrese un numero flotante
/// @param flotante donde se guarda el numero ingresado
/// @returnretarna el numero ingresado
float PedirNumeros(char mensaje[], float flotante);



#endif /* TP1BIBLIOTECAP_H_ */
