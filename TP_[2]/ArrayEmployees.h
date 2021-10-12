/*
 * ArrayEmployees.h
 *
 *  Created on: 26 sep. 2021
 *      Author: riky
 */

#include "B.h"
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} Employee;
/// @param list lista a calcular promedios. se encarga de calcular el sueldo mayor al promedio
/// @param len tamaño de la lista
/// @return
int promedioSalarios(Employee* list, int len);
/// @param list lista a ordenar a-z o z-a, y sector
/// @param len tamaño de la lista
/// @param orden del ordenamiento 1 a-z , 0 z-a
/// @return -1 error , 0 correcto
int sortEmployees(Employee* list, int len, int orden);
/// @param list lista a buscar id a modifica
/// @param len tamaño de la lista
/// @param id a modifcar
/// @return -1 si es incorrecto o no se pudo modificar
int modificarEmployee(Employee* list, int len, int id);
/// @param list lista a buscar id
/// @param len tamaño de la lista
/// @param id a eliminar .
/// @return -1 error y 0 correcto
int removeEmployee(Employee* list, int len, int id);
/// @param list lista para buscar por id
/// @param len tamaño de lista
/// @param id a buscar.
/// @return retorna id encotrado y -1 error
int findEmployeeById(Employee* list, int len, int id);
/// @param lista Employee pasa la lista a cargar.
/// @param TArray tamaño total de lista Employee
/// @param contadorId contador progresivo de id Usuario
/// @param limitCarac  limite de carracter para cadenas.
/// @return retorna -1 si hay error
int CargarEmpleado(Employee lista[], int TArray, int contadorId, int limitCarac);

/// @param lista ingresa la estructura y busca un espacio libre
/// @param tam tamaño de la lista
/// @return retorna el espacio libre si lo hay, y -1 si no lo hay.
int BuscarPrimerEspacioVacio(Employee* lista, int tam);

///agregar en una lista existente de empleados los valores recibidos como parámetros
///param list employee*
///param len int
///param id int
///param name[] char
///param lastName[] char
///param salary float
///param sector int
///return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary,
				int sector);
/// @param list se pasa lista y posicion q se va mostrar al usuario.
void MostrarEmpleado(Employee list);

/// @param lista array a imprimir por pantalla
/// @param largo tamaño del array
int printEmployees(Employee* lista, int largo);

/// @param list array a inicializar en TRUE, "LISTA VACIA"
/// @param len tamaño de array
/// @return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int initEmployees(Employee* list, int len);

#endif /* ARRAYEMPLOYEES_H_ */
