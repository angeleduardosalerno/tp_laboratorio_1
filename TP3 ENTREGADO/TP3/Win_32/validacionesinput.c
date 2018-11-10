#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacionesinput.h"
#include "LinkedList.h"
#include "Employee.h"



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

 /** \brief Almacena el numero ingresado, luego de validar el dato, pide minimo (>= 1) pero no maximo.
 * \param int* pResultado Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
 * \param char* mensaje Mensaje a ser mostrado al usuario para que determine que dato desee ingresar.
 * \param char* mensajeError Mensaje a ser mostrado al usuario en caso de no ingresar un dato valido.
 * \param int minimo Numero minimo valido para ingresar.
 * \param int reintentos Reintentos brindados al usuario en caso de ingresar datos invalidos.
 * \return Devuelve 1 si pudo guardar el dato en *pResultado y 0 si no lo pudo guardar por no pasar la validacion.
 *
 */

 int utn_getNumeroAvanzadaSinMax(int* pResultado, char* mensaje, char* mensajeError, int minimo, int reintentos)
 {
     int retorno;
     int numero;

         if (pResultado!= NULL && mensaje != NULL && mensajeError != NULL && minimo >= 1 && reintentos >= 0)
         {
             while(reintentos>0)
             {
                 printf("%s", mensaje);

                 if(utn_getIntAvanzada(&numero)==1)
                 {
                     if(numero>=minimo)
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

/** \brief Verifica si el valor recibido es Alfanumerico (con al menos 1 letra, un espacio y un numero).
 * \param char cadena de caracteres a ser analizada.
 * \return Devuelve 1 si es Alfanumerico y 0 si no lo es.
 *
 */
 int utn_esAlfanumericoAvanzada (char cadena [])
 {
     int i=0, retorno, contadorLetras=0, contadorNumeros=0, contadorEspacios=0;

     while (cadena[i]!= '\0')
     {
         if ( (cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z') )
         {
             contadorLetras ++;
         }
         if ( (cadena[i] >= '0' && cadena[i] <= '9' ) )
         {
             contadorNumeros ++;
         }
         if ((cadena[i] == ' '))
         {
             contadorEspacios++;
         }

         if ((cadena[i]!= ' ' ) && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i]< 'A' && cadena[i]> 'Z') && (cadena[i] < '0' || cadena[i] > '9' ))
             retorno=0;

         i++;
     }

    if ((contadorLetras >= 1) && (contadorNumeros >= 1) && (contadorEspacios >= 1) && (retorno != 0))
        retorno=1;
    else
        retorno=0;

     return retorno;
 }

 /** \brief Almacena el dato Alfanuemerico ingresado (usando fgets en lugar de scanf)  luego de validar el dato como cadena de caracteres.
 * \param char cadena [] Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
 * \return Devuelve 1 si pudo guardar el dato en char cadena [] y 0 si no lo pudo guardar por no pasar la validacion.
 *
 */
 int utn_getAlfanumerico(char cadena [])
 {
     int retorno = 0;
     char buffer[20];

     if(cadena!=NULL)
     {
         fgets(buffer,sizeof(buffer),stdin);
         buffer[strlen(buffer)-1]='\0';

         if(utn_esAlfanumericoAvanzada(buffer))
         {
             strcpy(cadena, buffer);
             retorno = 1;
         }
     }
         return retorno;
 }

 /** \brief Almacena el telefono ingresado como char, luego de validar el dato.
 * \param char cadena [] Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
 * \return Devuelve 1 si pudo guardar el dato en char cadena [] y 0 si no lo pudo guardar por no pasar la validacion.
 *
 */

 int utn_getAlfanumericoAvanzada (char cadena [], char* mensaje, char* mensajeError, int reintentos)
 {
     int retorno;
     char alfaNumerico[20];

         if (cadena!= NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
         {
             while(reintentos>0)
             {
                 printf("%s", mensaje);

                 if(utn_getAlfanumerico(alfaNumerico)==1)
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
                 strcpy(cadena, alfaNumerico);
                 retorno=1;
             }
         }
             return retorno;
 }



 /** \brief Verifica si el valor recibido corresponde a las validaciones del numero de telefono.
 * \param char cadena de caracteres a ser analizada.
 * \return Devuelve 1 si es numerico y 0 si no lo es.
 *
 */
 int utn_esTelefonoAvanzada (char cadena [])
 {
     int i=0, contadorGuiones=0, contadorCaracteres=0;
     int  retorno;

     while (cadena[i]!= '\0')
     {
         contadorCaracteres++; //PARA QUE INGRESEN LA CANTIDAD ADECUADA DE CARACTERES...

         if (cadena[i]== '-')
         {
             contadorGuiones++;
         }

         if ((cadena[i] != '-') && (cadena[i] < '0' || cadena[i] > '9' ))
             retorno= 0;

         i++;
     }                           //OJO ACA MODIFICAR LOS CARACTERES SI ES TELEFONO LINEA 10 CARACTERES (YA ESTAN CONTADOS LOS 2 GUIONES), CELU 12 CARACTERES (YA ESTAN CONTADOS LOS 2 GUIONES)
         if ((contadorGuiones ==2) && (contadorCaracteres ==12) &&(retorno != 0)) // PARA QUE TENGA EN CUENTA UNICAMENTE SI LA CONDICION DE ARRIBA SE CUMPLE, SINO SE FIJA SOLO EN LOS GUIONES.
             retorno=1;
         else
             retorno=0;

         return retorno;

 }

 /** \brief Almacena el numero ingresado (usando fgets en lugar de scanf)  luego de validar el dato como cadena de caracteres.
 * \param char cadena [] Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
 * \return Devuelve 1 si pudo guardar el dato en char cadena [] y 0 si no lo pudo guardar por no pasar la validacion.
 *
 */
 int utn_getTelefono(char cadena [])
 {
     int retorno = 0;
     char buffer[20];

     if(cadena!=NULL)
     {

         fgets(buffer,sizeof(buffer),stdin);
         buffer[strlen(buffer)-1]='\0';

         if(utn_esTelefonoAvanzada(buffer))
         {
             strcpy(cadena, buffer);
             retorno = 1;
         }
     }
         return retorno;
 }

 /** \brief Almacena el telefono ingresado como char, luego de validar el dato.
 * \param char cadena [] Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
 * \return Devuelve 1 si pudo guardar el dato en char cadena [] y 0 si no lo pudo guardar por no pasar la validacion.
 *
 */

 int utn_getTelefonoAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos)
 {
     int retorno;
     char telefono[20];

         if (cadena!= NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
         {
             while(reintentos>0)
             {
                 printf("%s", mensaje);

                 if(utn_getTelefono(telefono)==1)
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
                 strcpy(cadena, telefono);
                 retorno=1;
             }
         }
             return retorno;
 }

 /** \brief Verifica si el valor recibido es numerico y si tiene 8 caracteres (dni).
 * \param char cadena de caracteres a ser analizada.
 * \return Devuelve 1 si es numerico y 0 si no lo es.
 *
 */
 int utn_esDniAvanzada(char cadena [])
 {
     int i=0, contadorCaracteres=0;
     int  retorno;

     while (cadena[i]!= '\0')
     {
         contadorCaracteres++; //PARA QUE INGRESEN LA CANTIDAD ADECUADA DE CARACTERES...

         if (cadena[i] < '0' || cadena[i] > '9' )
             retorno= 0;

         i++;
     }                           //OJO ACA MODIFICAR LOS CARACTERES EL DNI TIENE 8 DIGITOS
         if ((contadorCaracteres ==8) &&(retorno != 0)) // PARA QUE TENGA EN CUENTA UNICAMENTE SI LA CONDICION DE ARRIBA SE CUMPLE, SINO SE FIJA SOLO EN LOS GUIONES.
             retorno=1;
         else
             retorno=0;

         return retorno;

 }

 /** \brief Almacena el dni ingresado luego de validar el dato como cadena de caracteres.
 * \param char cadena [] Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
 * \return Devuelve 1 si pudo guardar el dato en char cadena [] y 0 si no lo pudo guardar por no pasar la validacion.
 *
 */
 int utn_getDni(char cadena [])
 {
     int retorno = 0;
     char buffer[15];

     if(cadena!=NULL)
     {

         fgets(buffer,sizeof(buffer),stdin);
         buffer[strlen(buffer)-1]='\0';

         if(utn_esDniAvanzada(buffer))
         {
             strcpy(cadena, buffer);
             retorno = 1;
         }
     }
         return retorno;
 }

 /** \brief Almacena el dni ingresado como char, luego de validar el dato.
 * \param char cadena [] Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
 * \return Devuelve 1 si pudo guardar el dato en char cadena [] y 0 si no lo pudo guardar por no pasar la validacion.
 *
 */

 int utn_getDniAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos)
 {
     int retorno;
     char dni[15];

         if (cadena!= NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
         {
             while(reintentos>0)
             {
                 printf("%s", mensaje);

                 if(utn_getDni(dni)==1)
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
                 strcpy(cadena, dni);
                 retorno=1;
             }
         }
             return retorno;
 }

 /** \brief Verifica si el valor recibido es numerico y si tiene 13 caracteres (CUIT 11 NUMEROS + 2 -).
 * \param char cadena de caracteres a ser analizada.
 * \return Devuelve 1 si es numerico y 0 si no lo es.
 *
 */
 int utn_esCuilAvanzada(char cadena [])
 {
     int i=0, contadorGuiones=0, contadorCaracteres=0;
     int  retorno;

     while (cadena[i]!= '\0')
     {
         contadorCaracteres++; //PARA QUE INGRESEN LA CANTIDAD ADECUADA DE CARACTERES...

         if (cadena[i]== '-')
         {
             contadorGuiones++;
         }

         if ((cadena[i] != '-') && (cadena[i] < '0' || cadena[i] > '9' ))
             retorno= 0;

         i++;
     }
         if ((contadorGuiones ==2) && (contadorCaracteres ==13) &&(retorno != 0)) // PARA QUE TENGA EN CUENTA UNICAMENTE SI LA CONDICION DE ARRIBA SE CUMPLE, SINO SE FIJA SOLO EN LOS GUIONES.
             retorno=1;
         else
             retorno=0;

         return retorno;

 }

 /** \brief Almacena el CUIL ingresado luego de validar el dato como cadena de caracteres.
 * \param char cadena [] Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
 * \return Devuelve 1 si pudo guardar el dato en char cadena [] y 0 si no lo pudo guardar por no pasar la validacion.
 *
 */
 int utn_getCuil(char cadena [])
 {
     int retorno = 0;
     char buffer[20];

     if(cadena!=NULL)
     {

         fgets(buffer,sizeof(buffer),stdin);
         buffer[strlen(buffer)-1]='\0';

         if(utn_esCuilAvanzada(buffer))
         {
             strcpy(cadena, buffer);
             retorno = 1;
         }
     }
         return retorno;
 }

 /** \brief Almacena el Cuil ingresado como char, luego de validar el dato.
 * \param char cadena [] Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
 * \return Devuelve 1 si pudo guardar el dato en char cadena [] y 0 si no lo pudo guardar por no pasar la validacion.
 *
 */

 int utn_getCuilAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos)
 {
     int retorno;
     char cuil [20];

         if (cadena!= NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
         {
             while(reintentos>0)
             {
                 printf("%s", mensaje);

                 if(utn_getCuil(cuil)==1)
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
                 strcpy(cadena, cuil);
                 retorno=1;
             }
         }
             return retorno;
 }

 /** \brief Verifica si el valor recibido es MAIL y si tiene caracteres o numeros y si o si un @, un punto, en minuscula y sin espacios.
 * \param char cadena de caracteres a ser analizada.
 * \return Devuelve 1 si es numerico y 0 si no lo es.
 *
 */
 int utn_esMailAvanzada(char cadena [])
 {
     int i=0, contadorPuntos=0, contadorA=0;
     int  retorno;

     while (cadena[i]!= '\0')
     {
         if (cadena[i]== '.')
         {
             contadorPuntos++;
         }
         if (cadena[i]== '@')
         {
             contadorA++;
         }

         if ((cadena[i] != '-') && (cadena[i] < '0' || cadena[i] > '9') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] != '_') && (cadena[i] != '.') && (cadena[i] != '@')) //TODO LO Q PUEDE CONTENER EL MAIL
             retorno= 0;

         i++;
     }
         if ((contadorPuntos >= 1) && (contadorA==1) &&(retorno != 0)) // PARA QUE TENGA EN CUENTA UNICAMENTE SI LA CONDICION DE ARRIBA SE CUMPLE, SINO SE FIJA SOLO EN LOS GUIONES.
             retorno=1;
         else
             retorno=0;

         return retorno;

 }

 /** \brief Almacena el CUIL ingresado luego de validar el dato como cadena de caracteres.
 * \param char cadena [] Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
 * \return Devuelve 1 si pudo guardar el dato en char cadena [] y 0 si no lo pudo guardar por no pasar la validacion.
 *
 */
 int utn_getMail(char cadena [])
 {
     int retorno = 0;
     char buffer[25];

     if(cadena!=NULL)
     {

         fgets(buffer,sizeof(buffer),stdin);
         buffer[strlen(buffer)-1]='\0';

         if(utn_esMailAvanzada(buffer))
         {
             strcpy(cadena, buffer);
             retorno = 1;
         }
     }
         return retorno;
 }

 /** \brief Almacena el MAIL ingresado como char, luego de validar el dato.
 * \param char cadena [] Variable donde se debe almacenar el dato, y donde retorna el mismo en caso de ser correcto.
 * \return Devuelve 1 si pudo guardar el dato en char cadena [] y 0 si no lo pudo guardar por no pasar la validacion.
 *
 */

 int utn_getMailAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos)
 {
     int retorno;
     char mail [25];

         if (cadena!= NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
         {
             while(reintentos>0)
             {
                 printf("%s", mensaje);

                 if(utn_getMail(mail)==1)
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
                 strcpy(cadena, mail);
                 retorno=1;
             }
         }
             return retorno;
 }



 // FUNCIONES DESPUES DEL PRIMER PARCIAL: ------------------------------------------------------------------------------------------------>

  /** \brief OBTIENE UNA CADENA DE CARACTERES CON RESERVA DE MEMORIA DINAMICA.
 * \param char* message MENSAJE A SER MOSTRADO, PIDIENDO EL INGRESO DEL TEXTO DESEADO DESDE EL MAIN.
 * \return char* DEVUELVE UN PUNTERO A CHAR, CON LA DIRECCION DE MEMORIA DONDE ESTA LOCALIZADA EL STRING INGRESADO. SE DEBE LIBERAR DESPUES CON FREE () OJOOO!
 *
 */

 char* getDynamicString (char* message)
 {
     char* auxString; // LA DIFERENCIA CON EL VIDEO ES Q ACA EL LA CREABA Y LA IGUALABA DIRECTAMENTE CON MALLOC
     int leng;

     printf(message);

     auxString= (char*) malloc(sizeof(char)*1024); // le asigna 1k aprox de memoria para guardar, se le asigna de mas y con realloc eliminas el sobrante.

     scanf("%1023s", auxString);// se le deja un byte libre para el final de cadena?

     leng=strlen(auxString);

     auxString= (char*) realloc (auxString, sizeof(char) * (leng +1)); // se le suma 1 por q strlen no incluye el ultimo caracter de \0...

     return auxString;

 }
