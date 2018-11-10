#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_newEmployee(); // MIRAR LA DE ABAJO POR COMO UTILIZAR EL PUNTERO Q DEVUELVE, VER SI NO FUNCIONA DIRECTAMENTE!
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr); //FUNCION INICIALIZAR PARA USAR DENTRO DEL PARSEO DE DATOS
Employee* employee_newParametrosAddEmployee(int id, char* nombreStr, int horasTrabajadas, int sueldo);

// ACA ESTABA EL PROBLEMA, DENTRO DE ESTA FUNCION TENES Q CREAR LA NEW PERSONA...
int employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id); // OJOOO LAS FUNCIONES GET LE PASAN COMO PARAMETRO EL PUNETO AL ID YO LA TENIA SIMPLE int employee_getId(Employee* this); OJOOO VER!

int employee_setNombre(Employee* this,char* nombre);
int employee_getName(Employee* this, char* nombre);  // OJOOO LAS FUNCIONES GET LE PASAN COMO PARAMETRO EL PUNETO AL ID YO LA TENIA SIMPLE int employee_getId(Employee* this); OJOOO VER!
//ACA RETORNAN UN ENTERO, VER SI ESTA OK POR QUE EL NOMBRE ES CHAR!!

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHours(Employee* this,int* horasTrabajadas);  // OJOOO LAS FUNCIONES GET LE PASAN COMO PARAMETRO EL PUNETO AL ID YO LA TENIA SIMPLE int employee_getId(Employee* this); OJOOO VER!

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);  // OJOOO LAS FUNCIONES GET LE PASAN COMO PARAMETRO EL PUNETO AL ID YO LA TENIA SIMPLE int employee_getId(Employee* this); OJOOO VER!

void employee_free(Employee* this); // PARA LIBERAR MEMORIA DE LA ESTRUCTURA EMPLOYEE
int employee_sortByName(void* thisA,void* thisB); //VER BIEN ACA QUE HACE!

#endif // employee_H_INCLUDED
