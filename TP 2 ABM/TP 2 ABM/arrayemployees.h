#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} Employee;


//  PARA INPUTS DE DATOS CON VALIDACION AVANZADA:

int utn_esNumericoAvanzada (char cadena []); // CONVIERTE EN ARRAY Y LO RECORRE CARACTER POR CARACTER PARA VALIDARLO...
int utn_getIntAvanzada(int* pResultado); // PARA GUARDAR EL DATO USANDO FGETS EN VES DE SCAN F...
int utn_getNumeroAvanzada(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos); // PARA OBTENER UN NUMERO VALIDADO, INCLUYE FUNCIONES ANTERIORES...

int utn_esDecimalAvanzada (char cadena []);
int utn_getFloatAvanzada(float* pResultado);
int utn_getNumeroConDecimalesAvanzada(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int utn_esStringAvanzada(char cadena []);
int utn_getStringAvanzada(char cadena []);
int utn_getCadenaDeCaracteresAvanzada(char cadena [], char* mensaje, char* mensajeError, int reintentos);

//FUNCIONES PROPIAS DEL TP

int initEmployees( Employee arrayEmployees [], int longitudArray);
int utn_buscarLugarVacioEpersona (Employee arrayEmployees [],int longitudArray); //ESTA OK PERO EMPROLIJAR LO DE EL RETORNO..

int addEmployee(Employee arrayEmployees [], int longitudArray, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee arrayEmployees [], int longitudArray, int id);
int removeEmployee(Employee arrayEmployees [], int longitudArray, int id);
int sortEmployees(Employee arrayEmployees [], int longitudArray, int orden);
int printEmployees(Employee arrayEmployees [], int longitudArray);

int printSalary(Employee arrayEmployees [], int longitudArray);

#endif
