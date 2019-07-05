#include <stdlib.h>
#ifndef _monticulo
#define _monticulo

typedef struct
{
   int tam;
   int pos_actual;
   int altura;
   short es_min;
   float *elementos;
} Monticulo;

Monticulo* iniciar_monticulo(short esMin);
void VerificarEspacio(Monticulo *heap);
void Insertar(Monticulo* heap, float elemento);

float GetTop(Monticulo* heap);
float Poll(Monticulo* heap);

void HeapifyUp(Monticulo* heap, int pos);
void HeapifyDown(Monticulo* heap, int pos);

int IndicePadre(int indice);
int IndiceHijoDerecho(Monticulo *heap, int indice);
int IndiceHijoIzquierdo(Monticulo *heap, int indice);

short isEmpty(Monticulo* heap);
int size(Monticulo* heap);

void swap(float *a, float *b);
#endif // _monticulo
