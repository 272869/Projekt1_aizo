#include <chrono>
#include "ShellSort.h"
#include "cmath"


long long ShellSort::shell_sort_1(int *arr, int n) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int gap = n / 2; gap > 0; gap /= 2) { //wzór na odstępy
        for (int i = gap; i < n; i++) { // Pętla przechodząca przez tablicę, rozpoczynając od pozycji równych odstępowi
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) // Pętla przechodząca przez podtablicę, wykonująca porównania i przesunięcia
                arr[j] = arr[j - gap]; // Przesunięcie elementu o gap miejsc w prawo
            arr[j] = temp;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

long long ShellSort::shell_sort_2(int *arr, int n) {
    auto start = std::chrono::high_resolution_clock::now();
    int k = 1; //zmienna do obliczania odstępów
    int gap = 1; //odstęp początkowy
    int g = gap;
    while (g < n){ //obliczamy największy odstęp mniejszy od wielkosci tablicy
        gap = g;
        g = static_cast<int>(pow(2, k) + 1); //wzór na odstępy wg. Papiernowa i Stasiewicza
        k++;
    }

    while (gap > 0){
        for (int i = gap; i < n; i += 1){ //insertion sort
            int key = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > key; j -= gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = key;
        }
        k--; // Zmniejszenie k, aby uzyskać następny odstęp
        g = static_cast<int>(pow(2, k) + 1); // Obliczenie nowego odstępu
        if(gap == 1){ //Jeśli zmienna gap przyjmuje wartość 1 to algorytm przechodzi do ostatniej iteracji sortowania
            gap = 0;
        }
        else {
            gap = g;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}