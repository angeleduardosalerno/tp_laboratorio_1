#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validacionesinput.h"
#include "parser.h"

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


int main()
{
    int opciones;

    LinkedList* listaEmpleados = ll_newLinkedList(); // SE CREA UNA LISTA LINKED LIST, ASIGNANDOLE MEMORIA DINAMICAMENTE.

    do
    {
        //system("cls");
        printf ("\n ------------------------MENU PRINCIPAL-------------------------------------\n");
        printf("\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("\n 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
        printf("\n 3. Alta de empleado \n ");
        printf("\n 4. Modificar datos de empleado\n ");
        printf("\n 5. Baja de empleado \n");
        printf("\n 6. Listar empleados\n");
        printf("\n 7. Ordenar empleados\n");
        printf("\n 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n ");
        printf("\n 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n ");
        printf("\n10. Salir\n");

        utn_getNumeroAvanzada(&opciones, " \n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 10,3);

        switch (opciones)
        {
            case 1: // Cargar los datos de los empleados desde el archivo data.csv (modo texto).

                controller_loadFromText("data.csv",listaEmpleados);
                system("pause");

            break; // BREAK CASO 1

            case 2: //Cargar los datos de los empleados desde el archivo data.csv (modo binario)

                controller_loadFromBinary("data.csv",listaEmpleados);
                system("pause");

            break; // BREAK CASE 2

            case 3: //Alta de empleado

                controller_addEmployee(listaEmpleados);
                system("pause");

            break;

            case 4: // Modificar datos de empleado\n

                controller_editEmployee(listaEmpleados);
                system("pause");

            break;

            case 5: // REMOVER / BAJA DE EMPLEADOS

                controller_removeEmployee(listaEmpleados);
                system("pause");

            break;

            case 6: // LISTAR EMPLEADOS!

                controller_ListEmployee(listaEmpleados);
                system("pause");

            break;

            case 7: // Ordenar empleados

                controller_sortEmployee(listaEmpleados);
                system("pause");

            break;

            case 8: // Guardar los datos de los empleados en el archivo data.csv (modo texto).\n

                controller_saveAsText("data.csv",listaEmpleados);
                system("pause");

            break;

            case 9:

                controller_saveAsBinary("data.csv",listaEmpleados);
                system("pause");

            break;
        }
    } while(opciones != 10);

    return 0;

}





