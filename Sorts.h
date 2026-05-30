#ifndef SORTS_H
#define SORTS_H

class Sorts {
    public:
        static void bubbleSort(int arr[], int tamanio);
        static void selectionSort(int arr[], int tamanio);
        static void insertionSort(int arr[], int tamanio);
        static void mergeSort(int arr[], int tamanio);
        static void heapSort(int arr[], int tamanio);
        static void quickSort(int arr[], int tamanio);

    private:
    //del merge
        static void mergeSortHelper(int arr[], int left, int right);
        static void fusionar(int arr[], int izq, int mid, int der);
    //quick    
        static void quickSortHelper(int arr[], int izq, int der);
        static int  particion(int arr[], int izq, int der);
        static int  medianaDeTres(int arr[], int izq, int der);
    // Heap 
        static void heapify(int arr[], int tamanio, int raiz);
};

#endif

