#include <stdio.h>
#include <stdlib.h>
#include "monticulo.h"

int main()
{
   Monticulo* data;
   data = iniciar_monticulo(0);

   Insertar(data, 5);
   Insertar(data, 10);
   Insertar(data, 20);
   Insertar(data, 35);
   Insertar(data, 2);
   Insertar(data, 8);
   Insertar(data, 15);
   Insertar(data, 100);
   Insertar(data, 9);
   Insertar(data, 1);

   printf("Top: %.2f\n\n", GetTop(data));

   int loop;
   for (loop = 0; loop < data->pos_actual; loop++)
      printf("%.2f ", *(data->elementos + loop));

   printf("\n");

   while (!isEmpty(data))
      printf("%.2f\n", Poll(data));


   return 0;
}
