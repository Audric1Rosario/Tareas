#include "PilaEstatica.h"

Pila* IniciarPila()
{
   const int TAM = 100;
   Pila *nuevaPila;
   nuevaPila = (Pila *)malloc(sizeof(Pila));
   nuevaPila->pos = 0;
   nuevaPila->tam = TAM;
   nuevaPila->Pila = (float*) malloc(TAM * sizeof(float));

   return nuevaPila;
}

void VerificarEspacio(Pila *pila)
{
   if (pila->pos + 1 < pila->tam)
      return;

   pila->Pila = (float*)realloc(pila->Pila, pila->tam * 2);
   pila->tam = pila->tam * 2;

   return;
}

void Push(Pila *pila, float elemento)
{
   VerificarEspacio(pila);
   *(pila->Pila + pila->pos) = elemento;
   //pila->Pilas[pila->pos
   pila->pos++;

}

float Pop(Pila *pila)
{
   if (isEmpty(pila))
      return -1;

   float valor = *(pila->Pila + pila->pos - 1);
   pila->pos--;
   return valor;
}

int Size(Pila *pila)
{
   return pila->pos;
}

short isEmpty(Pila *pila)
{
   return pila->pos == 0;
}

float Peek(Pila *pila)
{
   float valor = Pop(pila);
   Push(pila, valor);

   return valor;
}
