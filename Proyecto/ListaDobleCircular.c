#include <stdlib.h>
#include "ListaDobleCircular.h"

/// Funciones Desarrollo

Lista* InicializarLista()
{
   Lista* nuevaLista = (Lista*) malloc(sizeof(Lista));
   nuevaLista->Cantidad = 0;
   nuevaLista->Cabeza = (Nodo*) malloc(sizeof(Nodo));
   nuevaLista->Cabeza->data.id = -1;
   nuevaLista->Cabeza->siguiente = nuevaLista->Cabeza;
   nuevaLista->Cabeza->anterior = nuevaLista->Cabeza;
   return nuevaLista;
}

void AgregarPelicula(Pelicula elemento, Nodo *despuesDe)
{
   Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
   nuevo->data = elemento;
   nuevo->siguiente = despuesDe->siguiente;
   nuevo->anterior = despuesDe;
   despuesDe->siguiente->anterior = nuevo;
   despuesDe->siguiente = nuevo;

   return;
}

void EliminarPelicula(Lista* listado, Nodo* aEliminar)
{
   if (aEliminar->data.id == -1)
      return;
   aEliminar->anterior->siguiente = aEliminar->siguiente;
   aEliminar->siguiente->anterior = aEliminar->anterior;
   free(aEliminar);
   listado->Cantidad--;
   return;
}

Nodo* BuscarPorId(Lista *listadoPeliculas, int id)
{
   Nodo *nodoActual = (Nodo*)malloc(sizeof(Nodo));
   nodoActual = listadoPeliculas->Cabeza->siguiente;

   while (nodoActual->data.id != -1)
   {
      if (nodoActual->data.id == id)
         return nodoActual;
      nodoActual = nodoActual->siguiente;
   }

   return NULL;
}

Nodo* BuscarPorAnyo(Lista *listadoPeliculas, int anyo)
{
   Nodo *nodoActual = (Nodo*)malloc(sizeof(Nodo));
   nodoActual = listadoPeliculas->Cabeza->siguiente;

   while (nodoActual->data.id != -1)
   {
      if (nodoActual->data.Anyo > anyo)
         return nodoActual->anterior;
      nodoActual = nodoActual->siguiente;
   }

   return nodoActual->anterior;
}

Nodo* CopiarNodo(Nodo *original)
{
   Nodo *copia = (Nodo*)malloc(sizeof(Nodo));

   copia->data = original->data;
   copia->anterior = original->anterior;
   copia->siguiente = original->siguiente;

   return copia;
}

void Intercambiar(Nodo *primero, Nodo *segundo)
{/*
   Nodo *temp = (Nodo*)malloc(sizeof(Nodo));
   *temp = *primero;
   *primero = *segundo;
   *segundo = *temp;
   free(temp);*/

   Nodo *auxPrimero = CopiarNodo(primero);

   primero->anterior->siguiente = segundo;
   primero->anterior = segundo->anterior;
   primero->siguiente->anterior = segundo;
   primero->siguiente = segundo->siguiente;
   segundo->siguiente = auxPrimero->siguiente;
   segundo->anterior->siguiente = primero;
   segundo->anterior = auxPrimero->anterior;
   primero->siguiente->anterior = primero;

   free(auxPrimero);
   return;
}

void OrdenarPeliculaSeleccion(Lista *listado)
{
   Nodo *actual = listado->Cabeza->siguiente;
   Nodo *menor;
   Nodo *pos;

   while (actual->data.id != -1)
   {
      menor = actual;
      pos = actual->siguiente;
      while (pos->data.id != -1)
      {
         if (pos->data.Anyo < menor->data.Anyo)
         {
            menor = pos;
         }
         pos = pos->siguiente;
      }
      Intercambiar(actual, menor);
      actual = actual->siguiente;
   }
   return;
}

void InsertarPelicula(Lista*, Pelicula, int);
