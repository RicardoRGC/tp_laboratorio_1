#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;
/// @param valor1
/// @param valor2
/// compara y ordena de a-z
/// @return 0 de la a-z mayor que 0 z-a
int employee_comparebyname(void* valor1, void* valor2);
/// @param valor1
/// @param valor2
///
/// @return si valor1 es mayor 1 , valor2 -1  y 0 iguales
int employee_comparebyId(void* valor1, void* valor2);
/// @param valor1
/// @param valor2
/// @return si valor1 es mayor 1 , valor2 -1  y 0 iguales
int employee_comparebyHorasTrabajadas(void* valor1, void* valor2);
/// @param valor1
/// @param valor2
/// @return si valor1 es mayor 1 , valor2 -1  y 0 iguales
int employee_comparebySueldo(void* valor1, void* valor2);
/// @param this
void printOne(Employee* this);


/// @return
Employee* employee_new();
/// @param idStr
/// @param nombreStr
/// @param horasTrabajadasStr
/// @param sueldo
///  agrega los parametros a un empleado y lo devuelve
/// @return retorna el empleado
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
/// @param empleado
/// borra un empleado
void employee_delete(Employee* empleado);

/// @param this
/// @param id
///
/// @return falla la funcion -1 0 si es correcto.
int employee_setId(Employee* this,int id);
/// @param this
/// @param id
/// @return falla la funcion -1 0 si es correcto.
int employee_getId(Employee* this,int* id);
/// @param this
/// @param nombre
/// @return falla la funcion -1 0 si es correcto.
int employee_setNombre(Employee* this,char* nombre);
/// @param this
/// @param nombre
/// @return falla la funcion -1 0 si es correcto.
int employee_getNombre(Employee* this,char* nombre);
/// @param this
/// @param horasTrabajadas
/// @return falla la funcion -1 0 si es correcto.
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/// @param this
/// @param horasTrabajadas
/// @return falla la funcion -1 0 si es correcto.
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


/// @param this
/// @param sueldo
/// @return falla la funcion -1 0 si es correcto.
int employee_setSueldo(Employee* this,int sueldo);
/// @param this
/// @param sueldo
/// @return falla la funcion -1 0 si es correcto.
int employee_getSueldo(Employee* this,int* sueldo);



#endif // employee_H_INCLUDED
