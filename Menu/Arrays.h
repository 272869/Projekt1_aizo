#ifndef ARRAYS_H
#define ARRAYS_H
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <chrono>

template<typename T>
class Arrays {
    T min_val;
    T max_val;
    T* array;
    int size= 0;
public:
    Arrays() {
        min_val = 0;
        max_val = 100;
        if(std::is_same<T, int>::value){
            min_val = 0;
            max_val = 100;
        }else if(std::is_same<T, float>::value){
            min_val = 0;
            max_val = 100000;
        }
    }
    Arrays(T* array, int size){
        this->array = array;
        this->size = size;
    };
    T* generateRandomArray(int size){
        std::mt19937 generator;
        generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> distribution(min_val, max_val);

        T* arr = new T[size];
        for (int i = 0; i < size; ++i) {
            int random = distribution(generator);
            if(std::is_same<T, float>::value){
                float val = static_cast<float>(random) / 1000;
                arr[i] = val;
            } else{
                arr[i] = random;
            }
        }
        return arr;
    };

    void partialSort(T *arr, int size, int percent) {
        int partialSize = (size * percent) / 100;
        std::sort(arr, arr + partialSize + 1); // Sortujemy tylko pierwszą trzecią tablicy
    }
    T* generateArray(int size, int option){
        T* arr = generateRandomArray(size);
        if(option == 2){
            std::sort(arr,arr+size);
        }else if(option==3){
            std::sort(arr, arr+size);
            reverseArray(static_cast<T *>(arr), size);
        }else if(option == 4){
            partialSort(arr,size,33);
        }else if(option == 5){
            partialSort(arr,size,66);
        }
        return arr;
    };
    void reverseArray(T *arr, int size) {
        for (int i = 0; i < size / 2; ++i) {
            std::swap(arr[i], arr[size - i - 1]);
        }
    }

    // Funkcja do wyświetlania tablicy
    void printArray() {
        for (int i = 0; i < this->size; i++)
            std::cout << array[i] << " ";
        std::cout << std::endl;
    };

    bool isSorted(){
        for (int i = 0; i < this->size - 1; i++){
            if (array[i] > array[i+1]){
                return false;
            }
        }
        return true;
    }

    // Funkcja do kopiowania tablicy
    T* copyArray(const T* arr, int size) {
        T* copiedArray = new T[size];
        std::copy(arr, arr + size, copiedArray); //iterator początkowt,iterator końcowy
        // (wskazujący na element za ostatnim elem w tab),iterator początkowy nowej tab
        return copiedArray;
    }
    T* copyArray(const Arrays<T> &array){
        return copyArray(array.getArray(), array.getSize());
    }

    int getSize() const {
        return this->size;
    };

    void setArray(T* newArray, int size){
        this->size = size;
        array = copyArray(newArray, size);
    }

    T *getArray() const {
        return array;
    }

    T convertStringTo(const std::string& str) { //konwersja stringa z pliku na typ T
        if (std::is_same<T, int>::value) { // jeśli T jest intem to konwertuj stringi na inty
            return std::stoi(str);
        } else if (std::is_same<T, double>::value) {
            return std::stod(str);
        }
    }

    T* readArray(const std::string& fileName){
        std::ifstream inputFile(fileName);
        std::string line;
        std::getline(inputFile, line); //odczytujemy pierwszą linię która jest rozmiarem
        size = std::stoi(line); //konwertuje ją na int
        std::cout <<"size: " << size << std::endl;
        T* array = new T[size];

        int i = 0;
        while (std::getline(inputFile, line) && i < size) {
            T value = convertStringTo(line); //konwertuje każdą linię na typ T
            array[i] = value;
            i++;
        }
        return array;
    }

};
#endif // ARRAYS_H
