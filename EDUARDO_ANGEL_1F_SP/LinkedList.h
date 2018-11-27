#ifndef __LINKEDLIST
#define __LINKEDLIST       //= p PUNTERO ELEMENT = AL ELEMENTO!!
                        //EN EL TP3 CALCULO QUE ACA SE GUARDAN LOS PUNTEROS QUE APUNTAN HACIA LOS DATOS DE EMPLOYEE!!!!!!!!!!
struct Node             //NODO DONDE ESTAN LOS DATOS, EL INDEX TE ENVIA SU DIR DE MEMORIA CON LL GET
{
    void* pElement;
    //ESTE ES EL DATO DEL NODO, QUE COMO PUEDE SER DE CUALQUIER TIPO INT CHAR ETC, LO CREARON VOID...*******************************
    struct Node* pNextNode; // NODO SIGUIENTE, O SEA EL NODO SON LOS DATOS GUARDADOS, LOS ELEMENTOS PAS LOS PUNTEROS!!
    //ESTE ES EL PUNTERO QUE SEÑALA HACIA EL SIGUIENTE NODO DE LA LISTA!!!!********************************* TIENE Q SER UNA ESTRUCTURA POR QUE EL QUE SIGUE TAMBIEN ES UN NODO!

}typedef Node; // SON LOS NODOS QUE APUNTAN HACIA ADELANTE O ATRAS EN LA LISTA DE PUNTEROS.

struct LinkedList
{
    Node* pFirstNode; // PRIMER NODO DE LA LISTA VER BIEN! ESTE ES EL NODO DE LA LISTA, que apunta al siguiente, despues los otros tambien se llaman pfirst node por q no se puede cambiar la desc...
    int size; // TAMAÑO DE LA LISTA!

}typedef LinkedList; // ESTA ES LA LISTA DE PUNTEROS PROPIAMENTE DICHA.

#endif



//Publicas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this);
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);
void* ll_get(LinkedList* this, int index);
int ll_set(LinkedList* this, int index,void* pElement);
int ll_remove(LinkedList* this,int index);
int ll_clear(LinkedList* this);
int ll_deleteLinkedList(LinkedList* this);
int ll_indexOf(LinkedList* this, void* pElement);
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index);
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this);
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
int ll_reOrder(LinkedList* this, Node* pNodePrev);
