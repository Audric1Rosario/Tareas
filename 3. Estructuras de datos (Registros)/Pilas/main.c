#include <stdio.h>
#include <stdlib.h>
#include "PilaEstatica.h"

void MostrarEncabezadoHistograma();
void MostrarElementoHistograma(int, float, float);
void MostrarPieHistograma(int, float);
void imprime_grafico(float, float);

int main()
{
   Pila *miPila;
   float num, suma = 0;
   int loop;

   miPila = IniciarPila();
   printf("Programa para imprimir un histograma de los valores ingresados.\n");

   do
   {
      printf("Ingrese un valor (-1 para terminar): ");
      scanf("%f", &num);

      if (num >= 0)
      {
         Push(miPila, num);
         suma += num;
      }
   } while (num >= 0);

   system("cls || clear");

   printf("\n\nHistograma:\n");
   loop = 0;

   MostrarEncabezadoHistograma();
   while (!isEmpty(miPila))
   {
      num = Pop(miPila);
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
