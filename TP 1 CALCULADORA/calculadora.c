/**
* \brief Suma dos numeros ingresados desde la funcion main.
* \param float op1 primer numero a sumar desde main.
* \param float op2 segundo numero a sumar desde main.
* \return Retorna el resultado de la suma de los operandos anteriormente ingresados.
*
*/
 float suma (float op1, float op2)
 {
     float resultado;
     resultado=op1 + op2;
     return resultado;
 }

 /**
* \brief Resta dos numeros ingresados desde la funcion main.
* \param float op1 primer numero a restar desde main.
* \param float op2 segundo numero a restar desde main.
* \return Retorna el resultado de la resta de los operandos anteriormente ingresados.
*
*/
 float resta (float op1, float op2)
 {
     float resultado;
     resultado= op1 - op2;
     return resultado;
 }

 /**
* \brief Divide dos numeros ingresados desde la funcion main.
* \param float op1 numero dividendo pasado desde main.
* \param float op2 numero divisor pasado desde main.
* \return Retorna el resultado de la division de los operandos anteriormente ingresados.
*
*/
 float division (float op1, float op2)
 {
     float resultado;
     resultado = op1 / op2;
     return resultado;
 }

 /**
* \brief Multiplica dos numeros ingresados desde la funcion main.
* \param float op1 primer numero a multiplicar desde main.
* \param float op2 segundo numero a multiplicar desde main.
* \return Retorna el resultado de la multiplicacion de los operandos anteriormente ingresados.
*
*/
 float multiplicacion (float op1, float op2)
 {
     float resultado;
     resultado = op1 * op2;
     return resultado;
 }

  /**
* \brief Realiza el factorial de un numero ingresado desde la funcion main.
* \param int op1 numero a realizar el factorial desde main.
* \return Retorna el resultado del factorial del operando ingresado anteriormente.
*
*/
 int factorial (int op1)
 {
     int factorial=1;
     int contador;

     for (contador=1; op1 >= contador; contador ++ )
     {
         factorial= factorial * contador;
     }
     return factorial;
 }


