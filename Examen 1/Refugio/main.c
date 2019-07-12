#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "colas.h"

/*
   Un refugio de animales solo alberga perros y gatos, y trabaja en una forma
   de “primero que entra, primero que sale”. La gente debe adoptar el animal “más viejo”
   (basado en la fecha que llegó) de todos los animales del refugio, o pueden elegir
   entre un perro o un gato (y recibirán el animal más viejo de ese tipo). No pueden elegir
   qué animal específico se llevarán. Cree las estructuras de datos para mantener este sistema
   e implemente operaciones como Encolar, DecolarCualquiera, DecolarPerro, DecolarGato. Puede
   utilizar código de los ejercicios hechos en clase.

Pistas:
- Podríamos considerar emplear una lista de perros y gatos, y luego iterar a través de ella para
encontrar al primer perro (o gato). ¿Cuál es el impacto de hacer esto?
- Supongamos que guardamos dos listas separadas para perros y gatos. ¿Cómo podríamos encontrar el
animal más viejo de cualquier tipo? ¡Sea creativo!
- Piense en cómo lo haría en la vida real. Tendrías una lista de perros en orden cronológicos y una lista de
gatos en orden cronológico. ¿Qué dato necesitas para encontrar al animal más viejo? ¿Cómo mantendrías esta información?
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
