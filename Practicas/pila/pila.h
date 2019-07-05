
/*
   Se ponen definiciones de los tipos,
   variables, prototipos.
*/
#include <stdlib.h>

#ifndef _pila
#define _pila
#define MAX 50
//const int MAX = 50;

typedef struct
{
   int id;
   char nombre[20];
   char apellido[20];
   int edad;
   float balance;
} Persona;

typedef struct
{
   int data[MAX];
   int tam;
} apila;

int agregar (apila *, int);
int sacar (apila *, int *);

/*void Imprimir_una_persona();*/

#endif // _pila

