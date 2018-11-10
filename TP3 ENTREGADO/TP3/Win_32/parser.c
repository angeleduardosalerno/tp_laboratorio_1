#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validacionesinput.h"
#include "parser.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 SI ES OK -1 SI HAY ERROR
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r;
    char var1[50], var2[50] ,var3[50] ,var4[50]; // VARIABLES AUX EN Q SE ALMACENA LOS DATOS DEL ARCHIVO LEIDOS COMO STRING

    if (pFile != NULL && pArrayListEmployee != NULL )
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);// LECTURA EN FALSO PARA EVITAR LOS TITULOS

        do{
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4); // SE LEE DEL ARCHIVO LOS ELEMENTOS COMO STRING...

            if(r==4) // SI PUDO LEER LOS 4 ELEMENTOS DEL ARCHIVO: EL id,nombre,horasTrabajadas,sueldo
            {
                Employee* e= employee_newParametros(var1, var2, var3, var4); // ACA HAY QUE PASAR LOS STRING A SUS RESPECTIVOS FORMATOS Y GUARDALO EN LA LISTA

                ll_add(pArrayListEmployee,e); // SE CARGAN LOS DATOS GUARDADOS EN LA ESTRUCTURA EN LA LISTA!

            }

        }while(!feof(pFile));

        fclose(pFile); // CIERRA EL ARCHIVO SI EL PARSEO TERMINO!
        return 0;
    }
    else
    {
        printf("Error puntero null");
        fclose(pFile);
        return -1;
    }


}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char var1[50], var2[50] ,var3[50] ,var4[50]; // VARIABLES AUX EN Q SE ALMACENA LOS DATOS DEL ARCHIVO LEIDOS COMO STRING
    int readLine;

    FILE *pFileBinary;

    if((pFileBinary=fopen("BINARY-DATA","rb"))==NULL) // SE ABRE EL BINARIO EN LECTURA, SI ES NULL ES POR QUE NO EXISTE Y SE CREA
    {
        if((pFileBinary=fopen("BINARY-DATA","wb"))==NULL) // SI ES IGUAL A NULL O SEA LA PRIMERA VEZ SI NO EXISTE EL ARCHIVO DEVUELVE NULL, ENTONCES LO CREA
        {
            printf("\nEl archivo no puede ser abierto");
            fclose(pFile);
            return -1;
        }

        // SE CREO EL ARCHIVO BINARIO
    }

    readLine = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

    do {
            readLine = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

            if (readLine == 4)
            {
                Employee* e= employee_newParametros(var1, var2, var3, var4);

                fwrite(e, sizeof(Employee), 1, pFileBinary); //ESCRIBE EL ARCHIVO DE TEXTO PFILE EN EL BINARIO PBINARY FILE
                ll_add(pArrayListEmployee, e);
            }
            else
            {
                printf("LINEA CON CARACTERES ERRONEOS.\n");
                fclose(pFileBinary);
                fclose(pFile);
                return -1;
            }

    } while (!feof(pFile));

    fclose(pFileBinary);
    fclose(pFile);
    return 0;

}




