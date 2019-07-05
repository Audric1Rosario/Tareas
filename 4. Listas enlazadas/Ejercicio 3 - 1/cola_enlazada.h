#include <stdlib.h>

#ifndef _cola_enlazada
#define _cola_enlazada

typedef struct nodo
{
   int elemento;
   //int actual;
   //int elem;
   //int cantidad;
   struct nodo *enlace;
} Nodo;

typedef struct
{
   Nodo *inicio;
   Nodo *final;
} Cola;

Nodo* inicializar_nodo();
Cola* inicializar_cola();
void verificar_tam(Cola *miCola);
void encolar(Cola *miCola, int num);
int decolar(Cola *miCola);
int front_element (Cola *miCola);

#endif // _cola_enlazada
