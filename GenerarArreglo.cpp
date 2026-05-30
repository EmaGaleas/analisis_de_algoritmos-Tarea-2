#include "GenerarArreglo.h"
#include <cstdlib> 

void GenerarArreglo::generar(int arr[], int tamanio) {
    for(int i = 0; i < tamanio; i++) {
        arr[i] = rand();
    }
}