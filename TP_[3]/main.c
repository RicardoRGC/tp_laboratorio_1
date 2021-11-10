#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "B.h"
#include "BValidaciones.h"

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
/// siempre tengo que usar (free) despues crear esapacio en memoria?
///LinkedList* ll_newLinkedList(void)  donde utilizar.
int main()
{
	setbuf(stdout, NULL);
	int option = 0;
	int flagArchivo = 0;
	int flagEmpleados = 0;

	LinkedList*listaEmpleados = ll_newLinkedList();
	do
	{
		if (getNumero(&option,
						"1.Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
										"2.Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
										"3.Alta Empleado\n"
										"4.Modificar Datos Empleado\n"
										"5.Baja de Empleado\n"
										"6.Listar Empleados\n"
										"7.Ordenar Empleados\n"
										"8.Guardar los datos del empleado en archivo texto\n"
										"9.Guardar los datos del empleado en archivo Binario\n"
										"10.SALIR\n", "Error opcion incorrecta", 1, 10, 3) == -1)
		{
			printf("ERROR");
		}

		switch (option)
		{
		case 1:

			if (flagArchivo == 0
							&& controller_loadFromText("data.csv", listaEmpleados) != -1)
			{
				printf("correcto\n");
				flagArchivo = 1;
			}
			else
			{
				printf("no se puedo cargar\n");
			}

			break;
		case 2:
			if (flagArchivo == 0
							&& controller_loadFromBinary("data.bin", listaEmpleados) != -1)
			{
				printf("correcto");
				flagArchivo = 1;
			}
			else
			{
				printf("no se puedo cargar");
			}

			break;
		case 3:
			if (controller_addEmployee(listaEmpleados) != -1)
			{
				printf("carga correcta\n");
				flagEmpleados = 1;
			}

			break;
		case 4:
			if ((flagEmpleados == 1 || flagArchivo == 1)
							&& controller_ListEmployee(listaEmpleados) != -1
							&& controller_editEmployee(listaEmpleados) != -1)
			{
				printf("carga correcta");
			}

			break;
		case 5:
			if ((flagEmpleados == 1 || flagArchivo == 1)
							&& controller_ListEmployee(listaEmpleados) != -1
							&& controller_removeEmployee(listaEmpleados) != -1)
			{
				printf("carga correcta");
			}

			break;
		case 6:
			if ((flagArchivo == 1 || flagEmpleados == 1)
							&& controller_ListEmployee(listaEmpleados) != -1)
			{
				printf("carga correcta\n");
			}

			break;
		case 7:
			if ((flagArchivo == 1 || flagEmpleados == 1)
							&& controller_sortEmployee(listaEmpleados) != -1)
			{
				printf("carga correcta");
			}

			break;
		case 8:
			if (flagArchivo == 1
							&& controller_saveAsText("data.csv", listaEmpleados) != -1
							&& controller_saveAsBinary("data.bin", listaEmpleados) != -1)
			{
				printf("Guardado exitoso\n");

			}
			else
			{
				printf("Error\n");
			}
			break;
		case 9:
			if (flagArchivo == 1
							&&controller_saveAsText("data.csv", listaEmpleados) != -1
							&& controller_saveAsBinary("data.bin", listaEmpleados) != -1)
			{
				printf("Guardado exitoso\n");

			}
			else
			{
				printf("Error\n");
			}

			break;
		case 10:
			if(ll_deleteLinkedList(listaEmpleados)!=-1)
			{
				printf("el programa se cerro exitosamente");
			}
			break;
    default:
    	printf("\nOpcion invalida ingrece una opcion del 1 al 10\n ");
		}
	}
	while (option != 10);
	return 0;
}

