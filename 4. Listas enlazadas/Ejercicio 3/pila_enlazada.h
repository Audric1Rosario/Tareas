#include <stdlib.h>
#ifndef _pila_enlazada
#define _pila_enlazada

typedef struct nodo
{
   float valor;
   struct nodo *enlace;
} Nodo;

Nodo* crear_nodo(float elemento, Nodo *siguiente);
Nodo* push_nodo(Nodo *pila, float nuevo_dato);
Nodo* pop_nodo(Nodo *pila, float *valor);
float peek_nodo(Nodo *pila);

#endif // _pila_enlazada
