#include "PilaEstatica.h"
const int TAM = 300;

Pila* IniciarPila()
{
   int i;
   Pila *nuevaPila;
   nuevaPila = (Pila *)malloc(sizeof(Pila));

   for (i = 0; i < 3; i++)
      nuevaPila->pos[i] = 0;

   nuevaPila->tam = TAM;
   nuevaPila->cantidad = 0;
   nuevaPila->Pila = (int*) malloc(TAM * sizeof(int));

   for (i = 0; i < 3; i++)
      nuevaPila->lim[i] = (TAM / 3) * i;

   return nuevaPila;
}

void VerificarEspacio(Pila *pila)
{
   if (pila->cantidad < pila->tam)
      return;

   pila->Pila = (int*)realloc(pila->Pila, pila->tam * 2);
   pila->tam = pila->tam * 2;

   return;
}

void Push(Pila *pila, int elemento, int tercio)
{
   VerificarEspacio(pila);
   *(pila->Pila + pila->pos[tercio] + pila->lim[tercio]) = elemento;
   //pila->Pilas[pila->pos
   pila->pos[tercio]++;
   pila->cantidad++;

}

int Pop(Pila *pila, int tercio)
{
   if (isEmpty(pila, tercio))
      return -1;

   int valor = *(pila->Pila + pila->pos[tercio] + pila->lim[tercio] - 1);
   pila->pos[tercio]--;
   pila->cantidad--;
   return valor;
}

int Size(Pila *pila)
{
   return pila->cantidad;
}

short isEmpty(Pila *pila, int tercio)
{
   return pila->pos[tercio] == 0;
}

int Peek(Pila *pila, int tercio)
{
   int valor = Pop(pila, tercio);
   Push(pila, valor, tercio);

   return valor;
}
