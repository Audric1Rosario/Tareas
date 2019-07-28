#include <stdio.h>
#include <stdlib.h>
#include "conio.h"

const int DIM = 9;

void capturarMatriz(short matrizSudoku[DIM][DIM]);
void mostrarMatriz(short matrizSudoku[DIM][DIM]);
short resolverSudoku(short matrizSudoku[DIM][DIM]);
short resolverSudokuBT(short matrizSudoku[DIM][DIM], int x, int y);
short esValido(short matrizSudoku[DIM][DIM], int x, int y);

int main()
{
   short sudoku[9][9] = {{0, 6, 0, 0, 0, 0, 0, 0, 8},
                         {9, 0, 0, 0, 0, 0, 0, 0, 0},
                         {8, 0, 0, 0, 0, 0, 0, 0, 0},
                         {7, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 5, 0, 0, 0, 0},
                         {0, 0, 0, 0, 6, 0, 0, 0, 0},
                         {3, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 7, 0, 0, 0, 0, 0, 0},
                         {0, 0, 4, 0, 0, 0, 0, 0, 0}};
   /*
   short sudoku[9][9] = {{0, 6, 0, 3, 0, 0, 0, 0, 8},
                         {9, 0, 6, 3, 0, 0, 0, 0, 0},
                         {8, 0, 0, 0, 0, 0, 0, 0, 0},
                         {7, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 5, 0, 0, 0, 0},
                         {0, 0, 0, 0, 6, 0, 0, 0, 0},
                         {3, 0, 0, 0, 0, 0, 1, 0, 0},
                         {0, 0, 7, 0, 0, 0, 0, 0, 0},
                         {0, 0, 4, 0, 0, 0, 0, 0, 0}};*/
   capturarMatriz(sudoku);
   printf("\n");
   mostrarMatriz(sudoku);

   system("pause");
   printf("\n\n");

   if (!resolverSudoku(sudoku))
      printf("\nSudoku inv%clido.\n", 160);
   else
      mostrarMatriz(sudoku);

   return 0;
}

void capturarMatriz(short matrizSudoku[DIM][DIM])
{
   int i, j;
   char num;
   system("cls");
   for (i = 0; i < DIM; i++)
   {
      for (j = 0; j < DIM; j++)
      {
         printf("%d, %d: ", i + 1, j + 1);
         scanf("%hd", &matrizSudoku[i][j]);
      }
   }
}

void mostrarMatriz(short matrizSudoku[DIM][DIM])
{
   int i, j;
   for (i = 0; i < DIM; i++)
   {
      for (j = 0; j < DIM; j++)
         printf("%d\t", matrizSudoku[i][j]);
      printf("\n");
   }
}

short resolverSudoku(short matrizSudoku[DIM][DIM])
{
   return resolverSudokuBT(matrizSudoku, 0, 0);
}

short resolverSudokuBT(short matrizSudoku[DIM][DIM], int x, int y)
{
   int tanteoActual;
   if (y >= DIM)
      return 1;

   if (x >= DIM)
      return resolverSudokuBT(matrizSudoku, 0, y+1);

   if (matrizSudoku[y][x] != 0)
      return resolverSudokuBT(matrizSudoku, x + 1, y);

   for (tanteoActual = 1; tanteoActual <= DIM; tanteoActual++)
   {
      matrizSudoku[y][x] = tanteoActual;
      if (esValido(matrizSudoku, x, y))
      {
         if (resolverSudokuBT(matrizSudoku, x+1, y))
            return 1;
      }
   }
   matrizSudoku[y][x] = 0;
   return 0;
}

short esValido(short matrizSudoku[DIM][DIM], int x, int y)
{
   int i, j, encontrado;
   // Fila:

   for (i = 0, encontrado = 0; i < DIM; i++)
      encontrado += matrizSudoku[y][i] == matrizSudoku[y][x] ? 1 : 0;
   if (encontrado > 1)
      return 0;

   // Columna:
   for (i = 0, encontrado = 0; i < DIM; i++)
      encontrado += matrizSudoku[i][x] == matrizSudoku[y][x] ? 1 : 0;
   if (encontrado > 1)
      return 0;

   // Bloque:
   for (i = y - (y % 3), encontrado = 0; i < (y - (y % 3) + 3); i++)
   {
      for (j = x - (x % 3); j < (x - (x % 3) + 3); j++)
      {
         encontrado += matrizSudoku[i][j] == matrizSudoku[y][x] ? 1 : 0;
      }
   }

   if (encontrado > 1)
      return 0;

   return 1;
}

