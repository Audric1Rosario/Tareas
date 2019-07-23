#include <stdio.h>
#include <stdlib.h>
#include "randomgenerator.h"
#include <stdint.h>
#include <sys/time.h>

const int cant_pruebas = 4;
const int pruebas[4] = {1000, 100000, 200000, 500000};

uint64_t QuickSort(int[], int, uint64_t*);
uint64_t QSrecursive(int[], int, int, uint64_t*);
int particionar(int[], int, int, uint64_t*);

// Intercambio
void swap_arr(int[], int, int);
void swap(int*, int*);

int main()
{
   // Quicksort
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
   printf("Quick Sort.\n\n");
   for (i = 0; i < cant_pruebas; i++)
   {
      // Inicializar contadores de memoria
      valores = pruebas[i]*sizeof(int);
      algoritmo = 0;

      // Medir tiempo exacto
      gettimeofday(&ti, NULL);   // Instante inicial
      pasos = QuickSort(elementos[i], pruebas[i], &algoritmo);   // Ejecutar algoritmo
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

uint64_t QuickSort(int lista[], int cant, uint64_t *memoria_usada)
{
   return QSrecursive(lista, 0, cant - 1, memoria_usada);
}

uint64_t QSrecursive(int lista[], int a, int b, uint64_t *memoria_usada)
{
   int indpiv;
   uint64_t pasos = 0;
   *memoria_usada += sizeof(indpiv);
   if (a >= b)
      return 0;

   indpiv = particionar(lista, a, b, &pasos);
   pasos += QSrecursive(lista, a, indpiv - 1, memoria_usada);
   pasos += QSrecursive(lista, indpiv + 1, b, memoria_usada);
   return pasos;
}

int particionar(int lista[], int a, int b, uint64_t *pasos)
{
   int pivote = lista[a], i = a + 1, j = i;

   for (; i <= b; i++)
   {
      *pasos += 1;
      if (lista[i] < pivote)
      {
         swap_arr(lista, i, j);
         j++;
      }
   }
   swap(&lista[a], &lista[j - 1]);

   return j - 1;
}

void swap_arr(int lista[], int a, int b)
{
   int temp = lista[b];
   lista[b] = lista[a];
   lista[a] = temp;
   return;
}

void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
   return;
}
