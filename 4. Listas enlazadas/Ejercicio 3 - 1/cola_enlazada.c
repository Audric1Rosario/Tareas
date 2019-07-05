#include <stdlib.h>
#include "cola_enlazada.h"

const int ini_tam = 100;

Nodo* inicializar_nodo()
{
   Nodo *data = (Nodo*) malloc(sizeof(Nodo));
   data->elemento = 0;
   data->enlace = NULL;

   return data;
}

Cola* inicializar_cola()
{
   Cola *nuevaCola = (Cola*) malloc(sizeof(Cola));
   nuevaCola->inicio = (Nodo*)inicializar_nodo();
   nuevaCola->final = (Nodo*)inicializar_nodo();

   return nuevaCola;
}

void encolar(Cola *miCola, int num)
{
   if (miCola->inicio->enlace == NULL)
   {
      miCola->inicio->enlace = miCola->final;
      miCola->inicio->elemento = num;
   }
   else
   {
      miCola->final->elemento = num;
      miCola->final->enlace = inicializar_nodo();
      miCola->final = miCola->final->enlace;
   }
}

int decolar(Cola *miCola)
{
   int respuesta = front_element(miCola);
   Nodo* siguiente = miCola->inicio->enlace;
   free(miCola->inicio);
   miCola->inicio = siguiente;

   return respuesta;
}

int front_element (Cola *miCola)
{
   return miCola->inicio->elemento;
}

