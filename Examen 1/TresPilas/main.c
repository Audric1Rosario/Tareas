#include <stdio.h>
#include <stdlib.h>
#include "PilaEstatica.h"

/// Tres pilas en 1
int main()
{
   Pila* threeway = IniciarPila();
   int i, j;

   Push(threeway, 1, 0);
   Push(threeway, 2, 1);
   Push(threeway, 3, 2);

   Push(threeway, 4, 0);
   Push(threeway, 5, 1);
   Push(threeway, 6, 2);

   Push(threeway, 7, 0);
   Push(threeway, 8, 1);
   Push(threeway, 9, 2);


   for (i = 0; i < 3; i++)
   {
      for(j = 0; j < 3; j++)
         printf("#%d: %d\n", i + 1, Pop(threeway, i));

      printf("\n\n");
   }

   system("pause");
   return 0;
}
