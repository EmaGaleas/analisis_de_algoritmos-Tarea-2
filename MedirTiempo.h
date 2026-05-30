#ifndef MEDIRTIEMPO_H
#define MEDIRTIEMPO_H
#include <chrono>
#include "Sorts.h"

class MedirTiempo {
    public:
        static double medir(void (*sortFunction)(int*, int), int* arr, int tamanio);
};

#endif