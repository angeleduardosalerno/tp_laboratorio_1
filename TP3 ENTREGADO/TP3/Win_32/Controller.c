#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validacionesinput.h"
#include "parser.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* ES EL NOMBRE DEL ARCHIVO PASADO DESDE EL MAIN
 * \param pArrayListEmployee LinkedList*
 * \return int 0 SI PUDO ABRIR EL ARCHIVO E INGRESAR AL PARSEO -1 SINO LO PUDO ABRIR.
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile;
     // HAY QUE CREAR LAS VARIABLES EMPLOYEE CON RESERVA DINAMICA DE MEMORIA SINO NO SE PUEDE GUARDAR EN NINGUN LADO ESTO...
    pFile = fopen(path,"r"); // OJOOOOOO ACA VA EL TIPO LO Q TENGO QUE HACER! ES MEJOR ABRIRLO POR CADA ITEM DE ACUERDO A LO Q TE PIDAN!!
    // O SEA SI SE PUDO ABRIR EL ARCHIVO...! SE HACE EL PARSEO!!
    if(pFile != NULL && path != NULL) // ACA HAY QUE PREGUNTAR POR LOS DOS, HAY QUE PREGUNTAR POR EL ERROR...
    {
        parser_EmployeeFromText(pFile, pArrayListEmployee);
        return 0;
    }
    else
    {
        fclose(pFile);
        return -1;
    }

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    if(path != NULL && pArrayListEmployee != NULL ) // ACA HAY QUE PREGUNTAR POR LOS DOS, HAY QUE PREGUNTAR POR EL ERROR...
    {
        FILE *pFile;

        pFile=fopen(path,"rb"); // ACA ES NECESARIO ABRIRLO EN RB O SE PUEDE ABRIR SOLO EN R? ANDA IGUAL CON R...

        if(pFile!=NULL) // SE ABRE EL BINARIO EN LECTURA, SI ES NULL ES POR QUE NO EXISTE Y SE CREA
        {
            parser_EmployeeFromBinary(pFile, pArrayListEmployee); // VER SI ESTA OK SE PARSEA LA PRIMERA VEZ SI LO CREA

            return 0;

        }
        else // SI EL ARCHIVO EXISTE Y SE LEE OK, CONTINUAS CON EL PARSEO
        {
            printf("\n ERROR PUNTEROS NULL");
            fclose(pFile);
            return -1;
        }
    }
    else
    {
        printf("\n ERROR PUNTEROS NULL");
        return -1;
    }

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int aux1, aux3, aux4, respuesta;
    char aux2[50];

    if(pArrayListEmployee != NULL ) // ACA HAY QUE PREGUNTAR POR LOS DOS, HAY QUE PREGUNTAR POR EL ERROR...
    {
        do
        {
            utn_getNumeroAvanzada(&aux1, "Ingrese ID \n", "ERROR EN EL INGRESO DEL ID \n", 1, 10000, 10);
            utn_getCadenaDeCaracteresAvanzada( aux2, "Ingrese NOMBRE \n", "ERROR EN EL INGRESO DEL NOMBRE \n",10 );
            utn_getNumeroAvanzada(&aux3, "Ingrese HORAS TRABAJADAS \n", "ERROR EN EL INGRESO DE HORAS TRABAJADAS \n", 1, 10000, 10 );
            utn_getNumeroAvanzada(&aux4, "Ingrese SUELDO \n", "ERROR EN EL INGRESO DEL SUELDO \n", 1, 10000, 10 );

            Employee* employeeAdd= employee_newParametrosAddEmployee(aux1, aux2, aux3, aux4); // LE PASAS LAS VARIABLES AUX PARA DAR DE ALTA EL NUEVO EMPLEADO

            ll_add(pArrayListEmployee,employeeAdd); // OJO ACA, LO INTEGRA EN LA LISTA PERO, LO GUARDA EN EL ARCHIVO?? // ACA LO PONE EN LA LISTA

            utn_getNumeroAvanzada(&respuesta, "Desea continuar ingresando los datos ?: 1 (si) / 0 (no) \n", "ERROR", 0, 1, 3);

        } while (respuesta == 1);

        return 1;
    }
    else
    {
        printf("\n ERROR PUNTEROS NULL");
        return -1;
    }

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
 {
     int retorno = -1;
     int i, id, idAux, auxSueldo, auxHotasT;
     int opcion, opcionDos;
     char auxNombre[51];


     utn_getNumeroAvanzada(&opcion, "Desea ver la lista de empleados? ?: 1 (si) / 0 (no) \n", "ERROR", 0, 1, 3);

     if(opcion==1)
     {
         controller_ListEmployee(pArrayListEmployee);
     }

     if(pArrayListEmployee != NULL)
     {
         if(utn_getNumeroAvanzada(&id,"Ingrese el ID del empleado a modificar: ","Reingrese un numero valido", 0, 2000, 10)==1) // O SEA SI SE PUDO GUARDAR EL ID
         {
             for(i = 0;i< ll_len(pArrayListEmployee);i++)           //LO HACE DE A UNA VEZ...
             {                                                      //GUARDAS LAS DIRECCIONES DE MEMORIA EL LA VARIABLE EMPLEADO...
                Employee* empleado = ll_get(pArrayListEmployee,i); // IMPRIME LA DIRECCION DE MEMORIA QUE ALMACENA LOS DATOS CARGADOS DE LOS EMPLEADOS

                employee_getId(empleado, &idAux); // VER BIEN, ACA LE PASAS L ARRAY Y LA DIRECCION DE MEMORIA DEL ID AUX   OJOOOO VER!!!!

                if(idAux == id)
                {
                    do
                    {
                        utn_getNumeroAvanzada(&opcionDos,"QUE CAMPO DESEA MODIFICAR ??:\n 1- Nombre \n 2- Horas de trabajo \n 3- Sueldo \n 4- SALIR \n","Reingrese OPCION VALIDA", 0, 4, 10);

                        switch(opcionDos)

                        {
                            case 1: //NOMBRE

                                if(utn_getCadenaDeCaracteresAvanzada( auxNombre, "Ingrese NOMBRE \n", "ERROR EN EL INGRESO DEL NOMBRE \n",10 )==1)
                                {
                                     if(!employee_setNombre(empleado, auxNombre)) // SI EL DATO SE GUARDA OK...
                                       {
                                         retorno = 0;
                                         break;
                                       }
                                }
                            break;

                            case 2: // HORAS TRABAJADAS!

                                if(utn_getNumeroAvanzada(&auxHotasT, "Ingrese HORAS TRABAJADAS \n", "ERROR EN EL INGRESO DE HORAS TRABAJADAS \n", 1, 10000, 10 )==1)
                                {
                                     if(!employee_setHorasTrabajadas(empleado, auxHotasT)) // SI EL DATO SE GUARDA OK...
                                       {
                                         retorno = 0;
                                         break;
                                       }
                                }

                            break;

                            case 3:

                                if(utn_getNumeroAvanzada(&auxSueldo, "Ingrese SUELDO \n", "ERROR EN EL INGRESO DEL SUELDO \n", 1, 10000, 10 )==1)
                                {
                                    if(!employee_setSueldo(empleado, auxSueldo)) // SI EL DATO SE GUARDA OK...
                                       {
                                         retorno = 0;
                                         break;
                                       }
                                }

                            break;
                        }

                    }while (opcionDos!= 4);
                }
             }
         }
     }

     return retorno;
 }


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i, id, idAux;
    int opcion, opcionDos;

    do
    {
        utn_getNumeroAvanzada(&opcionDos,"\n QUE DESEA REALIZAR:\n \n 1- ELIMINAR EMPLEADO \n 2- SALIR \n ","Reingrese OPCION VALIDA", 0, 2, 10);

        switch(opcionDos)
        {
            case 1:

            utn_getNumeroAvanzada(&opcion, "Desea ver la lista de empleados? ?: 1 (si) / 0 (no) \n", "ERROR", 0, 1, 3);

            if(opcion==1)
            {
             controller_ListEmployee(pArrayListEmployee);
            }

            if(pArrayListEmployee != NULL)
            {
                if(utn_getNumeroAvanzada(&id,"Ingrese el ID del empleado a ELIMINAR: \n","Reingrese un numero valido", 0, 2000, 10)==1) // O SEA SI SE PUDO GUARDAR EL ID
                {
                     for(i = 0;i< ll_len(pArrayListEmployee);i++)           //LO HACE DE A UNA VEZ...
                     {                                                      //GUARDAS LAS DIRECCIONES DE MEMORIA EL LA VARIABLE EMPLEADO...
                        Employee* empleado = ll_get(pArrayListEmployee,i); // IMPRIME LA DIRECCION DE MEMORIA QUE ALMACENA LOS DATOS CARGADOS DE LOS EMPLEADOS

                        employee_getId(empleado, &idAux); // VER BIEN, ACA LE PASAS L ARRAY Y LA DIRECCION DE MEMORIA DEL ID AUX   OJOOOO VER!!!!

                        if(idAux == id)
                        {
                            employee_delete(empleado); // hace un free a esa direccion de memoria
                            ll_remove(pArrayListEmployee,i);

                            retorno = 0;

                            break;
                        }
                     }
                }
            }

            break;
        }

    }while (opcionDos!= 2);

    return retorno;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList* ARRAY CON LISTA DE PUNTEROS...
 * \return int -1 ERROR INT 0 OK!
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
     int retorno = -1;
     int i;
     char nombre[128];
     int id, sueldo, horasTrabajadas;

     Employee* auxPunteroEmpleado;

     if(pArrayListEmployee != NULL)
     {
         for(i=0;i < ll_len(pArrayListEmployee);i++)
         {
            if(i%50==0) // si pones mas de 60 te cuenta desde un id diferente de 0
            {
                system("pause"); // si no va aca y lo pones abajo, en el else imprime de a uno...

                 auxPunteroEmpleado = ll_get(pArrayListEmployee,i);// FUNCION LL_GET RECIBE LA LISTA Y EL INDICE Y DEVUELVE LO POSICION DE MEMORIA DEL EMPLEADO QUE TIENE GUARDADO, ACCEDIENDO A ESA POSICION DE MEMORIA SE IMPRIMEN LOS DATOS...

                 employee_getId(auxPunteroEmpleado,&id);
                 employee_getName(auxPunteroEmpleado,nombre);
                 employee_getSueldo(auxPunteroEmpleado,&sueldo);
                 employee_getHours(auxPunteroEmpleado,&horasTrabajadas);

                 printf("\nID: %d",id);
                 printf("\nNombre: %s",nombre);
                 printf("\nSueldo: %d",sueldo);
                 printf("\nHoras trabajadas: %d",horasTrabajadas);
                 printf("\n");
                 retorno = 0;
            }
            else
            {
                 auxPunteroEmpleado = ll_get(pArrayListEmployee,i); // FUNCION LL_GET RECIBE LA LISTA Y EL INDICE Y DEVUELVE LO POSICION DE MEMORIA DEL EMPLEADO QUE TIENE GUARDADO

                 employee_getId(auxPunteroEmpleado,&id);
                 employee_getName(auxPunteroEmpleado,nombre);
                 employee_getSueldo(auxPunteroEmpleado,&sueldo);
                 employee_getHours(auxPunteroEmpleado,&horasTrabajadas);

                 printf("\nID: %d",id);
                 printf("\nNombre: %s",nombre);
                 printf("\nSueldo: %d",sueldo);
                 printf("\nHoras trabajadas: %d",horasTrabajadas);
                 printf("\n");

            }
         }
     }
     else
     {
        printf("\n ERROR PUNTEROS NULL");
        retorno=-1;

     }
     system("pause");

     return retorno;
}

/** \brief Ordenar empleados LFABETICAMENTE
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        printf("\n ORDENANDO ALFABETICAMENTE, ESPERE POR FAVOR...\n");

        if(! ll_sort(pArrayListEmployee,employee_sortByName,1))
        {
            controller_ListEmployee(pArrayListEmployee);
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int -1 ERROR 0 OK
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pFile;
     // HAY QUE CREAR LAS VARIABLES EMPLOYEE CON RESERVA DINAMICA DE MEMORIA SINO NO SE PUEDE GUARDAR EN NINGUN LADO ESTO...
    pFile = fopen(path,"w"); // OJOOOOOO ACA VA EL TIPO LO Q TENGO QUE HACER! ES MEJOR ABRIRLO POR CADA ITEM DE ACUERDO A LO Q TE PIDAN!!
    // O SEA SI SE PUDO ABRIR EL ARCHIVO...! SE HACE EL PARSEO!!
    if(pFile != NULL && path != NULL) // ACA HAY QUE PREGUNTAR POR LOS DOS, HAY QUE PREGUNTAR POR EL ERROR...
    {
        parser_EmployeeFromText(pFile, pArrayListEmployee);
        return 0;
    }
    else
    {
        fclose(pFile);
        return -1;
    }

}



/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    if(path != NULL && pArrayListEmployee != NULL ) // ACA HAY QUE PREGUNTAR POR LOS DOS, HAY QUE PREGUNTAR POR EL ERROR...
    {
        FILE *pFile;

        pFile=fopen(path,"wb"); // ACA ES NECESARIO ABRIRLO EN RB O SE PUEDE ABRIR SOLO EN R? ANDA IGUAL CON R...

        if(pFile!=NULL) // SE ABRE EL BINARIO EN LECTURA, SI ES NULL ES POR QUE NO EXISTE Y SE CREA
        {
            parser_EmployeeFromBinary(pFile, pArrayListEmployee); // VER SI ESTA OK SE PARSEA LA PRIMERA VEZ SI LO CREA

            return 0;

        }
        else // SI EL ARCHIVO EXISTE Y SE LEE OK, CONTINUAS CON EL PARSEO
        {
            printf("\n ERROR PUNTEROS NULL");
            fclose(pFile);
            return -1;
        }
    }
    else
    {
        printf("\n ERROR PUNTEROS NULL");
        return -1;
    }

}


