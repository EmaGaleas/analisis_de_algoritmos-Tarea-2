#include <iostream>
#include <iomanip>
#include <algorithm>
#include "GenerarArreglo.h"
#include "MedirTiempo.h"
#include "Sorts.h"

using std::cout;
using std::endl;
using std::copy;
using std::string;
using std::fixed;
using std::setprecision;

//correr en consola con g++ main.cpp GenerarArreglo.cpp MedirTiempo.cpp Sorts.cpp -o mainF _____then ./mainF

/** 
static void imprimirMuestra(const int arr[], int tamanio, int muestra = 10) {
    cout << "[ ";
    int limite = (muestra < tamanio) ? muestra : tamanio;
    for (int i = 0; i < limite; i++) {
        cout << arr[i];
        if (i < limite - 1) cout << ", ";
    }
    if (limite < tamanio) cout << " ...";
    cout << " ]\n";
}
*/

static void ejecutarSort(const char* nombre, void (*sortFunction)(int*, int), const int* base, int* copia, int  tamanio){
    copy(base, base + tamanio, copia);

    cout << "\n----------------------" << nombre << "----------------------\n ";
   // cout << "\tArreglo Original: ";
   // imprimirMuestra(copia, tamanio);

    double ms = MedirTiempo::medir(sortFunction, copia, tamanio);

   // cout << "\tArreglo Ordenado: ";
   // imprimirMuestra(copia, tamanio);
    cout << "\tTiempo de ejecucion  : " << fixed << setprecision(8) << ms << " ms\n";
    cout << "" <<string(40, ' ') << "\n";
}

// 
int main() {
    const int tamanioArreglo = 10; 

    int* realOriginal= new int[tamanioArreglo];
    int* copia = new int[tamanioArreglo];

    GenerarArreglo::generar(realOriginal, tamanioArreglo);

    std::cout << "Tamano del arreglo: " << tamanioArreglo << "\n";
    //std::cout << "(Se muestran los primeros 10 elementos)\n";

    ejecutarSort("Bubble Sort",    Sorts::bubbleSort,    realOriginal, copia, tamanioArreglo);
    ejecutarSort("Selection Sort", Sorts::selectionSort, realOriginal, copia, tamanioArreglo);
    ejecutarSort("Insertion Sort", Sorts::insertionSort, realOriginal, copia, tamanioArreglo);
    ejecutarSort("Merge Sort",     Sorts::mergeSort,     realOriginal, copia, tamanioArreglo);
    ejecutarSort("Heap Sort",      Sorts::heapSort,      realOriginal, copia, tamanioArreglo);
    ejecutarSort("Quick Sort",     Sorts::quickSort,     realOriginal, copia, tamanioArreglo);

    delete[] realOriginal;
    delete[] copia;

    return 0;
}