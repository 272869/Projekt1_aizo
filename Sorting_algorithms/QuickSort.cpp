#include "QuickSort.h"
#include <algorithm>
#include <stack>

/*int QuickSort::partition(int *arr, int left, int right, int pivot) {
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

long long QuickSort::sort_left(int *arr, int l, int p) {
    auto start = std::chrono::high_resolution_clock::now();
    if (l >= p) return 0;
    int m = partition(arr, l, p, arr[l]);
    sort_left(arr, l, m);
    sort_left(arr, m + 1, p);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

long long QuickSort::sort_right(int *arr, int l, int p) {
    auto start = std::chrono::high_resolution_clock::now();
    if (l >= p) return 0;
    int m = partition(arr, l, p, arr[p]);
    sort_right(arr, l, m);
    sort_right(arr, m + 1, p);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

long long QuickSort::sort_center(int *arr, int l, int p) {
    auto start = std::chrono::high_resolution_clock::now();
    if (l >= p) return 0;
    int m = partition(arr, l, p, arr[(l+p)/2]);
    sort_center(arr, l, m);
    sort_center(arr, m + 1, p);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

long long QuickSort::sort_rand(int *arr, int l, int p) {
    auto start = std::chrono::high_resolution_clock::now();
    if (l >= p) return 0;
    int randIndex = l + rand() % (p - l + 1); // Losuje indeks pivota
    int m = partition(arr, l, p, arr[randIndex]);
    sort_rand(arr, l, m);
    sort_rand(arr, m + 1, p);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}
*/

int QuickSort::partition(int *arr, int left, int right, int pivot) {
   // std::cout << "pivot: " << pivot << "   " ;
    if(right != pivot){
        int temp = arr[right];
        arr[right] = arr[pivot];
        arr[pivot] = temp;
    }
    int p = arr[right];
    int j = left;
    for (int i = left; i < right; i++){
        if(arr[i] <= p){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            j++;
        }
    }
    int temp = arr[j];
    arr[j] = arr[right];
    arr[right] = temp;
    return j;
}

long long QuickSort::sort_left(int *arr, int size) {
    auto start = std::chrono::high_resolution_clock::now();
    if (size <= 1) return 0;

    std::stack<std::pair<int, int>> stack;
    stack.push({0, size - 1});

    while (!stack.empty()) {
        auto range = stack.top();
        stack.pop();

        int low = range.first;
        int high = range.second;

        if (low < high) {
            int pivot_index = partition(arr, low, high, low);
            stack.push({low, pivot_index - 1});
            stack.push({pivot_index + 1, high});
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

long long QuickSort::sort_right(int *arr, int size) {
    auto start = std::chrono::high_resolution_clock::now();
    if (size <= 1) return 0;

    std::stack<std::pair<int, int>> stack;
    stack.push({0, size - 1});

    while (!stack.empty()) {
        auto range = stack.top();
        stack.pop();

        int low = range.first;
        int high = range.second;

        if (low < high) {
            int pivot_index = partition(arr, low, high, high);
            stack.push({low, pivot_index - 1});
            stack.push({pivot_index + 1, high});
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

long long QuickSort::sort_center(int *arr, int size) {
    auto start = std::chrono::high_resolution_clock::now();
    if (size <= 1) return 0;

    std::stack<std::pair<int, int>> stack;
    stack.push({0, size - 1});

    while (!stack.empty()) {
        auto range = stack.top();
        stack.pop();

        int low = range.first;
        int high = range.second;

        if (low < high) {
            int pivot_index = partition(arr, low, high, ((high-low)/2 + low));
            stack.push({low, pivot_index - 1});
            stack.push({pivot_index + 1, high});
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

long long QuickSort::sort_rand(int *arr, int size) {
    auto start = std::chrono::high_resolution_clock::now();
    if (size <= 1) return 0;

    std::stack<std::pair<int, int>> stack;
    stack.push({0, size - 1});

    std::mt19937 rng;
    rng.seed(std::chrono::system_clock::now().time_since_epoch().count());

    while (!stack.empty()) {
        auto range = stack.top();
        stack.pop();

        int low = range.first;
        int high = range.second;

        std::uniform_int_distribution<int> distribution(low, high);
        int random = distribution(rng);

        if (low < high) {
            //std::cout << "piv rand: " << random << "   " ;
            int pivot_index = partition(arr, low, high, random);
            //std::cout << "piv inx: " << pivot_index << "   " ;
            stack.push({low, pivot_index - 1});
            stack.push({pivot_index + 1, high});
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}