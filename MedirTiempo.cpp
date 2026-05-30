#include "MedirTiempo.h"

double MedirTiempo::medir(void (*sortFunction)(int*, int), int* arr, int tamanio) {
    auto inicio = std::chrono::high_resolution_clock::now();
    sortFunction(arr, tamanio);
    auto fin = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(fin - inicio).count();
}