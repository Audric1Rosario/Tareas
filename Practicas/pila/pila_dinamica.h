#include <stdlib.h>

#ifndef _pila_dinamica
#define _pila_dinamica

// typedef
typedef struct
{
   int *data;
   int tam;
} piladin;

// Prototipos
int agregar_din (piladin *, int *);
int sacar_din (piladin *, int *);

#endif // _pila_dinamica
