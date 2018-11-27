#ifndef VALIDACIONESINPUT_H_INCLUDED
#define VALIDACIONESINPUT_H_INCLUDED

 //  PARA INPUTS DE DATOS CON VALIDACION AVANZADA:

 int utn_esNumericoAvanzada (char cadena []); // CONVIERTE EN ARRAY Y LO RECORRE CARACTER POR CARACTER PARA VALIDARLO...
 int utn_getIntAvanzada(int* pResultado); // PARA GUARDAR EL DATO USANDO FGETS EN VES DE SCAN F...
 int utn_getNumeroAvanzada(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos); // PARA OBTENER UN NUMERO VALIDADO, INCLUYE FUNCIONES ANTERIORES...
 int utn_getNumeroAvanzadaSinMax(int* pResultado, char* mensaje, char* mensajeError, int minimo, int reintentos);

 int utn_esDecimalAvanzada (char cadena []);
 int utn_getFloatAvanzada(float* pResultado);
 int utn_getNumeroConDecimalesAvanzada(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

 int utn_esStringAvanzada(char cadena []);
 int utn_getStringAvanzada(char cadena []);
 int utn_getCadenaDeCaracteresAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos);

 int utn_esAlfanumericoAvanzada (char cadena []);
 int utn_getAlfanumerico(char cadena []);
 int utn_getAlfanumericoAvanzada (char cadena [], char* mensaje, char* mensajeError, int reintentos);

 int utn_esTelefonoAvanzada (char cadena []);
 int utn_getTelefono(char cadena []);
 int utn_getTelefonoAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos); //ingresar como telefono como char

 int utn_esDniAvanzada (char cadena []);
 int utn_getDni(char cadena []);
 int utn_getDniAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos); // ingresar dni como char son 8 digitos, no acepta.

 int utn_esCuilAvanzada (char cadena []);
 int utn_getCuil(char cadena []);
 int utn_getCuilAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos);//RECIBE EL CUIL COMO CADENA DE CARACTERES

 int utn_esMailAvanzada (char cadena []);
 int utn_getMail(char cadena []);
 int utn_getMailAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos); //RECIBE MAIL COMO CADENA DE CARACTERES.

 //DESPUES DEL PRIMER PARCIAL: -------------------------------> :

 //MEMORIA DINAMICA:

 char* getDynamicString (char* message); // PROBAR PARA VER SI ESTA OK


 #endif
