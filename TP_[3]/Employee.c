#include "Employee.h"
#include "BValidaciones.h"
#include "Controller.h"
#include "B.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define TAM 20
void employee_delete(Employee* empleado)
{
	free(empleado);

}
int employee_comparebyname(void* valor1, void* valor2) // respeta el prototipo que pide el sort
{
	int rtn;

	Employee*e1;
	Employee*e2;

	e1 = (Employee*) valor1; //castea
	e2 = (Employee*) valor2;

	rtn = strcmp(e1->nombre, e2->nombre); //comparo 2 cadenas a-z. el orden lo determina el sort.

	return rtn;
}
int employee_comparebyId(void* valor1, void* valor2)
{
	int rtn = 0;
	Employee*e1;
	Employee*e2;

	e1 = (Employee*) valor1; //castea
	e2 = (Employee*) valor2;

	if (e1->id > e2->id) // ordena numericamente.
	{
		rtn = 1;
	}
	else
	{
		if (e1->id < e2->id)
		{
			rtn = -1;
		}

	}
	return rtn;
}
int employee_comparebySueldo(void* valor1, void* valor2)
{
	int rtn = 0;
	Employee*e1;
	Employee*e2;

	e1 = (Employee*) valor1; //castea
	e2 = (Employee*) valor2;

	if (e1->sueldo > e2->sueldo) // ordena numericamente.
	{
		rtn = 1;
	}
	else
	{
		if (e1->sueldo < e2->sueldo)
		{
			rtn = -1;
		}

	}
	return rtn;
}
int employee_comparebyHorasTrabajadas(void* valor1, void* valor2)
{
	int rtn = 0;
	Employee*e1;
	Employee*e2;

	e1 = (Employee*) valor1; //castea
	e2 = (Employee*) valor2;

	if (e1->horasTrabajadas > e2->horasTrabajadas) // ordena numericamente.
	{
		rtn = 1;
	}
	else
	{
		if (e1->horasTrabajadas < e2->horasTrabajadas)
		{
			rtn = -1;
		}

	}
	return rtn;
}

void printOne(Employee* this)
{
	int id;
	char nombre[TAM];
	int horasTrabajadas;
	int sueldo;
	if (this != NULL)
	{
		if(employee_getId(this, &id)!=-1
						&&employee_getNombre(this, nombre) !=-1
						&&employee_getHorasTrabajadas(this, &horasTrabajadas) !=-1
						&&employee_getSueldo(this, &sueldo) !=-1)
		{
			printf("%-5d  %-5s  %-5d  %d \n", id, nombre, horasTrabajadas, sueldo);
		}

	}
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr,
				char* sueldo)
{

	Employee*empleado = employee_new();

	if (empleado==NULL
					||(employee_setId(empleado,atoi( idStr))!=0)
					||(employee_setNombre(empleado, nombreStr)!=0)
					||(employee_setHorasTrabajadas(empleado, atoi(horasTrabajadasStr))!=0)
					||(employee_setSueldo(empleado, atoi(sueldo))!=0))


	{
//delete
		employee_delete(empleado);

	}
	return empleado;
}

Employee* employee_new()
{
	Employee*empleado;
	empleado = (Employee*) malloc(sizeof(Employee));
	if (empleado!=NULL)
	{
	empleado->id = 0;
	strcpy(empleado->nombre, "");
	empleado->horasTrabajadas = 0;
	empleado->sueldo = 0;
	}

	return empleado;
}

int employee_setId(Employee* this, int id)
{
	int rtn =-1;

	if (id > 0 && this != NULL)
	{
		this->id = id;
		rtn =0;
	}

	return rtn;
}
int employee_getId(Employee* this, int* id)
{
	int rtn =-1;

	if (this != NULL && id > 0)
	{
		*id = this->id;
		rtn =0;

	}

	return rtn;
}
int employee_setNombre(Employee* this, char* nombre)
{
	int rtn =-1;

	if (nombre != NULL && this != NULL && validarCadena(nombre))
	{
		strcpy(this->nombre, nombre);
		rtn =0;
	}

	return rtn;

}
int employee_getNombre(Employee* this,char* nombre)
{
	int rtn=-1;
	if(nombre!=NULL&&this!=NULL)
	{
		strcpy( nombre,this->nombre);
    rtn = 0;
	}
	return rtn;
}
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int rtn =-1;

	if (horasTrabajadas > 0 && this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		rtn =0;
	}

	return rtn;

}
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int rtn;
	if (horasTrabajadas > 0 && this != NULL)
		{
			*horasTrabajadas=this->horasTrabajadas ;
			rtn =0;
		}

	return rtn;
}
int employee_setSueldo(Employee* this, int sueldo)
{
	int rtn =-1;

	if (sueldo > 0 && this != NULL)
	{
		this->sueldo = sueldo;
		rtn =0;
	}

	return rtn;
}
int employee_getSueldo(Employee* this, int* sueldo)
{
	int rtn =-1;
	if (sueldo > 0 && this != NULL)
	{
		*sueldo=this->sueldo;
		rtn =0;
	}

	return rtn;
}
