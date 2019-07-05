#include "colas.h"

const int tam_queue = 100;

cola* startQueue()
{
   cola* colas = (cola*) malloc(sizeof(cola));
   colas->elements = (float*) calloc(tam_queue, sizeof(float));
   colas->first = 0;
   colas->last = -1;
   colas->array_size = tam_queue;
   colas->cantidad = 0;

   return colas;
}

void changeSpace(cola* colas)
{
   if (sizequeue(colas) < colas->array_size)
      return;

   float* nuevoEspacio = (float*)malloc(colas->array_size * 2);
   int loop = colas->array_size;

   while (loop != colas->last)
   {
      *(nuevoEspacio++) = *(colas->elements + loop++);

      if (loop == colas->array_size)
         loop = 0;
   }
   colas->elements = nuevoEspacio - colas->cantidad;
   colas->first = 0;
   colas->last = colas->array_size - 1;
   colas->array_size *= 2;

   return;
}

short isEmpty(cola* colas)
{
   return sizequeue(colas) == 0;
}

float getFront(cola* colas)
{
   if (isEmpty(colas))
      return 0;

   return *(colas->elements + colas->first);
}

void enqueue(cola* colas, float element)
{
   changeSpace(colas);

   colas->last++;
   if (colas->last >= colas->array_size)
      colas->last = 0;

   *(colas->elements + colas->last) = element;
   colas->cantidad++;

   return;
}

float dequeue(cola* colas)
{
   if (isEmpty(colas))
      return 0;

   float answer = *(colas->elements + colas->first);

   colas->first++;
   if (colas->first >= colas->array_size)
      colas->first = 0;

   colas->cantidad--;
   return answer;

}

int sizequeue(cola* colas)
{
   return colas->cantidad;
}
