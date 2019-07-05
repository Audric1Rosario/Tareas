#include <stdio.h>
#include <stdlib.h>

void swap(int*, int*);
void selectsort(int*, int*);

int main()
{
    printf("Hello world!\n");
    return 0;
}

void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
   return;
}

void selectsort(int *data, int *count)
{
   int i, j, min, ind;

   for (i = 0; i < *count; i++)
   {
      min = *(data + i);
      ind = i;
      for (j = i + 1; j < *count; j++)
      {
         if (min > *(data + j))
         {
            min = *(data + j);
            ind = j;
         }
      }

      swap(data + i, data + ind);
   }

   return;
}
