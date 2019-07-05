#include "pila_dinamica.h"

int agregar_din (piladin *list, int *number)
{
   if (list->tam == 0)
   {
      if ( (list->data = (int *) malloc(sizeof(int))) == NULL)
         return 0;
      else
         list->tam = 1;
   }
   else
   {
      if ( (list->data = (int *) realloc(list->data, list->tam + 1)) == NULL)
         return 0;
      else
         list->tam++;
   }

   list->data[list->tam - 1] = *number;
   return 1;
}

int sacar_din (piladin *list, int *number)
{
   if (list->tam > 0)
   {
      *number = list->data[list->tam - 1];

      list->data = (int *) realloc(list->data, list->tam - 1);
      list->tam--;
   }
   else
      return 0;

   return 1;
}
