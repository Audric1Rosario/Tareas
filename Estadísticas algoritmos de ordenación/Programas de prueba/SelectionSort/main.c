#include <stdio.h>
#include <stdlib.h>
#include "randomgenerator.h"
#include <stdint.h>
#include <sys/time.h>

const int cant_pruebas = 4;
const int pruebas[4] = {1000, 100000, 200000, 500000};

uint64_t selectsort(int*, int, uint64_t*);
void swap(int*, int*);

//#define WIDTH 7
//#define DIV 1048576

int main()
{
   // SelectSort
   uint64_t pasos;               // Medir pasos
   uint64_t algoritmo, valores;  // Medir memoria

   // Elementos
   int i;
   int **elementos = (int**) malloc(cant_pruebas*sizeof(int*));

   // Reservar memoria para todo
   for (i = 0; i < cant_pruebas; i++)
      elementos[i] = (int*) malloc(pruebas[i]*sizeof(int));

   // Generar aleatorios
   for (i = 0; i < cant_pruebas; i++)
      generate_random(elementos[i], pruebas[i], 1, 10000);

   struct timeval ti, tf;
   double tiempo;

   // Probar valores
   printf("Selection Sort.\n\n");
   for (i = 0; i < cant_pruebas; i++)
   {
      // Inicializar contadores de memoria
      valores = pruebas[i]*sizeof(int);
      algoritmo = 0;

      // Medir tiempo exacto
      gettimeofday(&ti, NULL);   // Instante inicial
      pasos = selectsort(elementos[i], pruebas[i], &algoritmo);   // Ejecutar algoritmo
      gettimeofday(&tf, NULL);   // Instante final

      tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;

      printf("Arreglo de %d elementos ordenado.", pruebas[i]);
      printf("\n\nCantidad de pasos: %llu.\n", pasos);
      printf("Tard%c: %.3fms en ordenarse.\n", 162, tiempo);
      printf("Memoria usada por los elementos a ordenar: %llu bytes.\n", valores);
      printf("Memoria usada por el algoritmo: %llu bytes.\n\n\n", algoritmo);
   }

   return 0;
}

uint64_t selectsort(int *data, int count, uint64_t *memoria_usada)
{
   int i, j, min, ind;
   uint64_t pasos = 0;
   *memoria_usada += sizeof(i) + sizeof(j) + sizeof(min) + sizeof(ind);

   for (i = 0; i < count; i++)
   {
      min = *(data + i);
      ind = i;
      for (j = i + 1; j < count; j++)
      {
         if (min > *(data + j))
         {
            min = *(data + j);
            ind = j;
         }
         pasos++;
      }

      swap(data + i, data + ind);
   }

   return pasos;
}

void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
   return;
}
