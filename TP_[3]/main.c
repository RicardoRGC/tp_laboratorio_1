#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "B.h"

/****************************************************
 Menu:
 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
 3. Alta de empleado
 4. Modificar datos de empleado
 5. Baja de empleado
 6. Listar empleados
 7. Ordenar empleados
 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/

int main() {
	setbuf(stdout, NULL);
	int option = 0;

	LinkedList *listaEmpleados = ll_newLinkedList();
	do {
		if (getNumero(&option, "1.Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
				"2.Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
				"3.Alta Empleado\n"
				"4.Modificar Datos Empleado\n"
				"5.Baja de Empleado\n"
				"6.Listar Empleados\n"
				"7.Ordenar Empleados\n"
				"8.Guardar los datos del empleado en archivo texto\n"
				"9.Guardar los datos del empleado en archivo Binario\n"
				"10.SALIR\n", "Error opcion incorrecta", 1, 10, 3) == -1) {
			printf("ERROR");
		}

		switch (option) {
		case 1:
			if(controller_loadFromText("data.csv", listaEmpleados)!=-1)
			{
				printf("correcto\n");
			}

			break;
		case 2:
			if(controller_loadFromBinary("data.bin", listaEmpleados)!=-1)
			{
				printf("correcto");
			}
			else
			{
				printf("Error");
			}
			break;
		case 3:

			//controller_addEmployee(listaEmpleados);
			controller_addEmployee1(listaEmpleados);

			break;
		case 4:
			controller_ListEmployee(listaEmpleados);

			controller_editEmployee(listaEmpleados);
			break;
		case 5:
			controller_removeEmployee(listaEmpleados);
			break;
		case 6:
			controller_ListEmployee(listaEmpleados);
			break;
		case 7:
			controller_sortEmployee(listaEmpleados);
			break;
		case 8:

			break;
		case 9:
			controller_saveAsBinary("data.bin", listaEmpleados);
			break;

		}
	} while (option != 10);
	return 0;
}

