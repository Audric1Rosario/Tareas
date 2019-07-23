#include <stdio.h>
#include <stdlib.h>
#include "randomgenerator.h"
#include <stdint.h>
#include <sys/time.h>

const int cant_pruebas = 4;
const int pruebas[4] = {1000, 100000, 200000, 500000};

// Ordenación
uint64_t mergesort(int[], int, int, uint64_t*);
uint64_t merge(int[], int, int, int, uint64_t*);

int main()
{
   // Mergesort
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
   printf("Merge Sort.\n\n");
   for (i = 0; i < cant_pruebas; i++)
   {
      // Inicializar contadores de memoria
      valores = pruebas[i]*sizeof(int);
      algoritmo = 0;

      // Medir tiempo exacto
      gettimeofday(&ti, NULL);   // Instante inicial
      pasos = mergesort(elementos[i], 0, pruebas[i] - 1, &algoritmo);   // Ejecutar algoritmo
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

/// Ordenaci�zn por mezcla
uint64_t mergesort(int arr[], int l, int r, uint64_t *memoria_usada)
{
   uint64_t pasos = 0;

   if (l < r)
   {
      int m = l + (r - l) / 2;
      pasos += mergesort(arr, l, m, memoria_usada);
      pasos += mergesort(arr, m + 1, r, memoria_usada);
      *memoria_usada += sizeof(m);
      pasos += merge(arr, l, m, r, memoria_usada);
   }

   return pasos;
}

uint64_t merge(int arr[], int l, int m, int r, uint64_t *memoria_usada)
{
   int i, j, k;
   int a, b;
   uint64_t pasos = 0;

   a = m - l + 1;
   b = r - m;

   // Crear arreglos temporales
   int array_a[a], array_b[b];

   *memoria_usada += (a + b)*sizeof(int); // Calcular el tamaño de los arreglos temporales
   *memoria_usada += sizeof(i) + sizeof(j) + sizeof(k);

   // Copiar los datos del arreglo desde cada limite.
   for (i = 0; i < a; i++)
      array_a[i] = arr[l + i];
   for (j = 0; j < b; j++)
      array_b[j] = arr[m + 1 + j];

   i = 0;
   j = 0;
   k = l;
   // Mezclar los elementos
   while (i < a && j < b)
   {
      if (array_a[i] <= array_b[j])
         arr[k] = array_a[i++];
      else
         arr[k] = array_b[j++];
      k++;
   }

   // Terminar de copiar los elementos que faltan.
   while (i < a)
      arr[k++] = array_a[i++];

   while (j < b)
      arr[k++] = array_b[j++];

   pasos += 2*(i + j);
   return pasos;
}
