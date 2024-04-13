#ifndef AIZO_PROJEKT_1_INSERTIONSORT_H
#define AIZO_PROJEKT_1_INSERTIONSORT_H


template<typename T>
class InsertionSort{
public:
    static long long insertion_sort(const Arrays<T>& array){
        T* arr = array.getArray();
        int N  = array.getSize();

        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 1; i < N; ++i) {
            T key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
        auto end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    };
};


#endif //AIZO_PROJEKT_1_INSERTIONSORT_H