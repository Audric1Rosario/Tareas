#include <stdio.h>
#include <stdlib.h>

int main()
{
   int *num;
   long loop = 0;

   while ((num = (int*)malloc(sizeof(int))) != NULL)
      loop++;

   /*while(1)
   {
      num = malloc(1000);
      if (num == NULL)
         break;
      loop += 1000;
   }*/

   //free(num);
   printf("\nMemoria asignada: %ldMB\n", (loop*sizeof(int)) / 1048576);
   return 0;
}
