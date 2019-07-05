#include <stdlib.h>

#ifndef _PilaEstatica
#define _PilaEstatica

typedef struct
{
   int tam;
   float *Pila;
   int pos;
} Pila;

Pila* IniciarPila();

void Push(Pila*, float);
float Pop(Pila*);
int Size(Pila*);
short isEmpty(Pila*);
float Peek(Pila*);

void VerificarEspacio(Pila *pila);

#endif // _PilaEstatica
