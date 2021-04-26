
// C++ Program for counting sort
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define RANGE 255
 
// La función principal que ordena
// la cadena dada arr [] en
// orden alfabetico
void countSort(char arr[])
{
  // La matriz de caracteres de salida
    // que habrá ordenado arr
    char output[strlen(arr)];
 
// Crea una matriz de recuento para almacenar el recuento de individuos
    // caracteres e inicializar la matriz de conteo como 0
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));
 
    // Almacenar el recuento de cada caracter
    for (i = 0; arr[i]; ++i)
        ++count[arr[i]];
 
// Cambie el recuento [i] para que el recuento [i] ahora contenga datos reales
    // posición de este carácter en la matriz de salida
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];
 
   // Construye la matriz de caracteres de salida
    for (i = 0; arr[i]; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
 
    /*
    For Stable algorithm
    for (i = sizeof(arr)-1; i>=0; --i)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }
     
    For Logic : See implementation
    */
 
// Copie la matriz de salida en arr, de modo que arr ahora
    // contiene caracteres ordenados
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}
 
// Driver  code
int main()
{
    char arr[] = "243221567";
 
    countSort(arr);
 
    cout << "Sorted character array is " << arr;
    return 0;
}
 
// This code is contributed by rathbhupendra
