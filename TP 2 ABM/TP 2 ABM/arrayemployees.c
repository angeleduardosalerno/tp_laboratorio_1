#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arrayemployees.h"
#define CANTEMPLOYEES 1000

/** \brief Verifica si el valor recibido es numerico.
* \param char cadena de caracteres a ser analizada.
* \return Devuelve 1 si es numerico y 0 si no lo es.
*
*/
int utn_esNumericoAvanzada (char cadena [])
{
    int i=0;
    int retorno = 0;

    if(cadena!=NULL)
    {
        while (cadena[i]!= '\0')
        {
            if (cadena[i] < '0' || cadena[i] > '9' )
                break;
            i++;
        }
        if(cadena[i]=='\0')
        retorno=1;
    }
    return retorno;
}

/** \brief Almacena el numero ingresado (usando fgets en lugar de scanf)  luego de validar el dato como cadena de caracteres.
* \param int* pResultado Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
* \return Devuelve 1 si pudo guardar el dato en *pResultado y 0 si no lo pudo guardar por no pasar la validacion.
*
*/
int utn_getIntAvanzada(int* pResultado)
{
    int retorno = 0;
    char buffer[64];

    if(pResultado!=NULL)
    {
        fgets(buffer,sizeof(buffer),stdin);
        buffer[strlen(buffer)-1]='\0';

        if(utn_esNumericoAvanzada(buffer))
        {
            *pResultado = atoi(buffer);
            retorno = 1;
        }
    }
        return retorno;
}

/** \brief Almacena el numero ingresado, luego de validar el dato.
* \param int* pResultado Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto. // OJO HAY QUE PONER EL & EN LA VARIABLE... ej &arrayEmployees[i].sector
* \param char* mensaje Mensaje a ser mostrado al usuario para que determine que dato desee ingresar.
* \param char* mensajeError Mensaje a ser mostrado al usuario en caso de no ingresar un dato valido.
* \param int minimo Numero minimo valido para ingresar.
* \param int maximo Numero maximo valido para ingresar.
* \param int reintentos Reintentos brindados al usuario en caso de ingresar datos invalidos.
* \return Devuelve 1 si pudo guardar el dato en *pResultado y 0 si no lo pudo guardar por no pasar la validacion.
*
*/

int utn_getNumeroAvanzada(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno;
    int numero;

        if (pResultado!= NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
        {
            while(reintentos>0)
            {
                printf("%s", mensaje);

                if(utn_getIntAvanzada(&numero)==1)
                {
                    if(numero<=maximo && numero>=minimo)
                    break;
                }
                reintentos--;
                printf("%s", mensajeError);
            }
            if(reintentos==0)
            {
                retorno=0;
            }
            else
            {
                retorno=1;
                *pResultado = numero;
            }
        }
            return retorno;
}

/** \brief Verifica si el valor recibido es decimal.
* \param char cadena de caracteres a ser analizada.
* \return Devuelve 1 si es decimal y 0 si no lo es.
*
*/
int utn_esDecimalAvanzada(char cadena [])
{
    int i=0;
    int retorno = 0;
    int contadorPuntos=0;

    if(cadena!=NULL)
    {
        while (cadena[i]!= '\0')
        {
            if (cadena[i] == '.')
            {
                contadorPuntos++;
            }

            if ((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '.') && (contadorPuntos != 1))
                break;
            i++;
        }
        if(cadena[i]=='\0')
        retorno=1;
    }
    return retorno;
}

/** \brief Almacena el numero decimal ingresado (usando fgets en lugar de scanf)  luego de validar el dato como cadena de caracteres.
* \param float* pResultado Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
* \return Devuelve 1 si pudo guardar el dato en *pResultado y 0 si no lo pudo guardar por no pasar la validacion.
*
*/
int utn_getFloatAvanzada(float* pResultado)
{
    int retorno = 0;
    char buffer[64];

    if(pResultado!=NULL)
    {

        fgets(buffer,sizeof(buffer),stdin);
        buffer[strlen(buffer)-1]='\0';

        if(utn_esDecimalAvanzada(buffer))
        {
            *pResultado = atof(buffer); // VER SI ATOF ESTA OK
            retorno = 1;
        }
    }
        return retorno;
}

/** \brief Almacena el numero con decimal ingresado, luego de validar el dato.
* \param float* pResultado Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
* \param char* mensaje Mensaje a ser mostrado al usuario para que determine que dato desee ingresar.
* \param char* mensajeError Mensaje a ser mostrado al usuario en caso de no ingresar un dato valido.
* \param int minimo Numero minimo valido para ingresar.
* \param int maximo Numero maximo valido para ingresar.
* \param int reintentos Reintentos brindados al usuario en caso de ingresar datos invalidos.
* \return Devuelve 1 si pudo guardar el dato en *pResultado y 0 si no lo pudo guardar por no pasar la validacion.
*
*/

int utn_getNumeroConDecimalesAvanzada(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno;
    float numero;

        if (pResultado!= NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
        {
            while(reintentos>0)
            {
                printf("%s", mensaje);

                if(utn_getFloatAvanzada(&numero)==1)
                {
                    if(numero<=maximo && numero>=minimo)
                    break;
                }
                reintentos--;
                printf("%s", mensajeError);
            }
            if(reintentos==0)
            {
                retorno=0;
            }
            else
            {
                retorno=1;
                *pResultado = numero;
            }
        }
            return retorno;
}

/** \brief Valida que la cadena de caracteres ingresada posea solo letras y espacios vacios.
* \param char cadena Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
* \return Devuelve 1 si pudo guardar el dato en char cadena y 0 si no lo pudo guardar por no pasar la validacion.
*
*/

int utn_esStringAvanzada(char cadena [])
{
    int i=0;
    int retorno=0;

    if(cadena!=NULL)
    {
        while (cadena[i]!= '\0')
        {
            if ((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i]< 'A' || cadena[i]> 'Z')&& (cadena[i] != ' '))
            break;

            i++;
        }
        if(cadena[i]=='\0')
        retorno=1;
    }
    return retorno;
}

/** \brief Almacena la cadena de caracteres ingresada y la devuelve.
* \param char cadena Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
* \return Devuelve 1 si pudo guardar el dato en char cadena y 0 si no lo pudo guardar por no pasar la validacion.
*
*/
int utn_getStringAvanzada(char cadena [])
{
    int retorno = 0;
    char buffer[64];

    if(cadena!=NULL)
    {

        fgets(buffer,sizeof(buffer),stdin);
        buffer[strlen(buffer)-1]='\0';

        if(utn_esStringAvanzada(buffer))
        {
            strcpy( cadena, buffer);
            retorno = 1;
        }
    }
        return retorno;
}

/** \brief Obtiene una cadena de caracteres y la valida. (solo letras y espacios vacios).
* \param char cadena Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
* \param char* mensaje Mensaje a ser mostrado al usuario para que determine que dato desee ingresar.
* \param char* mensajeError Mensaje a ser mostrado al usuario en caso de no ingresar un dato valido.
* \param int reintentos Reintentos brindados al usuario en caso de ingresar datos invalidos.
* \return Devuelve 1 si pudo guardar el dato en char cadena y 0 si no lo pudo guardar por no pasar la validacion.
*
*/

int utn_getCadenaDeCaracteresAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos)
{
    int retorno;
    char texto [52];

        if (cadena!= NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
        {
            while(reintentos>0)
            {
                printf("%s", mensaje);

                if(utn_getStringAvanzada(texto))
                    break;

                reintentos--;
                printf("%s", mensajeError);
            }
            if(reintentos==0)
            {
                retorno=0;
            }
            else
            {
                strcpy(cadena, texto );
                retorno=1;
            }
        }
            return retorno;
}
// FUNCIONES PROPIAS DEL TP

/**\brief Para indicar que todas las posiciones del array employee estan vacias, esta funcion pone la bandera isEmpty de la estructura en 1 (TRUE).
* \param Employee arrayEmployees Es el array de tipo de dato estructura a ser inicializado.
*\param int longitudArray Es la cantidad de elementos del array.
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int initEmployees(Employee arrayEmployees [], int longitudArray)
{
    int i, retorno = -1;

    if (arrayEmployees!= NULL && longitudArray > 0)
    {
        for (i=0; i< longitudArray; i++)
        {
            arrayEmployees[i].isEmpty = 1;
        }
            retorno=0;
    }
    return retorno;
}

/**\brief Busca el primer lugar vacio en un array estructura, previamente cargado con el valor 1.
* \param ePersona arrayPersonas Es el array de tipo de dato estructura en donde se busca el dato.
*\param int longitudArray Es la cantidad de elementos del array de enteros.
* \return Devuelve el subindice vacio en el array (i) o -1 en caso de no haber lugar vacio. // OJO ACA USO EL -1 PARA INDICAR LUGAR VACIO
*
*/

int utn_buscarLugarVacioEpersona (Employee arrayEmployees [],int longitudArray)
{
    int i, retorno=-1;

    if (arrayEmployees!= NULL && longitudArray > 0)
    {
        for (i=0; i< longitudArray ; i++)
        {
            if ( arrayEmployees[i].isEmpty == 1)
            {
                retorno= i;
                break;
            }
        }
    }
        return retorno;
}

/** \brief Agrega en un array de empleados existente, los valores recibidos como parámetro, en la primer posición libre encontrada.
* \param Employee arrayEmployees [] Array de  empleados donde se cargan los datos ingresador
* \param int longitudArray longitud del array de empleados.
* \param id int // no va se calcula automaticamente....x funcion random
* \param name[] char nombre del empleado a cargar, pasado por referencia desde main.
* \param lastName[] char apellido del empleado a cargar, pasado por referencia desde main
* \param salary float salario del empleado a cargar, pasado por referencia desde main
* \param sector int sector del empleado a cargar, pasado por referencia desde main
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/

int addEmployee(Employee arrayEmployees [], int longitudArray, int id , char name[],char lastName[],float salary,int sector)
{
      int i;
      int retorno=-1;

    if (arrayEmployees!= NULL && longitudArray > 0)
    {
       i= utn_buscarLugarVacioEpersona(arrayEmployees, longitudArray); // BUSCA EL 1 Q ES EL LUGAR VACIO...

       if (i != -1) // o sea si no hay error en la funcion anterior
       {
           arrayEmployees[i].isEmpty=0;
           arrayEmployees[i].id = id; //NO ANDA ASI POR Q CUANDO LO ORDENA EL SORT, EL ID SIGUE SIENDO EL 0 PERO LO PASA A OTRA POSICION Y SIGUE SIENDO EL MISMO ID DEL PRINCIPIO...
           strcpy (arrayEmployees[i].name, name);
           strcpy (arrayEmployees[i].lastName, lastName);
           arrayEmployees[i].salary=salary;
           arrayEmployees[i].sector=sector;

           retorno= 0;
       }
    }
        return retorno;
}

/** \brief find an Employee by Id en returns the index position in array.
* \param Employee arrayEmployees array de empleados en el cual se va a buscar el id.
* \param len int tamaño del array de empleados.
* \param id int el id de empleado a buscar.
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/
int findEmployeeById(Employee arrayEmployees [], int longitudArray, int id)
{
    int i;
    int retorno=-1;

    if (arrayEmployees!= NULL && longitudArray > 0)
    {
        for (i=0; i< longitudArray ; i++)
        {
            if (arrayEmployees[i].id == id)
            {
                retorno= i;
                break;
            }
        }
    }
        return retorno;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
* \param Employee arrayEmployees Array de empleados donde se va a buscar el que se desea eliminar.
* \param int longitudArray tamaño del array de empleados.
* \param id int el id de empleado a buscar.
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee arrayEmployees [], int longitudArray, int id)
{
    int i;
    int retorno=-1;

    if (arrayEmployees!= NULL && longitudArray > 0)
    {
        for (i=0; i< longitudArray ; i++)
        {
            if (arrayEmployees[i].id == id)
            {
                arrayEmployees[i].isEmpty=1;
                retorno= 0;
            }
        }
    }
        return retorno;
}

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
* \param Employee arrayEmployees Array de empleados que se va a ordenar.
* \param int longitudArray tamaño del array de empleados.
* \param orden int [1] indicate UP ascendente - [0] indicate DOWN descendente
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee arrayEmployees [], int longitudArray, int orden) // TENGO QUE HACER UN FLAG PARA VER SI ESTA ORDENADO O NO...OJO!
{
    int i, j, retorno=-1;
    Employee auxArrayEmployees;

    if (arrayEmployees!= NULL && longitudArray > 0)
    {
        for(i=0; i<longitudArray-1; i++)
        {
            for(j=i+1; j<longitudArray; j++)
            {
                if (orden ==1) // ORDENAMIENTO ASCENDENTE menor a mayor
                {
                    if (strcmp(arrayEmployees[i].lastName,arrayEmployees[j].lastName) >0) // PIDE ORDENAMIENTO POR APELLIDO Y SECTOR VER SI SE PONE UN Y ACA O HAY OTRA FORMA
                    {
                        auxArrayEmployees = arrayEmployees[i];
                        arrayEmployees[i] = arrayEmployees[j];
                        arrayEmployees[j] = auxArrayEmployees;
                        retorno=0;
                    }
                    else
                    {
                        if (strcmp(arrayEmployees[i].lastName,arrayEmployees[j].lastName)==0)
                        {
                            if (arrayEmployees[i].sector > arrayEmployees[j].sector) //OJO ACA, HAY Q VER SI ESTA OK X Q EN EL DE DOS CRITERIOS EL CRITERIO ANTERIORMENTE ORDENADO LO SACABAN...
                            {
                                auxArrayEmployees = arrayEmployees[i];
                                arrayEmployees[i] = arrayEmployees[j];
                                arrayEmployees[j] = auxArrayEmployees;
                                retorno=0;
                            }
                        }
                    }
                }
                else // ORDENAMIENTO DESDENDENTE DE MAYOR A MENOR
                {
                    if (strcmp(arrayEmployees[i].lastName,arrayEmployees[j].lastName) < 0) // PIDE ORDENAMIENTO POR APELLIDO Y SECTOR VER SI SE PONE UN Y ACA O HAY OTRA FORMA
                    {
                        auxArrayEmployees = arrayEmployees[i];
                        arrayEmployees[i] = arrayEmployees[j];
                        arrayEmployees[j] = auxArrayEmployees;
                        retorno=0;
                    }
                    else
                    {
                        if (strcmp(arrayEmployees[i].lastName,arrayEmployees[j].lastName) ==0)
                        {
                            if (arrayEmployees[i].sector < arrayEmployees[j].sector) //OJO ACA, HAY Q VER SI ESTA OK X Q EN EL DE DOS CRITERIOS EL CRITERIO ANTERIORMENTE ORDENADO LO SACABAN...
                            {
                                auxArrayEmployees = arrayEmployees[i];
                                arrayEmployees[i] = arrayEmployees[j];
                                arrayEmployees[j] = auxArrayEmployees;
                                retorno=0;
                            }
                        }
                    }

                }
            }
        }
    }
            return retorno;
}

/** \brief print the content of employees array.
* \param Employee arrayEmployees [], es es array a ser impreso
* \param int longitudArray Longitud del array de empleados.
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
*
*/
int printEmployees(Employee arrayEmployees [], int longitudArray)
{
    int i;
    int retorno=-1;

    if (arrayEmployees!= NULL && longitudArray > 0)
    {
         for (i=0; i< longitudArray ; i++)
        {
            if (arrayEmployees[i].isEmpty != 1) // SOLAMENTE VA A MOSTRAS LOS VECTORES GUARDADOS, SINO HAY DATOS MUESTRA BASURA..
            {
                printf("Apellido:%s\tNombre:%s\tSector:%d\tSalario:%0.2f\tID:%d\t\n",
                    arrayEmployees[i].lastName, arrayEmployees[i].name, arrayEmployees[i].sector , arrayEmployees[i].salary , arrayEmployees[i].id );
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Imprime el total de los salarios, el promedio y la cantidad de empleados que superan el salario medio del array de empleados.
* \param Employee arrayEmployees [], es es array a ser impreso.
* \param int longitudArray Longitud del array de empleados.
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
*
*/
int printSalary(Employee arrayEmployees [], int longitudArray)
{
    int i, contadorSalarios=0, contadorSalariosMax=0;
    float salarioPromedio, acumuladorSalarios=0;
    int retorno=-1;

    if (arrayEmployees!= NULL && longitudArray > 0)
    {
        for (i=0; i< longitudArray ; i++) // PARA CALCULAR PROMEDIOS Y TOTAL DE SALARIOS.
        {
            if (arrayEmployees[i].isEmpty ==0)
            {
                acumuladorSalarios= acumuladorSalarios + arrayEmployees[i].salary;
                contadorSalarios++;
                salarioPromedio= acumuladorSalarios / contadorSalarios;
            }
        }

        for (i=0; i< longitudArray ; i++) // PARA CALCULAR LA CANT CON SALARIOS SUPERIOR AL PROMEDIO
        {
            if ((arrayEmployees[i].isEmpty ==0) && (arrayEmployees[i].salary > salarioPromedio))
            {
                    contadorSalariosMax ++;
            }
        }

        printf( "\n El total de los Salarios es: %0.2f \n El promedio de los salarios es: %0.2f \n La cantidad de empleados que superan el salario promedio son: %d \n"
                 ,acumuladorSalarios, salarioPromedio, contadorSalariosMax);

        retorno=0;
    }
    return retorno;
}
