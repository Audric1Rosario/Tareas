#include <stdlib.h>

#ifndef _colas
#define _colas

typedef struct
{
   float* elements;
   int first;
   int last;
   int array_size;
   int cantidad;
} cola;

cola* startQueue();
void changeSpace(cola* colas);
short isEmpty(cola* colas);
float getFront(cola* colas);
void enqueue(cola* colas, float element);
float dequeue(cola* colas);
int sizequeue(cola* colas);

#endif // _colas
