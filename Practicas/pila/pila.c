#include <stdlib.h>
#include <string.h>
#include "pila.h"

//#ifndef _pila




int agregar (apila *list, int number)
{
   if (list->tam < MAX)
   {
      list->data[list->tam++] = number;
   }
   else
      return 0;

   return 1;
}

int sacar (apila *list, int *number)
{
   if (list->tam > 0)
   {
      *number = list->data[list->tam < MAX ? list->tam : list->tam - 1];
      list->tam--;
   }
   else
      return 0;

   return 1;
}


/*
void Imprimir_una_persona()
{
   Persona miNuevaPersona;
   miNuevaPersona.id = 5;
   strcpy(miNuevaPersona.nombre, "Audric");
   strcpy(miNuevaPersona.apellido, "Rosario");
   miNuevaPersona.edad = 18;
   miNuevaPersona.balance = 150;

   printf("%d\t%s\t%s\t%d\t%.2f\n",
          miNuevaPersona.id,
          miNuevaPersona.nombre,
          miNuevaPersona.apellido,
          miNuevaPersona.edad,
          miNuevaPersona.balance);
}*/
//#endif // _pila

