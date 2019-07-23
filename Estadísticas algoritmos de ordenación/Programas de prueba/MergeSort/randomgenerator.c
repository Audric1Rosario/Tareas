#include <stdlib.h>
#include <time.h>
#include "randomgenerator.h"

int randomize(int a, int b)
{
   return rand()%(b - a + 1) + a;
}

void generate_random(int arr[], int count, int a, int b)
{
   int i;
   srand(time(NULL));

   for (i = 0; i < count; i++)
      arr[i] = randomize(a, b);

   return;
}
