#include <stdlib.h>

#ifndef _PilaEstatica
#define _PilaEstatica

typedef struct
{
   int tam;
   int *Pila;
   int pos[3];
   int cantidad;
   int lim[3];
} Pila;

Pila* IniciarPila();

void Push(Pila*, int, int);
int Pop(Pila*, int);
int Size(Pila*);
short isEmpty(Pila*, int);
int Peek(Pila*, int);

void VerificarEspacio(Pila *pila);

#endif // _PilaEstatica
