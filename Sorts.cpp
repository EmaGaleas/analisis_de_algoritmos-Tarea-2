#include "Sorts.h"
#include <algorithm> 
using std::swap;

// bubbleSort
void Sorts::bubbleSort(int arr[], int tamanio) {
    for (int i = 0; i < tamanio - 1; i++) {
        bool huboCambio = false;
        for (int j = 0; j < tamanio - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                huboCambio = true;
            }
        }
        if (!huboCambio) break;
    }
}

// selectionSort
void Sorts::selectionSort(int arr[], int tamanio) {
    for (int i = 0; i < tamanio - 1; i++) {
        int indiceMenor = i;
        for (int j = i + 1; j < tamanio; j++) {
            if (arr[j] < arr[indiceMenor]) {
                int aux = arr[j];
                arr[j] = arr[indiceMenor];
                arr[indiceMenor] = aux;
            }
        }
    }
}

// insertionSort
void Sorts::insertionSort(int arr[], int tamanio) {
    if (tamanio <= 1) return;
    insertionSort(arr, tamanio - 1);

    int ultimo = arr[tamanio - 1];
    int pos = tamanio - 2;

    for (; pos >= 0 && arr[pos] > ultimo; pos--) {
        arr[pos + 1] = arr[pos];
    }
    arr[pos + 1] = ultimo;
}

// mergeSort
void Sorts::mergeSort(int arr[], int tamanio) {
    if (tamanio < 2) return;
    mergeSortHelper(arr, 0, tamanio - 1);
}

void Sorts::mergeSortHelper(int arr[], int izq, int der) {
    if (izq >= der) return;
    int corte = izq + (der - izq) / 2;
    mergeSortHelper(arr, izq, corte);
    mergeSortHelper(arr, corte + 1, der);
    fusionar(arr, izq, corte, der);
}

void Sorts::fusionar(int arr[], int izq, int mid, int der) {
    int n1 = mid - izq + 1;
    int n2 = der - mid;

    int* izquierda = new int[n1];
    int* derecha   = new int[n2];

    for (int x = 0; x < n1; x++) 
        izquierda[x] = arr[izq + x];
    for (int x = 0; x < n2; x++) 
        derecha[x]   = arr[mid + 1 + x];

    int a, b, pos = izq;
    a = b = 0;

    while (a < n1 && b < n2)
        arr[pos++] = (izquierda[a] <= derecha[b]) ? izquierda[a++] : derecha[b++];

    while (a < n1) arr[pos++] = izquierda[a++];
    while (b < n2) arr[pos++] = derecha[b++];

    delete[] izquierda;
    delete[] derecha;
}

// heapSort
void Sorts::heapSort(int arr[], int tamanio) {
    for (int i = tamanio / 2 - 1; i >= 0; i--) {
        heapify(arr, tamanio, i);
    }

    for (int i = tamanio - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void Sorts::heapify(int arr[], int tamanio, int raiz) {
    while (true) {
        int mayor = raiz;
        int hijoIzq = 2 * raiz + 1;
        int hijoDer = 2 * raiz + 2;

        if (hijoIzq < tamanio && arr[hijoIzq] > arr[mayor])
            mayor = hijoIzq;
        if (hijoDer < tamanio && arr[hijoDer] > arr[mayor])
            mayor = hijoDer;
        if (mayor == raiz)
            break;

        swap(arr[raiz], arr[mayor]);
        raiz = mayor;
    }
}

// quickSort
void Sorts::quickSort(int arr[], int tamanio) {
    if (tamanio <= 1) return;
    quickSortHelper(arr, 0, tamanio - 1);
}

void Sorts::quickSortHelper(int arr[], int izquierdo, int derecho) {
    if (izquierdo >= derecho) return;

    int pivote_final = particion(arr, izquierdo, derecho);
    quickSortHelper(arr, izquierdo, pivote_final - 1);
    quickSortHelper(arr, pivote_final + 1, derecho);
}

int Sorts::medianaDeTres(int arr[], int izquierdo, int derecho) {
    int medio = izquierdo + (derecho - izquierdo) / 2;
    if (arr[izquierdo] > arr[medio])
        swap(arr[izquierdo], arr[medio]);
    if (arr[izquierdo] > arr[derecho])
        swap(arr[izquierdo], arr[derecho]);
    if (arr[medio] > arr[derecho])
        swap(arr[medio], arr[derecho]);

    swap(arr[medio], arr[derecho - 1]);
    return arr[derecho - 1];
}

int Sorts::particion(int arr[], int izquierdo, int derecho) {
    int pivote = medianaDeTres(arr, izquierdo, derecho);
    int i = izquierdo - 1;

    for (int j = izquierdo; j < derecho - 1; j++) {
        if (arr[j] <= pivote) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[derecho - 1]);
    return i + 1;
}