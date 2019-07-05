#include <stdio.h>
#include <stdlib.h>

#ifndef _punteroMain
#define _punteroMain
void punteroMain(int filaReina, int columnaReina)
{
   const int SIDE = 8;
   int i, j;

   char **tablero = (char *) calloc(SIDE, sizeof(char*));

   for (i = 0; i < SIDE; i++)
   {
      *(tablero + i) = (char *) calloc(SIDE, sizeof(char));

      for (j = 0; j < SIDE; j++)
      {
         if (filaReina == i || columnaReina == j)
            *(*(tablero + i) + j) = '*';
         else if (filaReina + columnaReina == i + j || filaReina - columnaReina == i - j)
            *(*(tablero + i) + j) = '*';
         else
            *(*(tablero + i) + j) = ' ';
      }
   }

   *(*(tablero + filaReina) + columnaReina) = 'R';
   system("cls || clear");
   for (i = 0; i < SIDE; i++)
   {
      for (j = 0; j < SIDE; j++)
         printf("%c", *(*(tablero + i) + j));

      printf("\n");
   }

   return;
}
#endif // _punteroMain
