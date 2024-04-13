#ifndef AIZO_PROJEKT_1_QUICKSORT_H
#define AIZO_PROJEKT_1_QUICKSORT_H
#include <vector>
#include "../Menu/Arrays.h"

class QuickSort{
public:
    static int partition(int *arr, int left, int right, int pivot);
    static long long sort_left(int *arr, int l, int p);
    static long long sort_right(int *arr, int l, int p);
    static long long sort_center(int *arr, int l, int p);
    static long long sort_rand(int *arr, int l, int p);
};
#endif //AIZO_PROJEKT_1_QUICKSORT_H