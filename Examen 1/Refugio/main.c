#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "colas.h"

/*
   Un refugio de animales solo alberga perros y gatos, y trabaja en una forma
   de �primero que entra, primero que sale�. La gente debe adoptar el animal �m�s viejo�
   (basado en la fecha que lleg�) de todos los animales del refugio, o pueden elegir
   entre un perro o un gato (y recibir�n el animal m�s viejo de ese tipo). No pueden elegir
   qu� animal espec�fico se llevar�n. Cree las estructuras de datos para mantener este sistema
   e implemente operaciones como Encolar, DecolarCualquiera, DecolarPerro, DecolarGato. Puede
   utilizar c�digo de los ejercicios hechos en clase.

Pistas:
- Podr�amos considerar emplear una lista de perros y gatos, y luego iterar a trav�s de ella para
encontrar al primer perro (o gato). �Cu�l es el impacto de hacer esto?
- Supongamos que guardamos dos listas separadas para perros y gatos. �C�mo podr�amos encontrar el
animal m�s viejo de cualquier tipo? �Sea creativo!
- Piense en c�mo lo har�a en la vida real. Tendr�as una lista de perros en orden cronol�gicos y una lista de
gatos en orden cronol�gico. �Qu� dato necesitas para encontrar al animal m�s viejo? �C�mo mantendr�as esta informaci�n?
*/

Animales obtener_tipo();

int main()
{
   cola* miRefugio = startQueue();
   animal nuevo = inicializar_animal();
   char volver = 'n';
   Animales seleccionar;


   printf("Refugio de animales.\n\n");
   system("pause");

   do
   {
      system("cls || clear");
      printf("Tipos de animales: Perro (1), Gato (2)\n\n");
      printf("Ingresar un animal:\n");
      printf("Nombre: ");
      gets(nuevo.nombre);
      seleccionar = obtener_tipo();
      nuevo.tipo = seleccionar;
      enqueue(miRefugio, nuevo);

      printf("\n\nDesea volver a ingresar [N para terminar]: ");
      volver = tolower(getche());
   } while (volver != 'n');

   do
   {
      printf("Que desea sacar? [0 para retornar el mas viejo]: ");
      seleccionar = obtener_tipo();

      nuevo = dequeue(miRefugio, seleccionar);
      printf("\nNombre: %s\t\tTipo: %s", nuevo.nombre, nuevo.tipo == gato ? "Gato" : "Perro");
   } while (!isEmpty(miRefugio));


   return 0;
}

Animales obtener_tipo()
{
   int d;
   Animales ans;
   do
   {
      printf("Tipo (Ingrese el n%cmero de tipo): ", 163);
      scanf("%d", &d);

      if (d > 2 || d < 0)
         printf("Ingrese un tipo correcto de animal.\n");

   } while (d > 2 || d < 0);
   ans = d == 0 ? nada : d;

   return ans;
}
