#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

 int main()
 {
     int opciones ;
     float operando1 = 0, operando2= 0; // igualados a cero para que se vea el numero al iniciar
     float sumar;
     float restar;
     float dividir;
     float multiplicar;
     int factorial1, factorial2; //para calcular el factorial de A y B.

     do
     {
         if (opciones!=4) // para que el comando borre la pantalla en todos los casos exceptuando la visualizacion de los resultados.
         {
            system("cls");
         }
        //desarrollo del menu principal
         printf( "\n ------------MENU--------------");
         printf(" \n\n 1.Ingresar 1er operando: (A=%.0f)", operando1);
         printf("\n 2.Ingresar 2do operando: (B=%.0f)", operando2);
         printf("\n 3.Calcular todas las operaciones:");
         printf("\n 4.Mostrar todos los resultados:");
         printf("\n 5.Salir");

         printf("\n \n Seleccionar opcion:");
         scanf("%d", &opciones);

         switch (opciones)
         {
             case 1:
                 printf(" Ingrese 1er operando:");
                 scanf("%f", &operando1);
                 break;
             case 2:
                 printf(" Ingrese 2do operando:");
                 scanf("%f", &operando2);
                 break;

             case 3: //calculo de los resultados!

                 sumar = suma(operando1, operando2);
                 restar = resta(operando1, operando2);

                 if (operando2 !=0)
                 {
                    dividir = division( operando1, operando2);
                 }
                 multiplicar = multiplicacion( operando1, operando2);
                 factorial1 = factorial (operando1);
                 factorial2= factorial(operando2);

                 break;

             case 4: //informe de los resultados!

                 printf("a) El resultado de A+B es: %0.2f", sumar);
                 printf("\n b) El resultado de A-B es:%0.2f", restar);
                 if (operando2!=0)
                 {
                     printf("\n c) El resultado de A/B es:%0.2f", dividir);
                 }
                 else
                 {
                     printf(" No es posible dividir por cero...");
                 }

                 printf("\n d) El resultado de A*B es:%0.2f", multiplicar);
                 printf("\n e) El factorial de A es: %d - El factorial de B es:%d ", factorial1, factorial2 );

                 break;

             default:
                 break;

         }
     } while ( opciones != 5); // salir del menu con la opcion 5.

     return 0;
 }

