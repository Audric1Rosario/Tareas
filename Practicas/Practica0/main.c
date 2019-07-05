#include <stdio.h>
#include <stdlib.h>

/*
   Programa que utilizando punteros, permita desde una funcion
   capturar el tamaño de un arreglo, y desde otra capture dichos
   valores en el arreglo. Los valores deben ser positivos. Al final,
   se deberán immpimir los valores.

   Puedes modificar el programa anterior para que ordene los elementos
   del arreglo, empleando sintaxis de punteros, con el algoritmo de
   ordenación por inserción
*/

void sizer(int*);
void insert(int*, int);
void plot(int*, int);

void sort_insert(int*, int);
void swap(int*, int*);

int main()
{
   int tam;
   int* elements;

   sizer(&tam);
   elements = (int *) calloc(tam, sizeof(int));

   insert(elements, tam);
   plot(elements, tam);

   return 0;
}

void sizer(int *data)
{
   system("cls || clear");
   do
   {
      printf("Ingrese el tama%co de los elementos que quiere ingresar:\n", 164);
      scanf("%d", data);

      if (*data < 1)
         printf("Los valores deben de ser mayores que 0.\n");
   } while (*data < 1);


   return;
}

void insert(int *elements, int count)
{
   int i;

   system("cls || clear");
   printf("\nIngrese un valor: \n");
   for (i = 0; i < count; i++)
   {
      printf("Valor %d: ", i + 1);
      scanf("%d", elements + i);
   }

   sort_insert(elements, count);
   return;
}

void plot (int *data, int count)
{
   int i;

   system("cls || clear");
   printf("Los elementos de su lista son:\n");
   for (i = 0; i < count; i++)
      printf("Valor %d: %d\n", i + 1, data[i]);

   return;
}

void sort_insert(int *data, int count)
{
   int i, j;

   for (i = 1; i < count; i++)
   {
      for (j = i - 1; j >= 0; j--)
      {
         if (*(data + j) > *(data + i))
            swap(data + j, data + i);
         else
            break;
      }
   }
   return;
}

void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
   return;
}
