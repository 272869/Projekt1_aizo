#include "ShellSort.h"
#include "cmath"


void ShellSort::shell_sort_1(int *arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) { //wzór na odstępy
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}



void ShellSort::shell_sort_2(int *arr, int n) {
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
        k--;
        g = static_cast<int>(pow(2, k) + 1);
        if(gap == 1){ //Jeśli zmienna gap przyjmuje wartość 1 to algorytm przechodzi do ostatniej iteracji sortowania
            gap = 0;
        }
        else {
            gap = g;
        }
    }
}