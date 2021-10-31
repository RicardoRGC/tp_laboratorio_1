
#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>

Employee* employee_new()
{
    Employee* empleado;
    empleado = (Employee*)malloc(sizeof(Employee));
    empleado->id = 0;
    strcpy(empleado->nombre, "");
    empleado->horasTrabajadas = 0;
    empleado->sueldo = 0;

    return empleado;
}

int employee_setId(Employee* this,int id)
{
	 int rtn=-1;


	    if( id > 0 && this != NULL)
	    {
	        this->id = id;
	        rtn=0;
	    }

	    return rtn;
}
int employee_setNombre(Employee* this,char* nombre)
{
	 int rtn=-1;

	    if( nombre > 0 && this != NULL)
	    {
	       strcpy(this->nombre,nombre);
	        rtn=0;
	    }

	    return rtn;

}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	 int rtn=-1;


	    if( horasTrabajadas > 0 && this != NULL)
	    {
	        this->horasTrabajadas = horasTrabajadas;
	        rtn=0;
	    }

	    return rtn;

}
int employee_setSueldo(Employee* this,int sueldo)
{
	 int rtn=-1;


		    if( sueldo > 0 && this != NULL)
		    {
		        this->sueldo = sueldo;
		        rtn=0;
		    }

		    return rtn;
}





