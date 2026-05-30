#include "Sorts.h"
#include <algorithm>  // std::swap, std::copy

// bubbleSort teoría dicta O(n²) promedio/peor caso y O(n) es el mejor caso 
void Sorts::bubbleSort(int arr[], int tamanio) {
    for (int i = 0; i < tamanio - 1; i++) {
        bool huboIntercambio = false;

        for (int j = 0; j < tamanio - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                huboIntercambio = true;
            }
        }

        if (!huboIntercambio) break;
    }
}

// selectionSort teoría dicta O(n²) siempre 
void Sorts::selectionSort(int arr[], int tamanio) {
    for (int i = 0; i < tamanio - 1; i++) {
        int indiceMenor = i;

        for (int j = i + 1; j < tamanio; j++) {
            if (arr[j] < arr[indiceMenor]) {
                indiceMenor = j;
            }
        }

        if (indiceMenor != i) {
            std::swap(arr[i], arr[indiceMenor]);
        }
    }
}

// insertionSort teoría dicta O(n²) promedio/peor caso y O(n) es el mejor caso 
void Sorts::insertionSort(int arr[], int tamanio) {
    for (int i = 1; i < tamanio; i++) {
        int clave = arr[i];
        int j     = i - 1;

        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = clave;
    }
}

// mergeSort teoría dicta O(nlogn) siempre
void Sorts::mergeSort(int arr[], int tamanio) {
    if (tamanio < 2) return;
    mergeSortHelper(arr, 0, tamanio - 1);
}

void Sorts::mergeSortHelper(int arr[], int izq, int der) {
    if (izq >= der) return;

    int mid = izq + (der - izq) / 2;   // evita desbordamiento vs (izq+der)/2

    mergeSortHelper(arr, izq, mid);
    mergeSortHelper(arr, mid + 1, der);
    fusionar(arr, izq, mid, der);
}

void Sorts::fusionar(int arr[], int izq, int mid, int der) {
    int tamanioIzq = mid - izq + 1;
    int tamanioDer = der - mid;

    // Buffers temporales
    int* izqArr = new int[tamanioIzq];
    int* derArr = new int[tamanioDer];

    std::copy(arr + izq,       arr + izq + tamanioIzq, izqArr);
    std::copy(arr + mid + 1,   arr + mid + 1 + tamanioDer, derArr);

    int i = 0, j = 0, k = izq;

    while (i < tamanioIzq && j < tamanioDer) {
        if (izqArr[i] <= derArr[j]) {
            arr[k++] = izqArr[i++];
        } else {
            arr[k++] = derArr[j++];
        }
    }

    while (i < tamanioIzq) arr[k++] = izqArr[i++];
    while (j < tamanioDer)  arr[k++] = derArr[j++];

    delete[] izqArr;
    delete[] derArr;
}

// heapSort teoría dicta O(nlogn) siempre, casos especiales es O(n)
void Sorts::heapSort(int arr[], int tamanio) {
    // Construir el max-heap
    for (int i = tamanio / 2 - 1; i >= 0; i--) {
        heapify(arr, tamanio, i);
    }

    // Extraer elementos del heap de mayor a menor
    for (int i = tamanio - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void Sorts::heapify(int arr[], int tamanio, int raiz) {
    int mayor    = raiz;
    int hijoIzq  = 2 * raiz + 1;
    int hijoDer  = 2 * raiz + 2;

    if (hijoIzq < tamanio && arr[hijoIzq] > arr[mayor]) mayor = hijoIzq;
    if (hijoDer < tamanio && arr[hijoDer] > arr[mayor]) mayor = hijoDer;

    if (mayor != raiz) {
        std::swap(arr[raiz], arr[mayor]);
        heapify(arr, tamanio, mayor);
    }
}

// quickSort teoría dicta O(nlogn) promedio y O(n²) peor caso

void Sorts::quickSort(int arr[], int tamanio) {
    if (tamanio < 2) return;
    quickSortHelper(arr, 0, tamanio - 1);
}

void Sorts::quickSortHelper(int arr[], int izq, int der) {
    // Para subarreglos pequeños, insertion sort es más eficiente
    if (der - izq < 16) {
        for (int i = izq + 1; i <= der; i++) {
            int clave = arr[i];
            int j     = i - 1;
            while (j >= izq && arr[j] > clave) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = clave;
        }
        return;
    }

    int indicePivote = particion(arr, izq, der);
    quickSortHelper(arr, izq, indicePivote - 1);
    quickSortHelper(arr, indicePivote + 1, der);
}

int Sorts::medianaDeTres(int arr[], int izq, int der) {
    int mid = izq + (der - izq) / 2;

    // Ordena los tres candidatos en su lugar y retorna el índice del medio
    if (arr[izq] > arr[mid]) std::swap(arr[izq], arr[mid]);
    if (arr[izq] > arr[der]) std::swap(arr[izq], arr[der]);
    if (arr[mid] > arr[der]) std::swap(arr[mid], arr[der]);

    // Coloca el pivote en der-1 para dejarlo fuera de la partición
    std::swap(arr[mid], arr[der - 1]);
    return der - 1;
}

int Sorts::particion(int arr[], int izq, int der) {
    int indicePivote = medianaDeTres(arr, izq, der);
    int pivote       = arr[indicePivote];

    int i = izq;
    int j = der - 1;

    while (true) {
        while (arr[++i] < pivote) {}
        while (arr[--j] > pivote) {}

        if (i >= j) break;
        std::swap(arr[i], arr[j]);
    }

    // Restaura el pivote a su posición final
    std::swap(arr[i], arr[der - 1]);
    return i;
}