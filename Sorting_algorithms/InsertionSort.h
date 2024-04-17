#ifndef AIZO_PROJEKT_1_INSERTIONSORT_H
#define AIZO_PROJEKT_1_INSERTIONSORT_H


template<typename T> // Szablon klasy, T oznacza typ danych
class InsertionSort{
public:
    static long long insertion_sort(const Arrays<T>& array){
        T* arr = array.getArray(); // Pobranie wskaźnika do tablicy z obiektu array
        int N  = array.getSize(); // Pobranie rozmiaru tablicy z obiektu array

        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 1; i < N; ++i) { // Pętla iterująca przez elementy tablicy, zaczynając od drugiego elementu
            T key = arr[i]; // Przypisanie wartości elementu na pozycji i do zmiennej key
            int j = i - 1; // Inicjalizacja zmiennej j na pozycji poprzedzającej i

            while (j >= 0 && arr[j] > key) { // Pętla while wykonuje się dopóki j >= 0 i wartość na pozycji j jest większa od key
                arr[j + 1] = arr[j]; // Przesunięcie elementu na pozycji j w prawo
                j = j - 1; // Przesunięcie wskaźnika j w lewo
            }
            arr[j + 1] = key; // Przypisanie wartości zmiennej key na pozycję j + 1
        }
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    };
};


#endif //AIZO_PROJEKT_1_INSERTIONSORT_H