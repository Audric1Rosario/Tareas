#include <stdlib.h>

#ifndef _colas
#define _colas

typedef enum
{
   perro = 1,
   gato = 2,
   nada = -1
} Animales;

typedef struct
{
   char* nombre;
   Animales tipo;
} animal;

typedef struct
{
   animal* elements;
   int first;
   int last;
   int array_size;
   int cantidad;
} cola;

animal animal_nulo();
animal inicializar_animal();
cola* startQueue();
void changeSpace(cola* colas);
short isEmpty(cola* colas);
animal getFront(cola* colas);
void enqueue(cola* colas, animal element);
void reorganize(cola* colas, Animales animal);
animal dequeue(cola* colas, int ind);
int sizequeue(cola* colas);

#endif // _colas
