#include <stdio.h>
#include <stdlib.h>
#include "cola_enlazada.h"

int main()
{
   int n;
   Cola* data = inicializar_cola();
   printf("Prueba de la cola...\n\n");

   do
   {
      printf("Ingrese un n%cmero (menor que 0 para terminar): ", 163);
      scanf("%d", &n);

      if (n >= 0)
         encolar(data, n);
   } while (n >= 0);

   printf("\n\n");
   n = 0;
   while (data->inicio->enlace != NULL)
      printf("Valor #%02d: %d\n", ++n, decolar(data));

   return 0;
}
