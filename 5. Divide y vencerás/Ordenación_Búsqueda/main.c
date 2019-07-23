#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Usuario
void CapturarValores(int[], int);
void MostrarValores(int[], int);

// Búsqueda
int linealsearch(int[], int, int);
int lsearch(int[], int, int);
int linealsearch_recursive(int[], int, int, int);

int binarysearch(int[], int, int);
int binarysearch_recursive(int [], int, int, int);

// Números Aleatorios
void aleatory_numbers(int[], int, int, int);

void anumbers(int[], int);
long aleatory_numbers_recursive(int[], int, int);

int randomize(int, int);

// Ordenación
void mergesort(int[], int, int);
void merge(int[], int, int, int);

void QuickSort(int[], int);
void QSrecursive(int[], int, int);
int particionar(int[], int, int);

// Intercambio
void swap_arr(int[], int, int);
void swap(int*, int*);

const int MIN = 0;
const int MAX = 1000;

int main()
{
    int n, dest, pos;
    printf("Digite el tama%co del arreglo.\n", 164);
    scanf("%d", &n);

    int arreglo[n];
    anumbers(arreglo, n);

    //CapturarValores(arreglo, n);
    MostrarValores(arreglo, n);

    printf("Digite el valor que desea buscar: ");
    scanf("%d", &dest);

    pos = binarysearch(arreglo, n, dest);
    printf("El valor %d, esta en la posici%cn %d.\n\n", dest, 162, pos);
    system("pause");

    QuickSort(arreglo, n);
    MostrarValores(arreglo, n);
    pos = binarysearch(arreglo, n, dest);
    printf("Luego de ordenar el valor %d, esta en la posici%cn %d.\n\n", dest, 162, pos);


    return 0;
}

/// Usuario
void CapturarValores(int arr[], int n)
{
   int i;

   system("cls");
   for (i = 0; i < n; i++)
   {
      printf("Ingrese valor #%d: ", i + 1);
      scanf("%d", &arr[i]);
   }
}

void MostrarValores(int arr[], int n)
{
   int i;

   system("cls");
   printf("Valores capturados:\n");
   for (i = 0; i < n; i++)
   {
      printf("Valor #%d: %d\n", i + 1, arr[i]);
   }
   printf("\n\n");
   system("pause");
}

/// Búsqueda
int linealsearch(int arr[], int n, int ele)
{
   int i;
   for (i = 0; i < n; i++)
   {
      if (arr[i] == ele)
         return i;
   }
   /// Valor inválido
   return -1;
}

/*
   A esta estrategia se le llama currificación
   consiste en poner una función mas sencilla y bonita para hacer la
   llamada a la recursiva
*/
int lsearch(int arr[], int n, int ele)
{
   return linealsearch_recursive(arr, n, 0, ele);
}

int linealsearch_recursive(int arr[], int n, int pos, int ele)
{
   if (pos >= n)
      return -1;

   return arr[pos] == ele ? pos : linealsearch_recursive(arr, n, pos + 1, ele);

}

int binarysearch(int arr[], int n, int dest)
{
   return binarysearch_recursive(arr, dest, 0, n - 1);
}

int binarysearch_recursive(int arr[], int ele, int l, int r)
{
   int m;
   if (r < l)
      return -1;

   m = l + (r - l) / 2;
   if (arr[m] == ele)
      return m;
   if (arr[m] < ele)
      return binarysearch_recursive(arr, ele, m+1, r);

   return binarysearch_recursive(arr, ele, l, m-1);

   //return -1;
}

/// Números aleatorios
void aleatory_numbers(int arr[], int n, int a, int b)
{
   int i;
   srand(time(NULL));
   for (i = 0; i < n; i++)
   {
      arr[i] = randomize(a, b);
   }
}

void anumbers(int numbers[], int n)
{
   srand(time(NULL));
   long sumatoria = aleatory_numbers_recursive(numbers, n, 0);
   printf("\nLa sumatoria de los aleatorios es: %ld\n", sumatoria);
   system("pause");
   return;
}

long aleatory_numbers_recursive(int num[], int n, int pos)
{
   if (pos >= n)
      return 0;

   num[pos] = randomize(MIN, MAX);

   return num[pos] + aleatory_numbers_recursive(num, n, pos+1);
}

int randomize(int a, int b)
{
   return rand() % (b - a + 1) + a;
}

/// Ordenación por mezcla
void mergesort(int arr[], int l, int r)
{
   if (l < r)
   {
      int m = l + (r - l) / 2;
      mergesort(arr, l, m);
      mergesort(arr, m + 1, r);

      merge(arr, l, m, r);
   }

   return;
}

void merge(int arr[], int l, int m, int r)
{
   int i, j, k;
   int a, b;

   a = m - l + 1;
   b = r - m;

   // Crear arreglos temporales
   int array_a[a], array_b[b];

   // Copiar los datos del arreglo desde cada limite.
   for (i = 0; i < a; i++)
      array_a[i] = arr[l + i];
   for (j = 0; j < b; j++)
      array_b[j] = arr[m + 1 + j];

   i = 0;
   j = 0;
   k = l;
   // Mezclar los elementos
   while (i < a && j < b)
   {
      if (array_a[i] <= array_b[j])
         arr[k] = array_a[i++];
      else
         arr[k] = array_b[j++];
      k++;
   }

   // Terminar de copiar los elementos que faltan.
   while (i < a)
      arr[k++] = array_a[i++];

   while (j < b)
      arr[k++] = array_b[j++];

   return;
}

void QuickSort(int lista[], int cant)
{
   QSrecursive(lista, 0, cant - 1);
   return;
}

void QSrecursive(int lista[], int a, int b)
{
   int indpiv;

   if (a >= b)
      return;

   indpiv = particionar(lista, a, b);
   QSrecursive(lista, a, indpiv - 1);
   QSrecursive(lista, indpiv + 1, b);
   return;
}

int particionar(int lista[], int a, int b)
{
   int pivote = lista[a], i = a + 1, j = i;

   for (; i <= b; i++)
   {
      if (lista[i] < pivote)
      {
         swap_arr(lista, i, j);
         j++;
      }
   }
   swap(&lista[a], &lista[j - 1]);

   return j - 1;
}

void swap_arr(int lista[], int a, int b)
{
   int temp = lista[b];
   lista[b] = lista[a];
   lista[a] = temp;
   return;
}

void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
   return;
}
