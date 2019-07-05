#include <stdio.h>
#include <stdlib.h>
#include "colas.h"
#include "conio.h"

typedef enum
{
   Encolar = 1,
   Decolar = 2,
   MostrarTodo = 3,
   Salir = 4
} eOpcionesMenu;

typedef enum
{
   Arriba,
   Abajo,
   Izquierda,
   Derecha,
   Enter,
   Ninguno = -1
} eFlecha;

eOpcionesMenu MostrarMenu();
eFlecha CapturarFlecha();

int main()
{
   cola *nuevaCola = startQueue();
   eOpcionesMenu entrada;
   float nuevoValor;
   int loop;

   do
   {
      entrada = MostrarMenu();
      fflush(stdin);
      clrscr();
      switch (entrada)
      {
      case Encolar:
         printf("Digite un nuevo valor: ");
         scanf("%f", &nuevoValor);
         enqueue(nuevaCola, nuevoValor);
         break;

      case Decolar:
         printf("Primer valor: %.2f\n\n", dequeue(nuevaCola));
         system("pause");
         break;

      case MostrarTodo:
         loop = 0;
         printf("Cola:\n");
         while (!isEmpty(nuevaCola))
            printf("Valor #%02d: %.2f.\n", ++loop, dequeue(nuevaCola));
         printf("\n\n\n");
         system("pause");
         break;

      case Salir:
         break;

      }
   } while (entrada != Salir);

   textbackground(BLACK);
   clrscr();
   printf("Muchas gracias!!\n\n");
   return 0;
}

eOpcionesMenu MostrarMenu()
{
   eOpcionesMenu seleccion = Encolar;
   fflush(stdin);
   _setcursortype(0);
   do
   {
//      textbackground()
      textbackground(BLACK);
      clrscr();

      textbackground(seleccion == Encolar ? CYAN : BLACK);
      printf("1: Agregar valor.\n");
      textbackground(seleccion == Decolar ? CYAN : BLACK);
      printf("2: Mostrar valor.\n");
      textbackground(seleccion == MostrarTodo ? CYAN : BLACK);
      printf("3: Mostrar todos los valores.\n");
      textbackground(seleccion == Salir ? CYAN : BLACK);
      printf("0: Salir.");

      switch(CapturarFlecha())
      {
      case Arriba:
         seleccion = seleccion == Encolar ? Salir : seleccion - 1;
         break;
      case Abajo:
         seleccion = seleccion == Salir ? Encolar : seleccion + 1;
         break;

      case Enter:
         return seleccion;
      default:
         continue;
      }


   } while (1);
}

eFlecha CapturarFlecha()
{
   fflush(stdin);
   if (getch() == 13)
      return Enter;

   switch (getch())
   {
   case 72:
      return Arriba;

   case 80:
      return Abajo;

   case 77:
      return Derecha;

   case 75:
      return Izquierda;

   default:
      return Ninguno;
   }
}
