/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
using namespace std; 
  
// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
/* Esta función toma el último elemento como pivote, coloca
el elemento pivote en su posición correcta en ordenados
matriz, y coloca todos más pequeños (más pequeños que pivote)
a la izquierda del pivote y todos los elementos mayores a la derecha
de pivote */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Índice del elemento más pequeño e indica la posición correcta del pivote encontrado hasta ahora
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // Si el elemento actual es más pequeño que el pivote
        if (arr[j] < pivot) 
        { 
            i++; // índice de incremento del elemento más pequeño 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* La función principal que implementa QuickSort
arr [] -> Matriz a ordenar,
low -> Índice de inicio,
high -> Índice final */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
       /* pi es un índice de partición, arr [p] es ahora
        en el lugar correcto */
        int pi = partition(arr, low, high); 
  
      // Ordena los elementos por separado antes
        // partición y después de la partición
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
  
/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 
  
// Driver Code
int main() 
{ 
    int arr[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    quickSort(arr, 0, n - 1); 
    cout << "Sorted array: \n"; 
    printArray(arr, n); 
    return 0; 
} 
  
// This code is contributed by rathbhupendra
