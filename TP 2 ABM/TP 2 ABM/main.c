#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arrayemployees.h"
#define CANTEMPLOYEES 1000 // CANTIDAD DE EMPLEADOS APROXIMADA DE LA EMPESA
#define MINSALARY 1 //RANGO SALARIAL
#define MAXSALARY 1000000


int main()
{
    int respuesta, opciones, opcionesDos, auxSector, auxId;
    int contadorAltas =0, contadorId =0, auxIndex, index, opcionesCuatro, opcionesListar;
    char auxName[51], auxLastName[51];
    float auxSalary;

    Employee arrayEmployees [CANTEMPLOYEES]; // ESTRUCTURA CON CANTIDAD DE EMPLEADOS.

    initEmployees(arrayEmployees , CANTEMPLOYEES); // INICIALIZACION DE LA BANDERA EN EL ARRAY IS EMPTY, INDICANDO CON 1 QUE TODAS LAS POSICIONES ESTAN VACIAS.

    do
    {
        system("cls");
        utn_getNumeroAvanzada(&opciones, "------MENU PRINCIPAL------\n 1. Altas \n 2. Modificacion  \n 3. Bajas  \n 4. Informar \n 5. Salir. \n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 5,3);

        switch (opciones)
        {
            case 1: // MENU ALTAS
                do
                {
                    if (utn_getCadenaDeCaracteresAvanzada( auxName, "\n Ingrese su nombre: ", "El nombre ingresado no es valido, debe estar compuesto solo por letras....\n", 3 ) != 1)
                    break;

                    if (utn_getCadenaDeCaracteresAvanzada( auxLastName, "\n Ingrese su apellido: ", "El apellido ingresado no es valido, debe estar compuesto solo por letras....\n ", 3 )!= 1)
                    break;

                    if (utn_getNumeroConDecimalesAvanzada(& auxSalary, "\n Ingrese salario: ", "El salario ingresado no es valido, debe estar compuesto solo por numeros....\n ", MINSALARY , MAXSALARY, 3  )!= 1)
                    break;

                    if (utn_getNumeroAvanzada(&auxSector, "\n Ingrese sector: ", "El sector ingresado no es valido, debe ser numerico...\n ", 1 , 20, 3 ) != 1) // VER SI EL SECTOR ES OK NUMERICO OJO
                    break;

                    contadorId++;
                    auxId=contadorId;

                    addEmployee(arrayEmployees ,CANTEMPLOYEES, auxId, auxName, auxLastName, auxSalary, auxSector );

                    contadorAltas ++;

                    if (utn_getNumeroAvanzada(&respuesta, " \n DESEA CONTINUAR INGRESANDO DATOS: 1 (SI) -  2 (NO):", "No ingreso un dato valido, reintente por favor", 1, 2, 3) != 1)
                    break;

                } while (respuesta != 2);

                    break;


            case 2: // MENU MODIFICACION

                if (contadorAltas > 0) // PARA INGRESAR UNICAMENTE SI HAY UN ALTA
                {
                    utn_getNumeroAvanzada(& auxIndex, " \n Ingrese el ID del empleado que desea modificar: ", "El ID ingresado debe ser numerico", 0, 1000, 3);

                    index=findEmployeeById(arrayEmployees, CANTEMPLOYEES, auxIndex);

                    if (index==-1) // CHEQUEAR ESTA PARTE A VER SI ESTA OK PARA INDICAR QUE NO SE ENCONTRO EL ID INGRESADO...
                    {
                        printf("No se encuentra ese ID...\n");
                        break;
                    }

                    do
                    {
                        utn_getNumeroAvanzada(&opcionesDos, "\n 1. Modificar nombre \n 2. Modificar apellido  \n 3. Modificar salario  \n 4. Modificar sector \n 5. Salir. \n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 5,3);


                        switch (opcionesDos)
                        {
                            case 1:

                                utn_getCadenaDeCaracteresAvanzada( arrayEmployees[index].name, "\n Ingrese su nombre: ", "El nombre ingresado no es valido, debe estar compuesto solo por letras....\n", 3 );
                                printf( "\n *****El nombre fue modificado con exito. ****\n \n ");
                                break;

                            case 2:

                                utn_getCadenaDeCaracteresAvanzada( arrayEmployees[index].lastName, "\n Ingrese su apellido: ", "El apellido ingresado no es valido, debe estar compuesto solo por letras....\n ", 3 );
                                printf( "\n *****El apellido fue modificado con exito. ****\n \n ");
                                break;

                            case 3:

                                utn_getNumeroConDecimalesAvanzada(& arrayEmployees[index].salary, "\n Ingrese salario: ", "El salario ingresado no es valido, debe estar compuesto solo por numeros....\n ", MINSALARY , MAXSALARY, 3  );
                                printf( "\n *****El salario fue modificado con exito. ****\n \n ");
                                break;

                            case 4:

                                utn_getNumeroAvanzada(&arrayEmployees[index].sector, "\n Ingrese sector: ", "El sector ingresado no es valido, debe ser numerico...\n ", 1 , 20, 3 );
                                printf( "\n *****El  fue modificado con exito. ****\n \n ");
                                break;
                        }

                    } while (opcionesDos != 5);

                    break;
                }
                else
                {
                    printf("\n ****Primero debe dar de alta un empleado..****\n \n ");
                    break;
                }


            case 3: // MENU BAJAS

                if (contadorAltas > 0) // PARA INGRESAR UNICAMENTE SI HAY UN ALTA
                {
                    utn_getNumeroAvanzada(& auxIndex, " \n Ingrese el ID del empleado que desea dar de baja: ", "El ID ingresado debe ser numerico", 0, 1000, 3);

                    removeEmployee(arrayEmployees, CANTEMPLOYEES, auxIndex);

                    printf( "\n *****El empleado fue removido con exito. ****\n \n ");

                    contadorAltas --;

                    break;
                }
                else
                {
                    printf("\n ****Primero debe dar de alta un empleado..****\n \n ");
                    break;
                }

            break;


            case 4: //MENU INFORMAR

                if (contadorAltas > 0) // PARA INGRESAR UNICAMENTE SI HAY UN ALTA
                {
                    do
                    {
                        utn_getNumeroAvanzada(&opcionesCuatro, "\n 1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n 2. TOTAL SALARIOS - PROMEDIO SALARIOS - EMPLEADOS CUYO SUELDO SUPERAN PROMEDIO.\n 3. Salir. \n \n Seleccione una opcion: ",
                                        " \n Seleccione una opcion valida.", 1, 3,  3 );

                        switch (opcionesCuatro)
                        {
                            case 1: // LISTADO ORDENADO POR APELLIDO Y SECTOR

                                utn_getNumeroAvanzada(&opcionesListar, "Seleccione  0.ORDEN DESCENDENTE - 1. ORDEN ASCENDENTE: ", " \n Seleccione una opcion valida.", 0, 1, 3 );

                                sortEmployees(arrayEmployees, CANTEMPLOYEES, opcionesListar);

                                printEmployees(arrayEmployees, CANTEMPLOYEES);

                            break;

                            case 2:

                                printSalary(arrayEmployees, CANTEMPLOYEES);

                            break;

                        }

                    }while (opcionesCuatro!=3);

                     break;
                }
                else
                {
                    printf("\n ****Primero debe dar de alta un empleado..****\n \n ");
                    break;
                }
        }
    } while (opciones != 5);
    return 0;
}
