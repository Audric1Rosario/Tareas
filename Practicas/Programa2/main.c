#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
   Programa que captura una matriz MxN
   y devuelve una matriz NxM
*/

int main()
{
   int n, m, i, j, pos_x, pos_y;
   printf("Programa para invertir matrices MxN a NxM.\n");

   do
   {
      printf("Ingrese la cantidad de filas: ");
      scanf("%d", &m);

      if (m < 1)
         printf("Debe haber al menos 1 fila.\n");
   } while (m < 1);

   do
   {
      printf("Ingrese la cantidad de columnas: ");
      scanf("%d", &n);

      if (n < 1)
         printf("Debe haber al menos 1 columna.\n");
   } while (n < 1);

   // Hora de ingresar matriz
   system("cls || clear");
   printf("Ingrese su matriz %dx%d.\n", m, n);
   pos_y = 2;

   int original[m][n];
   // Capturar
   for (i = 0; i < m; i++)
   {
      pos_x = 1;
      for (j = 0; j < n; j++)
      {
         gotoxy(pos_x, pos_y);
         scanf("%d", &original[i][j]);
         pos_x += 10;
      }
      pos_y++;
   }

   // Irse a posicion inicial
   pos_y += 2; gotoxy(1, pos_y);
   printf("Su matriz invertida es a %dx%d: \n", n, m); pos_y++;

   // Imprimir
   for (j = 0; j < n; j++)
   {
      pos_x = 1;
      for (i = m - 1; i >= 0; i--)
      {
         gotoxy(pos_x, pos_y);
         printf("%d", original[i][j]);
         pos_x += 10;
      }
      pos_y++;
   }

   system("pause");
   // Imprimir
   return 0;
}
