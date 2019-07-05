#include <stdio.h>
#include <stdlib.h>

#ifndef _mainMatriz
#define _mainMatriz
void mainMatriz(int filaReina, int columnaReina)
{
   const int SIDE = 8;
   char tablero[SIDE][SIDE];
   int i, j;

   for (i = 0; i < SIDE; i++)
   {
      for (j = 0; j < SIDE; j++)
      {
         if (filaReina == i || columnaReina == j)
            tablero[i][j] = '*';
         else if (filaReina + columnaReina == i + j || filaReina - columnaReina == i - j)
            tablero[i][j] = '*';
         else
            tablero[i][j] = ' ';
      }
   }

   tablero[filaReina][columnaReina] = 'R';

   system("cls || clear");
   for (i = 0; i < SIDE; i++)
   {
      for (j = 0; j < SIDE; j++)
         printf("%c", tablero[i][j]);

      printf("\n");
   }



   return;
}
#endif // _mainMatriz
