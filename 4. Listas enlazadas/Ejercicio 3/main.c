#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila_enlazada.h"
/*
   Realice un programa que permita visualizar un histograma
   partiendo de una serie de valores guardados en una pila dinámica
   capturados por teclado, utilizando listas enlazadas.
*/

#define NULL 0

void MostrarEncabezadoHistograma();
void MostrarElementoHistograma(int, float, float);
void MostrarPieHistograma(int, float);
void imprime_grafico(float, float);

int main()
{
   const Nodo* cabeza = NULL;
   Nodo* miPila = crear_nodo(-1, cabeza);

   float num, suma = 0;
   int loop;

   printf("Programa para imprimir un histograma de los valores ingresados.\n");
   do
   {
      printf("Ingrese un valor (-1 para terminar): ");
      scanf("%f", &num);

      if (num >= 0)
      {
         miPila = push_nodo(miPila, num);
         suma += num;
      }
   } while (num >= 0);

   system("pause");
   system("cls || clear");

   printf("\n\nHistograma:\n");
   MostrarEncabezadoHistograma();

   loop = 0;
   while (miPila->enlace)
   {
      miPila = pop_nodo(miPila, &num);
      MostrarElementoHistograma(++loop, num, (num/suma) * 100);
   }

   MostrarPieHistograma(loop, suma);
   printf("\n\n");

   system("pause");

   return 0;
}

void MostrarEncabezadoHistograma()
{
   system("cls || clear");
   printf("HISTOGRAMA\n\n");
   printf("No.:\tValor:\tProporci%cn:\n", 162);
}

void MostrarElementoHistograma(int secuencia, float valor, float proporcion)
{
   int cantidadCaracteres = (int)proporcion;
   printf("%d\t%.2f\t", secuencia, valor);

   while (cantidadCaracteres-- > 0)
      printf("%c", 219);

   printf(" %.2f%%\n", proporcion);
   return;
}

void MostrarPieHistograma(int cantidad, float total)
{
   printf("\nSe han mostrado %d elementos. Total %.2f.\n", cantidad, total);
   return;
}

