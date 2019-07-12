#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "conio.h"
#include "ListaDobleCircular.h"

#define hori_line   205
#define vert_line   186
#define esq_inf_der 188
#define esq_inf_izq 200
#define esq_sup_der 187
#define esq_sup_izq 201
#define inter_l_izq 204
#define inter_l_der 185
#define inter_l_arr 203
#define inter_l_aba 202

const int max_len = 100;
const int max_paragraph = 500;
const int max_word = 20;
const int COL1 = 26, COL2 = 52;

const int max_line = 24;
const int max_width = 80;
const int max_height = 24;

typedef enum
{
   Salir,
   Agregar,
   Modificar,
   Eliminar,
   Insertar,
   Explorar,
   Buscar,
   Ordenar
} eSeleccionarMenu;

eSeleccionarMenu MostrarMenu();

void mostrar_marco();
void mostrar_marco_3_columnas();
void dibujar_linea(int, int, int, int, char);

void CapturarPelicula(Lista*, Nodo*, short);
void ExplorarPeliculas(Lista*, Nodo*);
void BorrarPelicula(Lista*);
void MostrarPeliculaEnColumna(Pelicula, int);
void MostrarSinopsis(int, int, int, char*);
void ModificarPeliculas(Lista*);
void BuscarPeliculaPorAnyo(Lista*);
void OrdernarPeliculasPorAnyo(Lista*);

int main()
{
   Lista *listadoPeliculas = InicializarLista();
   eSeleccionarMenu opcionActual;

   do
   {
      opcionActual = MostrarMenu();

      switch (opcionActual)
      {
         case Agregar:
            CapturarPelicula(listadoPeliculas, NULL, 0);
            break;
         case Modificar:
            ModificarPeliculas(listadoPeliculas);
            break;
         case Eliminar:
            BorrarPelicula(listadoPeliculas);
            break;
         case Insertar:
            CapturarPelicula(listadoPeliculas, NULL, 1);
            break;
         case Explorar:
            ExplorarPeliculas(listadoPeliculas, NULL);
            break;
         case Buscar:
            BuscarPeliculaPorAnyo(listadoPeliculas);
            break;
         case Ordenar:
            OrdenarPeliculaSeleccion(listadoPeliculas);
            break;
         case Salir:
            system("cls || clear");
         break;
      }

   } while (opcionActual != Salir);

   return 0;

}

eSeleccionarMenu MostrarMenu()
{
   char seleccion;
   _setcursortype(0);
   do
   {
      system("cls || clear");
      mostrar_marco();
      gotoxy(25, 3);
      printf("Gesti%cn de Pel%cculas.", 162, 161);
      gotoxy(5, 5);
      printf("1: Agregar una pel%ccula.", 161);
      gotoxy(5, 7);
      printf("2: Modificar pel%ccula dando un ID.", 161);
      gotoxy(5, 9);
      printf("3: Eliminar una pel%ccula dando un ID.", 161);
      gotoxy(5, 11);
      printf("4: Agregar una pel%ccula en orden de a%co.", 161, 164);
      gotoxy(5, 13);
      printf("5: Explorar pel%cculas registradas.", 161);
      gotoxy(5, 15);
      printf("6: Buscar una pel%ccula por a%co.", 161, 164);
      gotoxy(5, 17);
      printf("7: Ordenar las pel%cculas.", 161);
      gotoxy(5, 20);
      printf("0: Salir de la aplicaci%cn.", 162);

      gotoxy(5, 21);
      fflush(stdin);
      seleccion = getch() - 48;

   } while (seleccion < 0 || seleccion > 8);

   _setcursortype(1);
   return (eSeleccionarMenu) seleccion;
}

void mostrar_marco()
{
   system("cls || clear");
   // Lineas
   dibujar_linea(1, 62, 2, 1, hori_line);
   dibujar_linea(0, 3, 1, 1, vert_line);
   dibujar_linea(0, 3, 64, 1, vert_line);
   dibujar_linea(1, 62, 2, 4, hori_line);
   dibujar_linea(0, 15, 1, 5, vert_line);
   dibujar_linea(0, 15, 64, 5, vert_line);
   dibujar_linea(1, 62, 2, 20, hori_line);

   // Esquinas
   gotoxy(1,  1);    printf("%c", esq_sup_izq);
   gotoxy(64, 1);    printf("%c", esq_sup_der);
   gotoxy(1, 20);    printf("%c", esq_inf_izq);
   gotoxy(64,20);    printf("%c", esq_inf_der);

   // Intersecciones
   gotoxy(1, 4);     printf("%c", inter_l_izq);
   gotoxy(64,4);     printf("%c", inter_l_der);
}

void mostrar_marco_3_columnas()
{
   system("cls || clear");
   // Lineas horizontales
   dibujar_linea(1, 78, 2, 1, hori_line);
   dibujar_linea(1, 78, 2, 24, hori_line);

   // Lineas verticales
   dibujar_linea(0, 24, 1, 1, vert_line);
   dibujar_linea(0, 24, 26, 1, vert_line);
   dibujar_linea(0, 24, 52, 1, vert_line);
   dibujar_linea(0, 24, 80, 1, vert_line);

   // Esquinas
   gotoxy(1,  1);    printf("%c", esq_sup_izq);
   gotoxy(80, 1);    printf("%c", esq_sup_der);
   gotoxy(1, 24);    printf("%c", esq_inf_izq);
   gotoxy(80,24);    printf("%c", esq_inf_der);

   // Intersecciones
   gotoxy(COL1, 1);  printf("%c", inter_l_arr);
   gotoxy(COL2, 1);  printf("%c", inter_l_arr);
   gotoxy(26,24);    printf("%c", inter_l_aba);
   gotoxy(52,24);    printf("%c", inter_l_aba);

   gotoxy(1, 25);

}

void dibujar_linea(int ori, int cant, int x, int y, char ch)
{
   int i;
   for (i = 0; i < cant; i++)
   {
      if (ori != 0)  // Horizontal
         gotoxy(x + i, y);
      else  // Vertical
         gotoxy(x, y + i);
      printf("%c", ch);
   }
}

void CapturarPelicula(Lista *listado, Nodo *aModificar, short enOrden)
{
   short generosSeleccionados[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
   int seleccion, i, j = 0;
   Pelicula nuevaPelicula;
   system("cls");
   mostrar_marco();

   gotoxy(10, 3);
   if (aModificar == NULL)
      printf("Agregando nueva pel%ccula al final de la lista.", 161);
   else
      printf("Modificando peli%ccula existente.", 161);

   gotoxy(3, 7);
   if (aModificar)
   {
      printf("Id: %4.3d", aModificar->data.id);
      nuevaPelicula.id = aModificar->data.id;
   }
   else
   {
      printf("Id: ");
      scanf("%d", &nuevaPelicula.id);
   }

   gotoxy(5, 8);
   printf("\tT%ctulo: ", 161);
   nuevaPelicula.Titulo = (char*)malloc(max_len*sizeof(char));
   fflush(stdin);
   gets(nuevaPelicula.Titulo);

   gotoxy(5, 9);
   printf("A%co: ", 164);
   scanf("%d", &nuevaPelicula.Anyo);

   gotoxy(5, 10);
   printf("Seleccione una clasificaci%cn: ", 162);

   gotoxy(7, 11);   printf("1: G     (Prop%csito general)", 162);
   gotoxy(7, 12);   printf("2: PG    (Supervisi%cn parental)", 162);
   gotoxy(7, 13);   printf("3: PG-13 (No apta para menores de 13 a%cos)", 164);
   gotoxy(7, 14);   printf("4: R     (Requiere compa%c%ca de un adulto)", 164, 161);
   gotoxy(7, 15);   printf("5: NC-17 (S%clo adultos)", 162);
   gotoxy(5, 16);   printf("Seleccione: ");

   do
   {
      gotoxy(17, 16); printf(" \b");  seleccion = getche() - 48;
   } while (seleccion < 1 || seleccion > 5);

   nuevaPelicula.Clasificacion = (char*) malloc(10*sizeof(char));
   switch(seleccion)
   {
      case 1:
         strcpy(nuevaPelicula.Clasificacion, "G");
         break;
      case 2:
         strcpy(nuevaPelicula.Clasificacion, "PG");
         break;
      case 3:
         strcpy(nuevaPelicula.Clasificacion, "PG-13");
         break;
      case 4:
         strcpy(nuevaPelicula.Clasificacion, "R");
         break;
      case 5:
         strcpy(nuevaPelicula.Clasificacion, "PC-17");
         break;
   }

   gotoxy(5, 17);
   printf("Calificaci%cn: ", 162);
   scanf("%f", &nuevaPelicula.Calificacion);

   gotoxy(5, 18);
   printf("Duraci%cn (minutos): ", 162);
   scanf("%f", &nuevaPelicula.Duracion);

   /// Mostramos los generos:
   system("cls || clear");
   mostrar_marco();

   gotoxy(10, 3);
   printf("Agregando nueva pel%ccula al final de la lista.", 161);
   do
   {
      do
      {
         gotoxy(5, 7);
         printf("Seleccione los g%cneros de la pel%ccula", 130, 161);

         gotoxy(5, 9);   printf("1: Acci%cn.", 162);
         gotoxy(5,10);   printf("2: Aventura.");
         gotoxy(5,11);   printf("3: Comedia.");
         gotoxy(5,12);   printf("4: Drama.");
         gotoxy(5,13);   printf("5: Terror.");
         gotoxy(5,14);   printf("6: Musical.");
         gotoxy(5,15);   printf("7: Ciencia Ficci%cn.", 162);
         gotoxy(5,16);   printf("8: Suspenso.");
         gotoxy(5,17);   printf("9: Infantil.");
         gotoxy(5,18);   printf("0: Salir.");
         gotoxy(9,19);   printf("Seleccione: ");
         seleccion = getche() - 48;
      } while (seleccion < 0 || seleccion > 9);

      if (seleccion != 0)
      {
         j += generosSeleccionados[seleccion - 1] ? -1 : 1;
         generosSeleccionados[seleccion - 1] = generosSeleccionados[seleccion - 1] ? 0 : 1;
      }
   } while (seleccion != 0);

   nuevaPelicula.Generos = (char**) malloc(j*sizeof(char*));
   nuevaPelicula.CantidadGeneros = j;
   for (i = 0, j = 0; i < 9; i++)
   {
      if (generosSeleccionados[i])
      {
         *(nuevaPelicula.Generos + j) = (char*) calloc(max_word, sizeof(char));

         switch(i)
         {
         case 0:
            strcpy(*(nuevaPelicula.Generos + j), "Accion");
            break;
         case 1:
            strcpy(*(nuevaPelicula.Generos + j), "Aventura");
            break;
         case 2:
            strcpy(*(nuevaPelicula.Generos + j), "Comedia");
            break;
         case 3:
            strcpy(*(nuevaPelicula.Generos + j), "Drama");
            break;
         case 4:
            strcpy(*(nuevaPelicula.Generos + j), "Terror");
            break;
         case 5:
            strcpy(*(nuevaPelicula.Generos + j), "Musical");
            break;
         case 6:
            strcpy(*(nuevaPelicula.Generos + j), "Ciencia Ficcion");
            break;
         case 7:
            strcpy(*(nuevaPelicula.Generos + j), "Suspenso");
            break;
         case 8:
            strcpy(*(nuevaPelicula.Generos + j), "Infantil");
            break;
         }
         j++;
      }
   }

   /// Mostramos los generos:
   system("cls || clear");
   mostrar_marco();

   gotoxy(10, 3);
   printf("Agregando nueva pel%ccula al final de la lista.", 161);

   nuevaPelicula.Sinopsis = (char*) malloc(max_paragraph*sizeof(char));
   gotoxy(5, 5);
   printf("Sinopsis (hasta 200 letras): ");
   fflush(stdin);
   gotoxy(8, 7);
   gets(nuevaPelicula.Sinopsis);

   if (aModificar == NULL && !enOrden)
      AgregarPelicula(nuevaPelicula, listado->Cabeza->anterior);
   else if (aModificar == NULL)
   {
      Nodo *despuesDe = BuscarPorAnyo(listado, nuevaPelicula.Anyo);
      AgregarPelicula(nuevaPelicula, despuesDe);
   }
   else
   {
      aModificar->data = nuevaPelicula;
   }

   return;
}

void ExplorarPeliculas(Lista* listado, Nodo* aConsultar)
{
   char seleccion;
   Nodo *nodoActual = (Nodo*)malloc(sizeof(Nodo));
   if (aConsultar == NULL)
      nodoActual = listado->Cabeza->siguiente;
   else
      nodoActual = aConsultar;

   do
   {
      mostrar_marco_3_columnas();

      if (nodoActual->data.id == -1)
      {
         system("cls");
         printf("No hay pel%cculas registradas.", 161);
         system("pause");
         break;
      }

      MostrarPeliculaEnColumna(nodoActual->data, 2);
      if (nodoActual->anterior->data.id == -1)
         MostrarPeliculaEnColumna(nodoActual->anterior->anterior->data, 1);
      else
         MostrarPeliculaEnColumna(nodoActual->anterior->data, 1);

      if (nodoActual->siguiente->data.id == -1)
         MostrarPeliculaEnColumna(nodoActual->siguiente->siguiente->data, 3);
      else
         MostrarPeliculaEnColumna(nodoActual->siguiente->data, 3);

      gotoxy(1, 25);       printf("A: anterior");
      gotoxy(COL1, 25);    printf("X: salir");
      gotoxy(COL2, 25);    printf("D: siguiente");
      fflush(stdin);

      seleccion = getch();

      if (tolower(seleccion) == 'a')
      {
         nodoActual = nodoActual->anterior;
         if (nodoActual->data.id == -1)
            nodoActual = nodoActual->anterior;
      }
      else if (tolower(seleccion) == 'd')
      {
         nodoActual = nodoActual->siguiente;
         if (nodoActual->data.id == -1)
            nodoActual = nodoActual->siguiente;
      }

   } while (tolower(seleccion) != 'x');
}

void BorrarPelicula(Lista *listadoPeliculas)
{
   int idPelicula;
   Nodo *nodoActual;
   system("cls");
   mostrar_marco();

   gotoxy(10, 3);
   printf("Eliminando Pel%ccula existente.", 161);

   gotoxy(5, 7);
   printf("Digite el ID: ");
   scanf("%d", &idPelicula);

   nodoActual = BuscarPorId(listadoPeliculas, idPelicula);

   if (nodoActual == NULL)
   {
      gotoxy(5, 9);   printf("Esta Pel%ccula no existe", 161);
      gotoxy(5, 10);  system("pause");
      return;
   }

   EliminarPelicula(listadoPeliculas, nodoActual);
   return;
}

void MostrarPeliculaEnColumna(Pelicula aMostrar, int numeroColumna)
{
   int colActual, i = 0;

   if (numeroColumna <= 1)
      colActual = 1;
   else if (numeroColumna == 2)
      colActual = COL1;
   else
      colActual = COL2;

   gotoxy(colActual + 1, 3);
   printf("%4.4d %.*s", aMostrar.id, max_line, aMostrar.Titulo);
   gotoxy(colActual + 1, 5);
   printf("%4d - %.2f - %.1f", aMostrar.Anyo, aMostrar.Calificacion, aMostrar.Duracion);
   gotoxy(colActual + 1, 7);
   printf("Clasif.: %.20s", aMostrar.Clasificacion);

   gotoxy(colActual + 1, 9);
   printf("G%cneros:", 130);

   while(i < aMostrar.CantidadGeneros) // o Null
   {
      gotoxy(colActual + 2, 10 + i);
      printf("%.*s", max_line, *(aMostrar.Generos + i++));
   }
   gotoxy(colActual + 1, 10 + i);
   MostrarSinopsis(colActual + 1, 10 + i, max_line, aMostrar.Sinopsis);
}

void MostrarSinopsis(int col, int fila, int limite, char *texto)
{
   int i = 0, tamano = strlen(texto);
   char *nuevoTexto = (char*)malloc(tamano*sizeof(char));
   nuevoTexto = strcpy(nuevoTexto, texto);

   while(tamano > 0)
   {
      gotoxy(col, fila + i);
      printf("%.*s", limite, nuevoTexto);
      nuevoTexto = strcpy(nuevoTexto, nuevoTexto + limite);
      i++;

      tamano -= limite;
   }
   gotoxy(col, 2);

   return;
}

void ModificarPeliculas(Lista *listadoPeliculas)
{
   int idPelicula;
   Nodo *nodoActual;
   system("cls");
   mostrar_marco();

   gotoxy(10, 3);
   printf("Modificando Pel%ccula existente.", 161);

   gotoxy(5, 7);
   printf("Digite el ID: ");
   scanf("%d", &idPelicula);

   nodoActual = BuscarPorId(listadoPeliculas, idPelicula);

   if (nodoActual == NULL)
   {
      gotoxy(5, 9);   printf("Esta Pel%ccula no existe", 161);
      gotoxy(5, 10);  system("pause");
      return;
   }

   CapturarPelicula(listadoPeliculas, nodoActual, 0);
   return;
}

void BuscarPeliculaPorAnyo(Lista *listadoPeliculas)
{
   int anyo;
   Nodo *nodoActual;
   system("cls");
   mostrar_marco();

   gotoxy(10, 3);
   printf("Buscando pel%ccula existente por a%co.", 161, 164);


   do
   {
      gotoxy(5, 7);
      printf("Digite el a%co: ", 164);
      scanf("%d", &anyo);

      if (anyo < 0)
      {
         gotoxy(5, 8);
         printf("El a%co no puede ser negativo", 164);
      }
   } while (anyo < 0);

   nodoActual = BuscarPorAnyo(listadoPeliculas, anyo);

   if (nodoActual->data.id == -1)
   {
      gotoxy(5, 10);   printf("La lista est%c vac%ca.", 160, 161);
      gotoxy(5, 11);  system("pause");
      return;
   }

   ExplorarPeliculas(listadoPeliculas, nodoActual);
   return;
}

void OrdernarPeliculasPorAnyo(Lista *listado)
{
   return;
}
void OrdernarPeliculasPorAnyo(Lista*);
