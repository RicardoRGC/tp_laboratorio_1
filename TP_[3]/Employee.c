#include "Employee.h"
#include "BValidaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

 void mostrarUnEmpleado(Employee* this)
{
   if(this != NULL )
   {
       printf ( "%d  %s  %d  %d \n" , this->id , this->nombre , this->horasTrabajadas , this->sueldo);
   }
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr,
				char* sueldo)
{
	Employee*empleado = employee_new();

	employee_setId(empleado, atoi(idStr));
					employee_setNombre(empleado, nombreStr);
					employee_setHorasTrabajadas(empleado, atoi(horasTrabajadasStr));
					employee_setSueldo(empleado, atoi(sueldo));

					/*
					 empleado->id=atoi(idStr);
					 strcpy(empleado->nombre,nombreStr);
					 empleado->horasTrabajadas=atoi(horasTrabajadasStr);
					 empleado->sueldo=atoi(sueldo);
					 */

					return empleado;
				}

				Employee* employee_new()
				{
					Employee*empleado;
					empleado = (Employee*) malloc(sizeof(Employee));
					empleado->id = 0;
					strcpy(empleado->nombre, "");
					empleado->horasTrabajadas = 0;
					empleado->sueldo = 0;

					return empleado;
				}

				int employee_setId(Employee* this, int id)
				{
					int rtn = -1;

					if (id > 0 && this != NULL)
					{
						this->id = id;
						rtn = 0;
					}

					return rtn;
				}
				int employee_getId(Employee* this,int* id)
				{
					int rtn=-1;

					    if( this != NULL && id>0)
					    {
					        *id= this->id;
					        rtn=0;

					    }

					    return rtn;
				}
				int employee_setNombre(Employee* this, char* nombre)
				{
					int rtn = -1;

					if (nombre > 0 && this != NULL && validarCadenaEspacios(nombre))
					{
						strcpy(this->nombre, nombre);
						rtn = 0;
					}

					return rtn;

				}
				int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
				{
					int rtn = -1;

					if (horasTrabajadas > 0 && this != NULL)
					{
						this->horasTrabajadas = horasTrabajadas;
						rtn = 0;
					}

					return rtn;

				}
				int employee_setSueldo(Employee* this, int sueldo)
				{
					int rtn = -1;

					if (sueldo > 0 && this != NULL)
					{
						this->sueldo = sueldo;
						rtn = 0;
					}

					return rtn;
				}

