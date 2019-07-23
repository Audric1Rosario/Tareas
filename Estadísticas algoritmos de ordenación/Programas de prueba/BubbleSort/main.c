#include <stdio.h>
#include <stdlib.h>
#include "randomgenerator.h"
#include <stdint.h>
#include <sys/time.h>

const int cant_pruebas = 4;
const int pruebas[4] = {1000, 100000, 200000, 500000};

uint64_t bubblesort(int*, int*, uint64_t*);
void swap(int*, int*);

int main()
{
   // BubbleSort
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
   printf("Bubble Sort.\n\n");
   for (i = 0; i < cant_pruebas; i++)
   {
      // Inicializar contadores de memoria
      valores = pruebas[i]*sizeof(int);
      algoritmo = 0;

      // Medir tiempo exacto
      gettimeofday(&ti, NULL);   // Instante inicial
      pasos = bubblesort(elementos[i], &pruebas[i], &algoritmo);   // Ejecutar algoritmo
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

uint64_t bubblesort (int *data, int *count, uint64_t *memoria_usada)
{
   int i, j;
   uint64_t pasos = 0;
   *memoria_usada += sizeof(i) + sizeof(j);

   for (i = 0; i < *count; i++)
   {
      for (j = 0; j < *count - i - 1; j++)
      {
         pasos++;
         if (*(data + j) > *(data + j + 1))
            swap(data + j, data + j + 1);
      }
   }
   return pasos;
}

void swap (int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
   return;
}
