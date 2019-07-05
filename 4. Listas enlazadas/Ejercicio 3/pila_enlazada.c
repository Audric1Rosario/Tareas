#include "pila_enlazada.h"
#include <stdlib.h>
// Desarrollar:
const Nodo* cabeza = NULL;
Nodo* crear_nodo(float elemento, Nodo *siguiente)
{
   Nodo* dato = (Nodo*)malloc(sizeof(Nodo));
   dato->valor = elemento;
   dato->enlace = siguiente;

   return dato;
}

Nodo* push_nodo(Nodo *pila, float nuevo_dato)  // Devuelve la cabeza del primero
{
   Nodo* nuevo_nodo = crear_nodo(nuevo_dato, pila);
   return nuevo_nodo;
}

Nodo* pop_nodo(Nodo *pila, float *valor)
{
   *valor = pila->valor;
   return pila->enlace;
}

float peek_nodo(Nodo *pila)
{
   float answer;
   pila = pop_nodo(pila, &answer);
   pila = push_nodo(pila, answer);
   return answer;
}
