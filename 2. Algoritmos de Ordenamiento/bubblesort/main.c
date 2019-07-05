#include <stdio.h>
#include <stdlib.h>

void bubblesort (int *, int *);
void swap(int*, int*);
int main()
{
    printf("Hello world!\n");
    return 0;
}

void bubblesort (int *data, int *count)
{
   int i, j;

   for (i = 0; i < *count; i++)
   {
      for (j = 0; j < *count - i - 1; j++)
      {
         if (*(data + j) > *(data + j + 1))
            swap(data + j, data + j + 1);
      }
   }
   return;
}

void swap (int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;

   return;
}
