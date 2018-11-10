#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validacionesinput.h"


/** \brief CREA LA ESTRUCTURA EMPLOYEE RESERVANDO MEMORIA EN FORMA DINAMICA
 * \return Employee* DEVUELVE LA DIRECCION DE MEMORIA DONDE DICHA ESTRUCTURA FUE CREADA.
 *
 */

Employee* employee_newEmployee()
{
    Employee* employee = (Employee*) malloc(sizeof(Employee)); // VER LA DIFERENCIA ENTRE EL CASTEO EL CUAL INTEGRA EL * Y EL SIZEOF Q SE HACE SIN EL *

    return employee;
}


/** \brief RECIBE LOS DATOS DE LOS EMPLEADOS POR PARAMETROS COMO STRING DESDE EL PARSEO DE DATOS, LOS CONVIERTE A SU TIPO DE DATO ESPECIFICO Y LOS GUARDA
* \param Employee* this CADENA DEL TIPO EMPLOYEE EN DONDE SE GUARDAN LOS DATOS CONVERTIDOS.
* \param char* idStr PARAMETROS RECIBIDOS COMO STRING
* \param char* nombreStr PARAMETROS RECIBIDOS COMO STRING
* \param char* horasTrabajadasStr PARAMETROS RECIBIDOS COMO STRING
* \param char* sueldoStr PARAMETROS RECIBIDOS COMO STRING
* \param pArrayListEmployee LinkedList*
* \return Employee* DEVUELVE LA DIRECCION DE MEMORIA DEL PUNTERO A PERSONA CARGADO, NULL SINO LO PUDO CARGAR
*
*/
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr) // ACA LOS DATOS HAY QUE PASARSELO A LA LISTA LINKED LIST, SERIA ASI SI FUERAN LISTAS ESTATICAS DE TIPO EMPLOYEE [5]
{
    int id, horasT, sueldo;

    Employee* this = employee_newEmployee();

    if ( this != NULL)// SIEMPRE HAY QUE PREGUNTAR POR NULL YA QUE MALLOC EN LA RESERVA DE MEMORIA DINAMICA DEVUELVE NULL SI HAY ERROROR!!!
    {
        id = atoi(idStr);
        horasT = atoi(horasTrabajadasStr);
        sueldo=atoi(sueldoStr);
        //EL NOMBRE NO SE CONVIERTE POR QUE YA ESTA EN STR...

        employee_setId(this, id);
        employee_setNombre(this, nombreStr);
        employee_setHorasTrabajadas(this, horasT);
        employee_setSueldo(this, sueldo);

        /*printf("%d \n", this->id); //ESTO HAY QUE PASARLO y tomarlos en los GET!!!
        printf("%s \n", this->nombre);
        printf("%d \n", this->horasTrabajadas);
        printf("%d \n", this->sueldo);*/


        return this; // SE DEVUELVE LA DIRECCION DE MEMORIA DONDE ESTA LA ESTRUCTURA EMPLOYEE CARGADA!

      }
    else
    {
        printf("ERROR, PUNTERO NULL");

        return NULL;
    }
}

/** \brief RECIBE LOS DATOS DE LOS EMPLEADOS POR PARAMETROS COMO STRING DESDE EL PARSEO DE DATOS, LOS CONVIERTE A SU TIPO DE DATO ESPECIFICO Y LOS GUARDA
* \param Employee* this CADENA DEL TIPO EMPLOYEE EN DONDE SE GUARDAN LOS DATOS CONVERTIDOS.
* \param char* idStr PARAMETROS RECIBIDOS COMO STRING
* \param char* nombreStr PARAMETROS RECIBIDOS COMO STRING
* \param char* horasTrabajadasStr PARAMETROS RECIBIDOS COMO STRING
* \param char* sueldoStr PARAMETROS RECIBIDOS COMO STRING
* \param pArrayListEmployee LinkedList*
* \return Employee* DEVUELVE LA DIRECCION DE MEMORIA DEL PUNTERO A PERSONA CARGADO, NULL SINO LO PUDO CARGAR
*
*/
Employee* employee_newParametrosAddEmployee(int id, char* nombreStr, int horasTrabajadas, int sueldo) // ACA LOS DATOS HAY QUE PASARSELO A LA LISTA LINKED LIST, SERIA ASI SI FUERAN LISTAS ESTATICAS DE TIPO EMPLOYEE [5]
{
    Employee* this = employee_newEmployee();

    if (this != NULL)// SIEMPRE HAY QUE PREGUNTAR POR NULL YA QUE MALLOC EN LA RESERVA DE MEMORIA DINAMICA DEVUELVE NULL SI HAY ERROROR!!!
    {
        employee_setId(this, id);
        employee_setNombre(this, nombreStr);
        employee_setHorasTrabajadas(this, horasTrabajadas);
        employee_setSueldo(this, sueldo);

        /*printf("%d \n", this->id); //ESTO HAY QUE PASARLO y tomarlos en los GET!!!
        printf("%s \n", this->nombre);
        printf("%d \n", this->horasTrabajadas);
        printf("%d \n", this->sueldo);*/

        return this; // SE DEVUELVE LA DIRECCION DE MEMORIA DONDE ESTA LA ESTRUCTURA EMPLOYEE CARGADA!

      }
    else
    {
        printf("ERROR, PUNTERO NULL");

        return NULL;
    }
}

/** \brief elimina y libera espacio del empleado que ya no se haya en uso.
* \param this Employee*
* \return int
*
*/

int employee_delete(Employee* this)
{
    int retorno = -1;

        if(this != NULL)
        {
             free(this);
             retorno = 0;
        }

    return retorno;
}
/** \brief CARGA EL ID DEL EMPLEADO PASADO COMO PARAMETRO.
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \param int id ES EL ID A SER ASIGNADO PASADO COMO PARAMETRO SI CUMPLE LAS CONSICIONES DE VALIDACION.
 * \return int 0 SI ES OK - 1 SI HAY ERROR POR NO PASAR LA VALIDACION.
 *
 */

int employee_setId(Employee* this,int id)
{
    if (this!=NULL) // LAS OTRAS VALIDACIONES NO HARIAN FALTA POR QUE ESTO LO GENERAMOS AUTOMATICAMENTE SIN INTERVENCION DEL USUARIO.
    {
        this->id=id;
        return 0;
    }
    else
    {
        printf("No se pudo asignar un ID \n");
        return 1;
    }
}

/** \brief RETORNAEL ID OBTENIDO EN LA ESTRUCTURA PASADA COMO PARAMETRO
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL ID
 * \return 0 OK -1 ERROR
 *
 */

int employee_getId(Employee* this, int* id)
{
    int retorno=-1;

    if(this!=NULL)
    {
        *id = this->id; // EL VALOR DE ID (*ID) ES EL QUE TIENE GUARDADO EN EL ESPACIO DE ID DEL ARRAY DE EMPLEADOS...
        retorno=0;
    }
    return retorno;

}

/** \brief CARGA EL NOMBRE DEL EMPLEADO PASADO COMO PARAMETRO, VALIDANDO QUE SEA SOLO LETRAS.
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL NOMBRE
 * \param char* nombre ES EL NOMBRE A SER ASIGNADO PASADO COMO PARAMETRO SI CUMPLE LAS CONSICIONES DE VALIDACION.
 * \return int 0 SI ES OK - 1 SI HAY ERROR POR NO PASAR LA VALIDACION.
 *
 */

int employee_setNombre(Employee* this, char* nombre)
{
    int i=0;
    int retorno=1;

    if(this!=NULL)
    {
         while (nombre[i]!= '\0')
         {
             if ((nombre[i] < 'a' || nombre[i] > 'z') && (nombre[i]< 'A' || nombre[i]> 'Z')&& (nombre[i] != ' '))
             break;

             i++;
         }
         if(nombre[i]=='\0')
         {
             strncpy(this->nombre, nombre, sizeof(this->nombre));
             retorno=0;
         }
    }
     return retorno;
}

/** \brief RETORNA LA POSICION DE MEMORIA DEL NOMBRE OBTENIDO DE LA ESTRUCTURA PASADA COMO PARAMETRO
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA LEER EL NOMBRE
 * \return char RETORNA LA POSICION DE MEMORIA DE EL NOMBRE DE LA ESTRUCTURA PASADA COMO PARAMETRO.
 *
 */

int employee_getName(Employee* this, char* nombre)
{
    int retorno=-1;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief CARGA LAS HORAS TRABAJADAS POR EMPLEADO PASADO COMO PARAMETRO.
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL NOMBRE
 * \param int horasTrabajadas HORAS TRABAJADAS A SER PASADAS COMO PARAMETRO SI CUMPLE LAS CONDICIONES DE VALIDACION.
 * \return int 0 SI ES OK - 1 SI HAY ERROR POR NO PASAR LA VALIDACION.
 *
 */
 int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
 {
    if(this != NULL && horasTrabajadas > 0 )
    {
        this->horasTrabajadas=horasTrabajadas;
        return 0;
    }
    else
    {
        printf("No se pudo asignar LAS HORAS TRABAJADAS \n");
        return 1;
    }

 }

 /** \brief RETORNA (LA POSICION DE MEMORIA)LAS HORAS TRABAJADAS OBTENIDO EN LA ESTRUCTURA PASADA COMO PARAMETRO
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE VA A MOSTRAR LAS HORA TRABAJADAS
 * \return HORAS TRABAJADAS POR EL EMPLEADO.
 *
 */

int employee_getHours(Employee* this, int* horasTrabajadas)
{
    int retorno=-1;

    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief CARGA EL SUELDO DEL EMPLEADO PASADO COMO PARAMETRO.
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE LE VA A ASIGNAR EL SUELDO
 * \param int sueldo SUELDO PASADO COMO PARAMETRO SI CUMPLE LAS CONDICIONES DE VALIDACION.
 * \return int 0 SI ES OK - 1 SI HAY ERROR POR NO PASAR LA VALIDACION.
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
 {
    if(this != NULL && sueldo > 0 )
    {
        this->sueldo=sueldo;
        return 0;
    }
    else
    {
        printf("No se pudo asignar EL SUELDO \n");
        return 1;
    }

 }

 /** \brief RETORNA (LA POSICION DE MEMORIA)EL SUELDO OBTENIDO EN LA ESTRUCTURA PASADA COMO PARAMETRO
 * \param Employee* this PUNTERO A LA ESTRUCTURA EMPLOYEE A LA CUAL SE VA A MOSTRAR EL SUELDO
 * \return SUELDO DEL EMPLEADO
 *
 */

int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno=-1;

    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}


/** \brief Libera el espacio ocupado por un empleado recibido como parametro
 * \param Person* this Puntero al empleado
 * \return void
 *
 */

void employee_free(Employee* this)
{
    if (this != NULL)
    {
        free(this);
    }
}

/** \brief Base a tomar para realizar un ordenamiento de empleados por nombre.
 *
 * \param thisA void* PUNTEROS VOID
 * \param thisB void* PUNTEROS VOID
 * \return 0 SINO GUARDO NADA 1 SI EL NOMBRE A ES MAS GRANDE QUE EL B Y -1 SINO LO ES
 *
 */
int employee_sortByName(void* thisA,void* thisB)
{
    int retorno = 0;

    char nameA[51];
    char nameB[51];

   employee_getName(thisA,nameA);
   employee_getName(thisB,nameB);

   if(strcmp(nameA,nameB) > 0)
   {
        retorno = 1; // retorna uno si el nombre a es mas grande que el b
   }
   else if(strcmp(nameA,nameB)< 0)
   {
        retorno = -1;
   }

    return retorno;
}
