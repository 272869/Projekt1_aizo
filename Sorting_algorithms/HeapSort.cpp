#include <algorithm>
#include <chrono>
#include "HeapSort.h"

void HeapSort::heapify(int *arr, int n, int i) { //kopiowanie, n=ilosc liczb, i=indeks tworzenia kopca
    int largest = i; //indeks rodzica
    int l = 2 * i + 1; //wzór na indeks lewego potomka
    int r = 2 * i + 2; //wzór na indeks prawego potomka

    if (l < n && arr[l] > arr[largest]) //sprawdzamy czy l nie jest końcem tablicy, i czy element o indeksie l nie jest większy od rodzica
        largest = l; //jeśli jest to w miejsce

    if (r < n && arr[r] > arr[largest]) //analogicznie
        largest = r;

    if (largest != i) { //jesli indeks rodzica
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

long long HeapSort::heap_sort(int *arr, int n) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = n / 2 - 1; i >= 0; i--) //tworzy kopiec
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) { // sortuje tablicę poprzez wymianę korzenia z ostatnim elementem i naprawianie kopca w części tablicy przedostatniej.
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}