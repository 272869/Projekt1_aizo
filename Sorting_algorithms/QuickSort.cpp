#include "QuickSort.h"
#include <algorithm>
#include <stack>

int QuickSort::partition(int *arr, int left, int right, int pivot) {
    if(right != pivot){ // Jeśli prawy indeks nie jest równy indeksowi pivota
        std::swap(arr[right], arr[pivot]);
    }
    int p = arr[right]; // Przypisanie wartości pivota z pozycji right do zmiennej r
    int j = left; // Inicjalizacja wskaźnika l na lewym krańcu tablicy
    for (int i = left; i < right; i++){ // Pętla iterująca przez elementy od lewego do prawego indeksu (exclusive)
        if(arr[i] <= p){ // Jeśli wartość na pozycji i jest mniejsza lub równa wartości pivota
            std::swap(arr[j], arr[i]); // Zamień wartości na pozycjach j i i za pomocą funkcji swap
            j++; // przejście na kolejny element
        }
    }
    std::swap(arr[j], arr[right]); // Zamień wartości na pozycjach l i right za pomocą funkcji swap
    return j; //zwróc indeks pivota do podziału tablicy
}

long long QuickSort::sort_left(int *arr, int size) {
    auto start = std::chrono::high_resolution_clock::now(); // Początek pomiaru czasu
    if (size <= 1) return 0; // Jeśli rozmiar tablicy jest mniejszy lub równy 1, zakończ sortowanie

    std::stack<std::pair<int, int>> stack; // Utwórz stos par (indeks początku, indeks końca) dla podziałów tablicy
    stack.push({0, size - 1}); // Umieść początkowy zakres do posortowania na stosie

    while (!stack.empty()) { // Dopóki stos nie jest pusty
        auto range = stack.top(); // Pobierz zakres do posortowania z wierzchołka stosu
        stack.pop(); // Usuń zakres z wierzchołka stosu

        int left = range.first; // Ustaw indeks początkowy zakresu
        int right = range.second; // Ustaw indeks końcowy zakresu

        if (left < right) { // Jeśli zakres zawiera więcej niż jeden element
            int pivot_index = partition(arr, left, right, left); // podział z lewym pivotem
            stack.push({left, pivot_index - 1}); // Umieść lewą część tablicy na stosie do dalszego sortowania
            stack.push({pivot_index + 1, right}); // Umieść prawą część tablicy na stosie do dalszego sortowania
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

        int left = range.first;
        int right = range.second;

        if (left < right) {
            int pivot_index = partition(arr, left, right, right); // pivot prawy
            stack.push({left, pivot_index - 1});
            stack.push({pivot_index + 1, right});
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

        int left = range.first;
        int right = range.second;

        if (left < right) {
            int pivot_index = partition(arr, left, right, ((right-left)/2 + left)); // pivot środkowy
            stack.push({left, pivot_index - 1});
            stack.push({pivot_index + 1, right});
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

        int left = range.first;
        int right = range.second;

        std::uniform_int_distribution<int> distribution(left, right);
        int random_pivot = distribution(rng); // losowanie pivot

        if (left < right) {
            int pivot_index = partition(arr, left, right, random_pivot);
            stack.push({left, pivot_index - 1});
            stack.push({pivot_index + 1, right});
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

/* WERSJA DZIAŁAJĄCA NA MNIEJSZYCH TABLICACH
int QuickSort::partition(int *arr, int left, int right, int pivot) {
    int l = left; // ustawiamy wskaźnik l na lewą stronę zakresu
    int r = right; // ustawiamy wskaźnik r na prawą stronę zakresu
    int p = pivot;
    while (1) {
        while (arr[l] < p) ++l; // Przesuń wskaźnik l w prawo, dopóki wartość na pozycji l jest mniejsza od pivota
        while (arr[r] > p) --r; // w lewo
        if (l < r) { // Jeśli wskaźnik l jest mniejszy od wskaźnika r
            std::swap(arr[l], arr[r]); // Zamień elementy na pozycjach l i r miejscami
            ++l;
            --r;
        }
        else { // Jeśli wskaźnik l nie jest już mniejszy od wskaźnika r
            if (r == right) r--; // Jeśli wskaźnik r znajduje się na końcu tablicy, przesuń go o jedno miejsce w lewo
            return r; // Zwróć pozycję wskaźnika r jako punkt podziału
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