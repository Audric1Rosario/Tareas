#include "colas.h"

const int tam_queue = 100;
const int nam_tam = 80;

animal animal_nulo()
{
   animal data = { "return", -1 };
   return data;
}

animal inicializar_animal()
{
   animal data;
   data.nombre = (char*) calloc(nam_tam, sizeof(char));
   data.tipo = (Animales) malloc(sizeof(Animales));

   return data;
}

cola* startQueue()
{
   cola* colas = (cola*) malloc(sizeof(cola));
   colas->elements = (animal*) calloc(tam_queue, sizeof(animal));
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

   animal* nuevoEspacio = (animal*)malloc(colas->array_size * 2);
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

animal getFront(cola* colas)
{
   if (isEmpty(colas))
      return animal_nulo();

   return *(colas->elements + colas->first);
}

void enqueue(cola* colas, animal element)
{
   changeSpace(colas);

   colas->last++;
   if (colas->last >= colas->array_size)
      colas->last = 0;

   *(colas->elements + colas->last) = element;
   colas->cantidad++;

   return;
}

animal dequeue(cola* colas, int m)
{
   int loop;
   animal answer = animal_nulo();

   if (m == -1) // Hacerlo de la manera por defecto
   {
      if (isEmpty(colas))
         return animal_nulo();

      answer = *(colas->elements + colas->first);

      colas->first++;
      if (colas->first >= colas->array_size)
         colas->first = 0;

      colas->cantidad--;
      return answer;
   }
   else  // Buscar ese animal en específico
   {

      if (colas->first > colas-> last)
      {
         for (loop = colas->first; loop < colas->array_size; loop++)
         {
            if (colas->elements[loop].tipo == m)
            {
               answer = *(colas->elements + loop);
               reorganize(colas, loop);
               return answer;
            }
         }
      }

      if ((answer.tipo == animal_nulo().tipo) && colas->first > colas-> last)
         loop = 0;
      else
         loop = colas->first;

      for (; loop < colas->last; loop++)
      {
         if (colas->elements[loop].tipo == m)
         {
            answer = *(colas->elements + loop);
            reorganize(colas, loop);
            return answer;
         }
      }

   }

   return animal_nulo();  // Si no encuentra el animal especifico
}

void reorganize(cola* colas, int ind)
{
   int i;
   if (colas->last < colas->first)
   {
      for (i = colas->first; i < colas->array_size - 1; i++)
         *(colas->elements + i) = *(colas->elements + i + 1);

      for (i = 0; i < colas->last - 1; i++)
         *(colas->elements + i) = *(colas->elements + i + 1);

      colas->last--;
   }
   else
   {
      for (i = colas->first; i < colas->last - 1; i++)
         *(colas->elements + i) = *(colas->elements + i + 1);
   }

   return;
}

int sizequeue(cola* colas)
{
   return colas->cantidad;
}
