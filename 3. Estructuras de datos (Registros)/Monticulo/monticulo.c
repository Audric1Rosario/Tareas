#include <stdlib.h>
#include <math.h>
#include "monticulo.h"

const int ALTURA = 10;
Monticulo* iniciar_monticulo(short esMin)
{
   Monticulo *nuevoHeap = (Monticulo*)malloc(sizeof(Monticulo));
   nuevoHeap->tam = pow(2, ALTURA) - 1;
   nuevoHeap->pos_actual = 0;
   nuevoHeap->altura = ALTURA;
   nuevoHeap->es_min = esMin;
   nuevoHeap->elementos = (float*)calloc(nuevoHeap->tam, sizeof(float));

   return nuevoHeap;
}

void VerificarEspacio(Monticulo *heap)
{
   if (heap->pos_actual < heap->tam)
      return;

   heap->altura++;
   heap->tam = pow(2, heap->altura);
   heap->elementos = (float*)realloc(heap->elementos, heap->tam);

   return;
}

void Insertar(Monticulo* heap, float elemento)
{
   VerificarEspacio(heap);

   *(heap->elementos + heap->pos_actual++) = elemento;
   HeapifyUp(heap, heap->pos_actual - 1);

   return;
}

float GetTop(Monticulo* heap)
{
   return *(heap->elementos);
}

float Poll(Monticulo* heap)
{
   if (heap->pos_actual == 0)
      return *heap->elementos;

   float raiz = GetTop(heap);

   swap(heap->elementos, heap->elementos + (heap->pos_actual - 1));
   heap->pos_actual--;
   HeapifyDown(heap, 0);

   return raiz;
}

void HeapifyUp(Monticulo* heap, int pos)
{
   // Axiomas
   if (pos == 0)
      return;
   int ind_padre = IndicePadre(pos);
   if (heap->es_min)
   {     // Cuando el es un min heap, y el padre es menor se sale
      if (*(heap->elementos + ind_padre) < *(heap->elementos + pos))
         return;
   }
   else  // Cuando el es un min heap, y el padre es mayor se sale
   {
      if (*(heap->elementos + ind_padre) > *(heap->elementos + pos))
         return;
   }

   // Cuerpo
   swap(heap->elementos + ind_padre, heap->elementos + pos);

   /// Cambio
   HeapifyUp(heap, ind_padre);
}

void HeapifyDown(Monticulo* heap, int pos)
{
   int top_hijo = IndiceHijoIzquierdo(heap, pos);
   int der_hijo = IndiceHijoDerecho(heap, pos);

   // Axioma de los indices de los hijos
   if (top_hijo < 0)
      return;

   if (der_hijo >= 0)
   {
      if (heap->es_min) // Saber si es un min heap encontrar el hijo menor
         top_hijo = *(heap->elementos + top_hijo) > *(heap->elementos + der_hijo) ? der_hijo : top_hijo;
      else              // si es un max heap encontrar el hijo mayor
         top_hijo = *(heap->elementos + top_hijo) < *(heap->elementos + der_hijo) ? der_hijo : top_hijo;
   }

   // Axioma de final de cambio
   if (heap->es_min)
   {  // Si el padre es menor que el hijo, entonces retorna
      if (*(heap->elementos + pos) < *(heap->elementos + top_hijo))
         return;
   }
   else
   {  // Si el padre es mayor entonces, retorna.
      if (*(heap->elementos + pos) > *(heap->elementos + top_hijo))
         return;
   }

   // Cuerpo
   swap(heap->elementos + pos, heap->elementos + top_hijo);

   // Cambio
   HeapifyDown(heap, top_hijo);

}

int IndicePadre(int indice)
{
   int result = (indice - 1) / 2;
   return result < 0 ? 0 : result;
}

int IndiceHijoDerecho(Monticulo *heap, int indice)
{
   int result = (indice * 2) + 2;
   return result < heap->pos_actual - 1 ? result : -1;
}

int IndiceHijoIzquierdo(Monticulo *heap, int indice)
{
   int result = (indice * 2) + 1;
   return result < heap->pos_actual ? result : -1;
}

short isEmpty(Monticulo* heap)
{
   return heap->pos_actual == 0;
}

int size(Monticulo* heap)
{
   return heap->pos_actual;
}

void swap(float *a, float *b)
{
   float temp = *a;
   *a = *b;
   *b = temp;
   return;
}
