#include <stdio.h>
#include <stdlib.h>
#include "versionMatriz.h"
#include "versionPuntero.h"


int main()
{
    int fil, col;
   printf("Programa para imprimir hacia donde se puede dirigir la reina.\n\n");

   do
   {
      printf("\nFila: ");
      scanf("%d", &fil);
      if (fil < 1 || fil > 8)
         printf("Por favor, ingrese un valor entre 1 y 8\n");
   } while (fil < 1 || fil > 8);
   do
   {
      printf("\nColumna: ");
      scanf("%d", &col);
      if (col < 1 || col > 8)
         printf("Por favor, ingrese un valor entre 1 y 8\n");
   } while (col < 1 || col > 8);

   punteroMain(fil - 1, col - 1);
   system("pause");
   return 0;
}
