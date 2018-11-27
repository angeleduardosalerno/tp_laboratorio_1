#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validacionesinput.h"
#include "parser.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this; // CREA UNA VARIABLE THIS DE TIPO LINKED LIST

    this = (LinkedList *)malloc(sizeof(LinkedList)); // LE ASIGNAS MEMORIA DINAMICA A LA LISTA

    if(this != NULL)
    {
        this->size=0; // ACA INICIALIZA LA LISTA! --- EL TAMANO ES IGUAL A 0 POR QUE ESTA VACIA LA LISTA!
        this->pFirstNode = NULL; // EL PRIMER NODO APUNTA A NULL, ES UNA INICIALIZACION, YA QUE NO TIENE NADA CARGADO...
                                    //LE ASIGNA NULL COMO DIRECCION DE MEMORIA...PARA QUE EL PUNTERO NO TENGA BASURA Y SE TILDE
    }

    return this; // DEVUELVE EL PUNTERO A LINKED LIST CON LA MEMORIA ASIGNADA DINAMICAMENTE, EL SIZE EN 0 Y EL PRIMER NODO APUNTANDO A NULL....
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux=this->size;

    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL; // INICIALIZA LA ESTRUCTURA NODE EN NULL!! OJOOO NO ES ESTO ASI, ACA LO USA COMO RETORNAR EL ERROR SUPER IMP, SINO SE CARGA EN EL IF POR UN ERROR, EL RETORNO ES NULL...!!SUP IMP!
    // LO USA COMO RETORNAR EL ERROR SUPER IMP -------- COMO ES EL PRIMER NODO LO INICIALIZA EN NULL PARA EVITAR QUE LEA LA BASURA... p DE PUNTERO AL NODO
    int i;

    if (this != NULL && ll_len(this) > 0 && nodeIndex >= 0 && nodeIndex < ll_len(this)) // ES SENSIBLE A LAS CONDICIONES TIENE Q ESTAR PERFECTO EL MAYOR IGUAL...
    {
        pNode = this->pFirstNode; //  O SEA, LA DIRECCION DE MEMORIA ASIGNADA A VA SER IGUAL A LA ESTRUCTURA P FIRSTNODE DE LINKEDLIST.
                                    // GAURDA EL NODO TOMADO DE LINKED LIST EN ESTE NODO CREADO, COMO SI FUERA UNA VAR AUX...
                                    //ACA GUARDA TODA LA LISTA LINKED LIST EN ESTE NUEVO NODO, POR ESO SE PUEDE RECORRER DESPUES!
                                    //-----------> ENTENDERLO DE FORMA GENERAL ACA LO QUE DICE ES QUE EL PRIMER NODO, VA A SER EL P NODE!!!!

        for (i=0 ; i < nodeIndex ; i++) // DESPUES SE METE DENTRO DEL NODO CRADO ACA, EN UN EJ HACIAN UN WHILE Q ERA WHILE( NODE->NEXTNODE)
        {
            pNode=pNode->pNextNode; // HACE UN FOR QUE RECORRE...PERO NO RELLENA NADA, TE VA A DEVOLVER EL ULTIMO ELEMENTO ANTES DEL INDICE...
                                    //LO QUE HACE ES RECORRER LA ESTRUCTURA NODO HASTA LLEGAR AL INDICE, YA QUE SE MUEVE POR DICHA ESTRUCTURA...
                                    //ESTA ES LA FORMA PARA RECORRER LOS NODOS
                                    // P NODE ES IGUAL A LA DIR DE MEMORIA DE NEX NODE, PARTIENDO DE ESA DIR DE MEMORIA, SE VA AL OTRO NODO ETC...
        }
    }

    return pNode; // VOS CREAS UN NODO NUEVO Y LO GUARDAS SEGUN EL INDICE QUE TE INDIQUEN... LO QUE TE DEVUELVE ES EL P ELEMENT Y EL PNEXT NODE EN LA POSICION BUSCADA
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement) // ESTO ES LA FUNCION PUSH......SE LLAMA PUSH POR QUE ELL PRIMER NODO SE EMPUJA HASTA EL FINAL...
{
    int returnAux = -1;

    Node* newNode = malloc(sizeof(Node)); // CREA UNA ESTRUCTURA NODE LLAMADA NEW NODE Y LE ASIGNA MEMORIA DINAMICA!-----SE CREA EL NUEVO NODO A SER AGREGADO!!

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) // VALIADS EL INDEX
    {
        if(this->pFirstNode == NULL && nodeIndex == 0) // EN LA PRIMERA POSICION, LA 0, o sea si no hay datos el puntero de la lista tiene q estar en null!! SI P FIRSNODE ESTA EN NULL SIGNIFICA QUE NO HAY ELEMENTOS GUARDADOS!
        {
            this->pFirstNode = newNode; // COPIA LA INFORMACION DE LA ESTRUCTURA NEW NODE DEL PUNTO ANTERIOR DENTRO DE LA LINKED LIST
                                        //ACA ESTA AGREGANDO EL NODO NUEVO A LA LINKED LIST
                                        //ACORDARSE QUE ESTABA INICIALIZADA EN NULL ACA!!!----
                                        //MI DUDA ACA ES SI COPIA LA ESTRUCTURA ENTERA O LO Q COPIA ES SOLO LA DIR DE MEMORIA---------------!
                                        //PARECE SER Q DICE P FIRST NODE APUNTA A NUEVO NODO Y DESPUES EL ENTRA A NUEVO NODO Y LA CARGA...!

            newNode->pElement = pElement; // LE ASIGNA AL ELEMENTO DEL NUEVO NODO P ELEMENT EL ELEMENTO PASADO COMO PARAMETRO!!

            this->size = ll_len(this) + 1; // LE AGREGA UNO AL TAMAÑO DE LA LISTA LINKED LIST!

            returnAux = 0; // SALE DE ACA CON LA ESCTRUCTURA NUEVO NODO CON EL ELEMENTO GUARDADO...
        }
        //NO ENTIENDO NO ESTAS AGREGANDO 2 NODOS ACA??
        else if(this->pFirstNode != NULL && nodeIndex == 0) // ADEMAS ENTRA ACA! --- o SEA SI ES CERO ANTES LO INICIALIZA Y DESPUES ENTRA ACA...
        {
            Node* oldFirstNode = this->pFirstNode; // COPIA LA DIRECCION DE MEMORIA DEL NODO NUEVO ANTERIOR EN EL NODO VIEJO Y CREA OTRO NUEVO...
                                                    //ACA NO LE ASIGNO MEMORIA DINAMICA, UNICAMENTE GUARDA LA DIR DE MEMORIA...
                                                    //EL NECESITABA MANTENER ESTO ACA PARA AIGNARLE LA DIR DE MEMORIA DEL PRIMER NODO Q ES EL NEW NODE
                                                    //ACA ESTA ALMACENADA LA DIRECCION DE MEMORIA CON EL ELEMENTO GUARDADO
                                                    //ACA HACE QUE EL VIEJO NODO APUNTE HACIA P FIRST NODE
                                                    //Y COMO COPIO LA DIR DE MEMORIA DONDE ESTABA GUARDADO LOS DATOS DEL NUEVO NODO LA INFO NO SE PIERDE

            this->pFirstNode = newNode; // COPIA LA ESTRUCTURA NEW NODE DEL PUNTO ANTERIOR DENTRO DE LA LINKED LIST
                                        //ACA AGREGA OTRO NODO A LA LINKED LIST, YA VAN 2

            this->pFirstNode->pNextNode = oldFirstNode; // ACA LE DICE QUE LA DIRECCION DE MEMORIA DEL NODO SIGUIENTE ES LA DEL ANTERIOR... O SEA EL PRIMER NODO VA A PASAR A SER EL ULTIMO DE LA LISTA!!
                                                        // ACA COPIA LA ESTRUCTURA DEL VIEJO NODO.
                                                        //ENTONCES TE QUEDA EL NUEVO EN PFIRST NODE Y EL VIEJO EN P NEXT NODE

            newNode->pElement = pElement; // LE ASIGNA AL ELEMENTO DEL NUEVO NODO P ELEMENT EL ELEMENTO PASADO COMO PARAMETRO!!

            this->size = ll_len(this) + 1; // LE AGREGA UNO AL TAMAÑO DE LA LISTA LINKED LIST!

            returnAux = 0;
        } //ESTAS OP LAS HACE CUANDO ES EL PRIMER NODO, O SEA EL 0------------------------------------------------------

        else if(this->pFirstNode != NULL && nodeIndex > 0 && nodeIndex < ll_len(this)) // ACA ENTRA SI EL INDEX ES MAYOR A CERO!!************
        {
            Node* oldNodeInIndex = getNode(this,nodeIndex); // VIEJO NODO EN LA POSICION DEL INDEX, LO TOMA CON GET Y GUARDA LOS DATOS EN ESA POSICION DE MEMORIA.

            newNode->pNextNode = oldNodeInIndex; // EMUJA PUSH ESE NODO PARA ATRAS, EL NUEVO NODO VA A APUNTAR AL VIEJO

            Node* previousNode = getNode(this,nodeIndex - 1); // NODO ANTERIOR!! AL INDICE LE RESTA UNO Y SACA EL ANTERIOR

            previousNode->pNextNode = newNode; // ACA LO QUE HACE ES QUE EL NODO ANTERIOR APUNTE HACIA EL NUEVO -----------------------------> ESTO ES APUNTAR HACIA ESA DIR DE MEMORIA
            //-------------------------------------------------------------
            newNode->pElement = pElement;

            this->size = ll_len(this) + 1;
            returnAux = 0;
        } // ENTONCES TE QUEDA EN NUEVO QUE APUNTA HACIA EL QUE SE MOVIO Y EL ANTERIOR AL NUEVO LO APUNTA EL ANTERIOR A ESTE.

        else if(this->pFirstNode != NULL && nodeIndex == ll_len(this)) // SI EL INDICE ES IGUAL A LA LONGITUD DE LA LISTA O SEA SI ES EL ULTIMO
        {
            Node* lastNode = getNode(this,nodeIndex - 1); // ULTIMO NODO TOMA EL NODO DEL ANTEULTMO, POR QUE NO TOMA EL ULTIMO?? ESTARA RELACIONADO CON LA CREACION DE LOS PRIMEROS 2?
            lastNode->pNextNode = newNode; // EL NODO ANTEULTIMO APUNTA AL ULTIMO QUE ES EL QUE CREA
            newNode->pElement = pElement;

            this->size = ll_len(this) + 1;
            returnAux = 0;
        }
    }

    return returnAux;

}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista ------AGREGA UN NODO, YA QUE LOS NODOS CONTIENEN LOS ELEMENTOS!
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len; // TAMAÑO DE LA LISTA!

    len = ll_len(this); // SE OBTIENE EL TAMAÑO DE LA LISTA, Y SE USA COMO INDEX EN LA FUNCION ADD

    if(this!= NULL)
    {
        addNode(this,len,pElement); // SE USA LA FUNCION ADD PARA AGREGAR UN NODO, Y EL NODO SE LE AGREGA EN EL ULTIMO INDEX...

        returnAux = 0;
    }

    return returnAux;

}

/** \brief OBTEIENE EL PUNTERO AL ELEMENTO, ALMACENADO EN EL NODO,  EN EL INDICE INDICADO
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int len = ll_len(this);
    Node* nodeToGet;

    if(this!= NULL && index >= 0 && index < len )
    {
        nodeToGet = getNode(this, index);
        //returnAux= nodeToGet;  -------------no es asi, hay que devolver el elemento, el dato guardado q es lo que importa del nodo, LA INFO QUE GUARDA!
        return nodeToGet->pElement; // RETORNA LA INFORMACION GUARDADA DEL NODO

    }
    return returnAux; // EL RETORNO ES VOID POR QUE P ELEMT ES UN PUNTERO A VOID...
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this); // TAMAÑO DE LA LISTA

    Node* nodeToSet = getNode(this,index);; // CREA UNA ESTRUCTURA NODO

    if(this != NULL && index >= 0 && index < len && len > 0)
    {
        nodeToSet->pElement = pElement; // ES EL ELEMENTO A MODIFICAR, EL PUNTERO A LOS DATOS CARGADOS LO QUE SE MODIFICA!

        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    // ACA LO Q HAY QUE TENER EN CUENTA ES QUE SI SE BORRA UN NODO HAY QUE HACER LAS CONEXIONES CON EL SIGUIENTE!!
    int returnAux = -1;

    Node* nodeToRemove = getNode(this,index); // OBTENES EL NODO QUE SE DESEA REMOVER...

    if(this != NULL && index >= 0 && index < ll_len(this)) // HACES LAS VERIFICACIONES
    {
        if(index == 0) // SI EL INDICE ES IGUAL A O / O SEA SI NO HAY NINGUNO...
        {
            this->pFirstNode = nodeToRemove->pNextNode; // ACA LO BORRAS DE LA LISTA! HACES Q LA LISTA APUNTE A ESE ESPACIO DE MEMORIA Y LO BORRAS
            free (nodeToRemove); // ENTONCES EL PRIMER NODO VA A APUNTAR AL QUE APUNTABA EL NODO QUE SE VA A ELIMINAR!

            this->size = ll_len(this) - 1; // LE RESTAS UNO AL TAMAÑO DE LA LSITA
            returnAux = 0;
        }

        else if(index > 0) // EN EL CASO DE QUE SEA MAS DE 1 ELEMENTO EN LA LISTA!
        {
            Node* previousNode = getNode(this,index - 1); // SE OBTIENE EL NODO PREVIO
            previousNode->pNextNode = nodeToRemove->pNextNode; // AL NODO PREVIO LO APUNTA HACIA EL NODO QUE APUNTABA EL QUE SE ELIMINA ASI NO SE ROMPE LA LISTA
            free(nodeToRemove); // Y REMUEVE EL NODO Y LA LISTA SIGUE ARMADA!

            this->size = ll_len(this) - 1;
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int len = ll_len(this); //TAMAÑO DE LA LISTA

    if(this != NULL)
    {
        for(i = 0;i < len;i++)
        {
            ll_remove(this,i); // REMUEVE UNO POR UNO...USANDO LA FUNCION ANTERIOR!
        }

        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista EN SI MISMA!!
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(ll_clear(this)==0) // SI SE PUDO LIBERAR TODA LA LISTA INTERNAMENTE RETORNA 0
        {
            free(this); // UNA VEZ LIBERADO LOS INDICES, LIBERA LA LISTA ENTERA...
            returnAux = 0;
        }
        else if (ll_clear(this)==1) // SINO SE PUDO LIBERAR LA LISTA INTERNAMENTE, DA ERROR...
        {
            returnAux= 1;
        }
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int len = ll_len(this);
    Node* auxNode;

    if(this!=NULL)
    {
        for(i = 0;i < len; i++) // RECORRE LA LISTA
        {
            auxNode = getNode(this,i); // TOMA LA DIRECCION DE MEMORIA DEL NODO DETERMINADO

            if(auxNode ->pElement == pElement) // Y SI EL DATO DENTRO DEL NODO ES IGUAL AL DEL ELEMENTO RETORNA LA POSICION..
            {
                returnAux = i;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL && this->size == 0)
    {
        returnAux = 1;
    }
    else if(this != NULL && this->size > 0)
    {
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement) // LO UNICO QUE SE HACE EN ESTA FUNCION ES LLAMAR A ADDNODE, SE LLAMAN IGUALES POR QUE UNA LA LLAMA Y OTRA HACE LA LOGICA
{
    int returnAux = -1;

    if(this!=NULL && index >= 0 && index <= ll_len(this))
    {
        addNode(this,index,pElement);
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero (AL DATO ALMACENADO)
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL; // lo apunta a null inicializandolo en error, SI ESTA OK CAMBIA ADENTRO!

    void* auxElement;

    if(this!=NULL && index >= 0 && index < ll_len(this))
    {
        auxElement = ll_get(this,index);
        ll_remove(this,index);

        returnAux = auxElement;
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 0;

        if(ll_indexOf(this,pElement)!= -1) // SI ESTA OK LA FUNCION
        {
            returnAux = 1; // CONTIENE AL ELEMENTO
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this, LinkedList* this2) // COMPARA LA LISTA 2 CON LA PRIMERA!
{
    int returnAux = -1;
    int i;
    void* pElement; // PUNTERO DE TIPO VOID, EL CUAL ES EL TIPO DEL PUNTERO DE LOS ELEMENTOS GUARDADOS!

    if(this != NULL && this2 != NULL)
    {
      returnAux = 1;

      for(i = 0; i < ll_len(this2); i++) // RECORRES LA LISTA THIS 2 ELEMENTO POR ELEMENTO
      {
         pElement = ll_get(this2,i); // RECORRE CADA ELEMENTO DE LA LISTA 2

         if(ll_contains(this,pElement)==0) // SINO CONTIENE EL ELEMENTO
         {
             returnAux = 0; //DEVUELVE 0
         }
      }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{

    void *pElement;
    int i;
    LinkedList* cloneArray = NULL;

    if(this != NULL && from >= 0 && to <= this->size)
    {
        cloneArray = ll_newLinkedList(); // CREA UNA NUEVA LINKED LIST!

        for(i=from;i < to;i++) // EN EL FOR VA EL DESDE Y EL HASTA
        {
            pElement = ll_get(this,i); //ADQUIERE LOS ELEMENTOS GUARDADOS
            ll_add(cloneArray,pElement); // Y LOS COPIA A LA LISTA DE PUNTEROS!
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    int i;
    Node* auxNode = NULL;
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
        cloneArray = ll_newLinkedList();

        for(i = 0 ; i < ll_len(this); i++) // RECORRES LA LISTA
        {
            auxNode = ll_get(this,i); //GUARDAS NODO POR NODO EN EL NODO AUXILIAR
            ll_add(cloneArray,auxNode); // AGREGAS LOS NODOS A LA LISTA CLONADA
        }
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order) // EL PUNTERO A FUNCION LO UNICO QUE HACE 2 GET DE 2 ELEMENTOS DE LA LISTA Y DEVUELVE 1 SI ES MAYOR Y -1 SI ES MENOR
{
    int returnAux = -1;
    int i;
    int flagSwap;

    Node* auxNode;

    if(this != NULL && ll_len(this)> 0 && pFunc != NULL && (order == 1 || order == 0))
    {
        do
        {
            i = 0;
            auxNode = getNode(this,i); // GUARDA EN LA VARIABLE AUX NODO LOS NODOS TOMADOS DE LA LISTA
            flagSwap = 0; // BANDERA EN 0

            for(i=0;i<ll_len(this)-1;i++) // RECORRE LA LISTA - 1
            {
                if(i!= 0)
                {
                    auxNode = auxNode->pNextNode; // LO QUE DICE ES, EL NODO AUXILIAR ES EL QUE ESTABA APUNTANDO AUX NODE**********
                }                                                                           //LA IDEA ES ENTRAR AL PUNTERO AL ELEMENTO, DONDE ESTAN GUARDADOS LOS EMPLEADOS Y DE AHI OBTENER LOS NOMBRES PARA COMPARARLOS!
                                    //LA IDEA DE ACA ES IR COMPARANDO ENTRE DOS *****ELEMENTOS***** DE NODOS DISTINTOS !!! SI ELIGEN 0 DESCENDENTE Y SI ELIGEN UNO ASCENDENTE
                if((order == 0 && auxNode->pElement != NULL && auxNode->pNextNode->pElement != NULL && (*pFunc)(auxNode->pElement,auxNode->pNextNode->pElement)== -1)|| //ESTE ES UN ORDENAMIENTO DESCENDENTE ES 0 ---DE MAYOR A MENOR-- LA FUNCION DE ORDENAMIENTO DEVUELVE -1 SI EL ELEMENTO A ES MAS CHICO QUE EL B
                   (order == 1 && auxNode->pElement != NULL && auxNode->pNextNode->pElement != NULL && (*pFunc)(auxNode->pElement,auxNode->pNextNode->pElement)== 1)) // ESTE ES UN ORDENAMIENTO ASCENDENTE ES 1 --DE MENOR A MAYORL---A FUNCION DE ORDENAMIENTO DEVUELVE 1 EL ELEMENTO A ES MAS GRANDE QUE EL B
                {
                   flagSwap = 1; // CAMBIA LA BANDERA
                   ll_reOrder(this,auxNode); // REORDENA LA LISTA -----LE PASA COMO NODO ANTERIOR EL AUX NODE, QUE TENIA GUARDADO AL SIGUIENTE
                }
            }
        }
        while(flagSwap == 1);
        returnAux = 0;
    }
    return returnAux;

}


/** \brief Algoritmo que reordena los nodos.
 * \param pList LinkedList* Puntero a la lista
 * \param pNodePrev Es el primer nodo que se va a intercambiar, el segundo lo obtenemos de su pNextNode...
 * \return int Retorna (-1) Error: si el puntero a la lista es NULL o alguno de los nodos es NULL. (0) Si ok
 */

int ll_reOrder(LinkedList* this, Node* pNodePrev)
{
    int returnAux = -1;
    void* auxElement = NULL;

    Node* pNodeSiguiente = pNodePrev->pNextNode; // ACA SE GUARDA EL NODO SIGUIENTE DEL PASADO COMO PARAMETRO

    if(this != NULL && pNodePrev != NULL && pNodeSiguiente != NULL)
    {
        auxElement = pNodePrev->pElement; // GUARDAS EN UNA VAR AUX EL ELEMENTO DEL NODO SIGUIENTE

        pNodePrev->pElement = pNodeSiguiente->pElement; // SE HACE UN SWAP DE LOS ELEMENTOS

        pNodeSiguiente->pElement = auxElement;

        returnAux = 0;
    }
    return returnAux;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */

 /*
int ll_map(LinkedList* this, int (*pFunc)(void* ,void*))
{





}
*/
