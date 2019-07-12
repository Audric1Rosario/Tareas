#include <stdlib.h>
#include <stdio.h>

#ifndef _ListaDobleCircular
#define _ListaDobleCircular

/// Estructuras especiales
typedef struct
{
   int id;
   char *Titulo;
   int Anyo;
   char *Clasificacion;
   float Calificacion;
   float Duracion;
   char **Generos;
   int CantidadGeneros;
   char *Sinopsis;
} Pelicula;

typedef struct sNodo
{
   Pelicula data;
   struct sNodo *anterior;
   struct sNodo *siguiente;
} Nodo;

typedef struct
{
   Nodo *Cabeza;
   int Cantidad;
} Lista;

/// Funciones
Lista* InicializarLista();

void AgregarPelicula(Pelicula, Nodo*);
void EliminarPelicula(Lista*, Nodo*);

Nodo* BuscarPorId(Lista*, int);
Nodo* BuscarPorAnyo(Lista*, int);

Nodo* CopiarNodo(Nodo*);
void Intercambiar(Nodo*, Nodo*);
void OrdenarPeliculaSeleccion(Lista*);
void InsertarPelicula(Lista*, Pelicula, int);

#endif // _ListaDobleCircular
