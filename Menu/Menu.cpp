#include <iostream>
#include "Menu.h"
#include "../Sorting_algorithms/QuickSort.h"
#include "../Sorting_algorithms/InsertionSort.h"
#include "../Sorting_algorithms/HeapSort.h"
#include "../Sorting_algorithms/ShellSort.h"

Menu::Menu() {
    while (true){
        std::cout<< "Wybierz typ danych do posortowania" << std::endl;
        std::cout<< "1. Int" << std::endl;
        std::cout<< "2. Float" << std::endl;
        std::cout<< "0. Wyjdz" << std::endl;
        int mode;
        std::cin >> mode;
        switch (mode) {
            case 1:
                int_type_mode();
                break;
            case 2:
                float_type_mode();
                break;
            case 0:
                return;
        }
    }
}

void Menu::int_type_mode() {
    Arrays<int> intArray;
    while (true) {
        std::cout << "Operacje dla tablicy typu int" << std::endl;
        std::cout << "1. Generuj losowa tablice" << std::endl;
        std::cout << "2. Wczytaj tablice z pliku" << std::endl;
        std::cout << "3. Wyswietl tablice" << std::endl;
        std::cout << "4. Sortowanie Quicksort" << std::endl;
        std::cout << "5. Sortowanie Insertion Sort" << std::endl;
        std::cout << "6. Sortowanie Heap Sort" << std::endl;
        std::cout << "7. Sortowanie Shell Sort" << std::endl;
        std::cout << "0. Powrot" << std::endl;
        int option;
        std::cin >> option;
        std::string fileName;
        switch (option) {
            case 1:
                std::cout << "Podaj rozmiar tablicy" << std::endl;
                int size;
                std::cin >> size;
                intArray.setArray(intArray.generateRandomArray(size), size);
                break;
            case 2:
                std::cout << "Podaj nazwe pliku" << std::endl;
                std::cin >> fileName;
                if(!fileName.empty()){
                    int* arr = intArray.readArray(fileName); //odczytuję tablicę
                    intArray.setArray(arr,intArray.getSize());
                }else {
                    std::cout << "Brak nazwy pliku" << std::endl;
                }
                break;
            case 3:
                intArray.printArray(); // Wyswietlamy tablicę
                break;
            case 4:
                if (intArray.getSize() > 0) {
                    std::cout << "Wybierz sposob sortowania:" << std::endl;
                    std::cout << "1. Sortowanie od lewej" << std::endl;
                    std::cout << "2. Sortowanie od prawej" << std::endl;
                    std::cout << "3. Sortowanie z pivotem w środku" << std::endl;
                    std::cout << "4. Sortowanie z losowym pivotem" << std::endl;
                    std::cout << "0. Powrot" << std::endl;
                    int sortOption;
                    std::cin >> sortOption;
                    int *workArr = intArray.copyArray(intArray);
                    Arrays workArray(workArr, intArray.getSize());
                    long long time;
                    switch (sortOption) {
                        case 1:
                            time = QuickSort::sort_left(workArray.getArray(), 0,workArray.getSize() - 1);
                            std::cout << "Czas: " << static_cast<double>(time) / 1000 << " ms\n";
                            //QuickSort::sort_left(intArray.getArray(), 0,intArray.getSize() - 1);
                            if(workArray.isSorted()){
                                std::cout << "Tablica posortowana:" << std::endl;
                                workArray.printArray();
                            }else{
                                std::cout << "NIE posortowana" << std::endl;
                            }
                            break;
                        case 2:
                            time = QuickSort::sort_right(workArray.getArray(), 0,workArray.getSize() - 1);
                            std::cout << "Czas: " << static_cast<double>(time) / 1000 << " ms\n";
                            if(workArray.isSorted()){
                                std::cout << "Tablica posortowana:" << std::endl;
                                workArray.printArray();
                            }else{
                                std::cout << "NIE posortowana" << std::endl;
                            }
                            break;
                        case 3:
                            time = QuickSort::sort_center(workArray.getArray(), 0,workArray.getSize() - 1);
                            std::cout << "Czas: " << static_cast<double>(time) / 1000 << " ms\n";
                            if(workArray.isSorted()){
                                std::cout << "Tablica posortowana:" << std::endl;
                                workArray.printArray();
                            }else{
                                std::cout << "NIE posortowana" << std::endl;
                            }
                            break;
                        case 4:
                            time = QuickSort::sort_rand(workArray.getArray(), 0,workArray.getSize() - 1);
                            std::cout << "Czas: " << static_cast<double>(time) / 1000 << " ms\n";
                            if(workArray.isSorted()){
                                std::cout << "Tablica posortowana:" << std::endl;
                                workArray.printArray();
                            }else{
                                std::cout << "NIE posortowana" << std::endl;
                            }
                            break;
                        case 0:
                            return;
                    }
                } else {
                    std::cout << "Brak tablicy" << std::endl;
                }
                break;
            case 5:
                if (intArray.getSize() > 0) {
                    int *workArr = intArray.copyArray(intArray);
                    Arrays workArray(workArr, intArray.getSize());
                    InsertionSort<int>::insertion_sort(workArray);
                    if(workArray.isSorted()){
                        std::cout << "Tablica posortowana:" << std::endl;
                        workArray.printArray();
                    }else{
                        std::cout << "NIE posortowana" << std::endl;
                    }
                } else {
                    std::cout << "Brak tablicy" << std::endl;
                }
                break;
            case 6:
                if (intArray.getSize() > 0) {
                    int *workArr = intArray.copyArray(intArray);
                    Arrays workArray(workArr, intArray.getSize());
                    HeapSort::heap_sort(workArray.getArray(),workArray.getSize());
                    if(workArray.isSorted()){
                        std::cout << "Tablica posortowana:" << std::endl;
                        workArray.printArray();
                    }else{
                        std::cout << "NIE posortowana" << std::endl;
                    }
                } else {
                    std::cout << "Brak tablicy" << std::endl;
                }
                break;
            case 7:
                if (intArray.getSize() > 0) {
                    std::cout << "Wybierz sposob sortowania:" << std::endl;
                    std::cout << "1. Shell" << std::endl;
                    std::cout << "2. Papiernow, Stasiewicz" << std::endl;
                    std::cout << "0. Powrot" << std::endl;
                    int sortOption;
                    std::cin >> sortOption;
                    int *workArr = intArray.copyArray(intArray);
                    Arrays workArray(workArr, intArray.getSize());
                    switch (sortOption) {
                        case 1:
                            ShellSort::shell_sort_1(workArray.getArray(), workArray.getSize());
                            if (workArray.isSorted()) {
                                std::cout << "Tablica posortowana:" << std::endl;
                                workArray.printArray();
                            } else {
                                std::cout << "NIE posortowana" << std::endl;
                            }
                            break;
                        case 2:
                            ShellSort::shell_sort_2(workArray.getArray(), workArray.getSize());
                            if (workArray.isSorted()) {
                                std::cout << "Tablica posortowana:" << std::endl;
                                workArray.printArray();
                            } else {
                                std::cout << "NIE posortowana" << std::endl;
                            }
                            break;
                        case 0:
                            return;
                    }
                } else {
                    std::cout << "Brak tablicy" << std::endl;
                }
                break;
            case 0:
                return;
        }
    }
}

void Menu::float_type_mode() {
    Arrays<float> floatArray;
    while (true) {
        std::cout << "Operacje dla tablicy typu int" << std::endl;
        std::cout << "1. Generuj losowa tablice" << std::endl;
        std::cout << "2. Wczytaj tablice z pliku" << std::endl;
        std::cout << "3. Wyswietl tablice" << std::endl;
        std::cout << "4. Sortowanie Insertion Sort" << std::endl;
        std::cout << "0. Powrot" << std::endl;
        int option;
        std::cin >> option;
        std::string fileName;
        switch (option) {
            case 1:
                std::cout << "Podaj rozmiar tablicy" << std::endl;
                int size;
                std::cin >> size;
                floatArray.setArray(floatArray.generateRandomArray(size), size);
                std::cout << "wygenerowana" << std::endl;
                break;
            case 2:
                std::cout << "Podaj nazwe pliku" << std::endl;
                std::cin >> fileName;
                if(!fileName.empty()){
                    float * arr = floatArray.readArray(fileName);
                    floatArray.setArray(arr,floatArray.getSize());
                }else {
                    std::cout << "Brak nazwy pliku" << std::endl;
                }
                break;
            case 3:
                floatArray.printArray(); // Wyswietlamy tablicę
                break;
            case 4:
                if (floatArray.getSize() > 0) {
                    float *workArr = floatArray.copyArray(floatArray);
                    Arrays workArray(workArr, floatArray.getSize());
                    InsertionSort<float>::insertion_sort(workArray);
                    if(workArray.isSorted()){
                        std::cout << "Tablica posortowana:" << std::endl;
                        workArray.printArray();
                    }else{
                        std::cout << "NIE posortowana" << std::endl;
                    }
                } else {
                    std::cout << "Brak tablicy" << std::endl;
                }
                break;
            case 0:
                return;
        }
    }
}