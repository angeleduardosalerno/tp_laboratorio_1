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
    char fileName[20];

    LinkedList* listaEmpleados = ll_newLinkedList(); // SE CREA UNA LISTA LINKED LIST, ASIGNANDOLE MEMORIA DINAMICAMENTE.

    do
    {
        //system("cls");
        printf ("\n ------------------------MENU PRINCIPAL-------------------------------------\n");
        printf("\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("\n 6. Listar empleados\n");
        printf("\n 8. Guardar los datos de los empleados en el archivo info.csv (modo texto).\n ");
        printf("\n 9. Guardar los datos de los empleados en el archivo info.dat (modo binario).\n ");
        printf("\n10. Salir\n");

        utn_getNumeroAvanzada(&opciones, " \n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 10,3);

        switch (opciones)
        {
            case 1: // Cargar los datos de los empleados desde el archivo data.csv (modo texto).

                printf("\nIngrese el nombre y ruta del archivo que desea abrir: ");
                fflush(stdin);
                scanf("%s", fileName); // se ingresa como data.csv ---------->para mehorar: hacer una funcion de validacion

                controller_loadFromText(fileName,listaEmpleados);
                system("pause");

            break; // BREAK CASO 1


            case 6: // LISTAR EMPLEADOS!

                controller_ListEmployee(listaEmpleados);
                system("pause");

            break;


            case 8: // Guardar los datos de los empleados en el archivo data.csv (modo texto).\n

                controller_saveAsText("info.csv",listaEmpleados);
                system("pause");

            break;

            case 9:

                controller_saveAsBinary("info.dat",listaEmpleados);
                system("pause");

            break;
        }
    } while(opciones != 10);

    return 0;

}



