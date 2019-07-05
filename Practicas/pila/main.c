#include <stdio.h>
#include <stdlib.h>
#include "pila_dinamica.h"
#include "pila.h"

int main()
{
   int num, loop;
   piladin historio;
   historio.data = NULL;

   do
   {
      printf("\nIngrese un valor diferente de 0: ");
      scanf("%d", &num);

      if (num != 0)
         agregar_din(&historio, &num);
   } while (num != 0);

   printf("El tama%co de la pila es de: %d", 164, historio.tam);
   system("pause");
   system("cls || clear");
   loop = 0;
   while (historio.data)
   {
      if (sacar_din(&historio, &num))
         printf("Val %d: %d\n", (loop++) + 1, num);
   }

   system("pause");

   return 0;
}
