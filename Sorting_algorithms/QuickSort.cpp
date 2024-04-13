#include "QuickSort.h"
#include <algorithm>

int QuickSort::partition(int *arr, int left, int right, int pivot) {
    int l = left;
    int r = right;
    int p = pivot;
    while (1) {
        while (arr[l] < p) ++l;
        while (arr[r] > p) --r;
        if (l < r) {
            std::swap(arr[l], arr[r]);
            ++l;
            --r;
        }
        else {
            if (r == right) r--;
            return r;
        }
    }
}

void QuickSort::sort_left(int *arr, int l, int p) {
    if (l >= p) return;
    int m = partition(arr, l, p, arr[l]);
    sort_left(arr, l, m);
    sort_left(arr, m + 1, p);
}

void QuickSort::sort_right(int *arr, int l, int p) {
    if (l >= p) return;
    int m = partition(arr, l, p, arr[p]);
    sort_right(arr, l, m);
    sort_right(arr, m + 1, p);
}

void QuickSort::sort_center(int *arr, int l, int p) {
    if (l >= p) return;
    int m = partition(arr, l, p, arr[(l+p)/2]);
    sort_center(arr, l, m);
    sort_center(arr, m + 1, p);
}

void QuickSort::sort_rand(int *arr, int l, int p) {
    if (l >= p) return;
    int randIndex = l + rand() % (p - l + 1); // Losuje indeks pivota
    int m = partition(arr, l, p, arr[randIndex]);
    sort_rand(arr, l, m);
    sort_rand(arr, m + 1, p);
}
