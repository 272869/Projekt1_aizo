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
        std::cout<< "2. Double" << std::endl;
        std::cout<< "0. Wyjdz" << std::endl;
        int mode;
        std::cin >> mode;
        switch (mode) {
            case 1:
                int_type_mode();
                break;
            case 2:
                double_type_mode();
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
                    switch (sortOption) {
                        case 1:
                            QuickSort::sort_left(intArray.getArray(), 0,intArray.getSize() - 1);
                            if(intArray.isSorted()){
                                std::cout << "Tablica posortowana:" << std::endl;
                                intArray.printArray();
                            }else{
                                std::cout << "NIE posortowana" << std::endl;
                            }
                            break;
                        case 2:
                            QuickSort::sort_right(intArray.getArray(), 0,intArray.getSize() - 1);
                            if(intArray.isSorted()){
                                std::cout << "Tablica posortowana:" << std::endl;
                                intArray.printArray();
                            }else{
                                std::cout << "NIE posortowana" << std::endl;
                            }
                            break;
                        case 3:
                            QuickSort::sort_center(intArray.getArray(), 0,intArray.getSize() - 1);
                            if(intArray.isSorted()){
                                std::cout << "Tablica posortowana:" << std::endl;
                                intArray.printArray();
                            }else{
                                std::cout << "NIE posortowana" << std::endl;
                            }
                            break;
                        case 4:
                            QuickSort::sort_rand(intArray.getArray(), 0,intArray.getSize() - 1);
                            if(intArray.isSorted()){
                                std::cout << "Tablica posortowana:" << std::endl;
                                intArray.printArray();
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
                    InsertionSort<int>::insertion_sort(intArray);
                    if(intArray.isSorted()){
                        std::cout << "Tablica posortowana:" << std::endl;
                        intArray.printArray();
                    }else{
                        std::cout << "NIE posortowana" << std::endl;
                    }
                } else {
                    std::cout << "Brak tablicy" << std::endl;
                }
                break;
            case 6:
                if (intArray.getSize() > 0) {
                    HeapSort::heap_sort(intArray.getArray(),intArray.getSize());
                    if(intArray.isSorted()){
                        std::cout << "Tablica posortowana:" << std::endl;
                        intArray.printArray();
                    }else{
                        std::cout << "NIE posortowana" << std::endl;
                        intArray.printArray();
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
                    switch (sortOption) {
                        case 1:
                            ShellSort::shell_sort_1(intArray.getArray(), intArray.getSize());
                            if (intArray.isSorted()) {
                                std::cout << "Tablica posortowana:" << std::endl;
                                intArray.printArray();
                            } else {
                                std::cout << "NIE posortowana" << std::endl;
                            }
                            break;
                        case 2:
                            ShellSort::shell_sort_2(intArray.getArray(), intArray.getSize());
                            if (intArray.isSorted()) {
                                std::cout << "Tablica posortowana:" << std::endl;
                                intArray.printArray();
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

void Menu::double_type_mode() {
    Arrays<double> doubleArray;
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
                doubleArray.setArray(doubleArray.generateRandomArray(size), size);
                std::cout << "wygenerowana" << std::endl;
                break;
            case 2:
                std::cout << "Podaj nazwe pliku" << std::endl;
                std::cin >> fileName;
                if(!fileName.empty()){
                    double * arr = doubleArray.readArray(fileName);
                    doubleArray.setArray(arr,doubleArray.getSize());
                }else {
                    std::cout << "Brak nazwy pliku" << std::endl;
                }
                break;
            case 3:
                doubleArray.printArray(); // Wyswietlamy tablicę
                break;
            case 4:
                if (doubleArray.getSize() > 0) {
                    InsertionSort<double>::insertion_sort(doubleArray);
                    if(doubleArray.isSorted()){
                        std::cout << "Tablica posortowana:" << std::endl;
                        doubleArray.printArray();
                    }else{
                        std::cout << "NIE posortowana" << std::endl;
                    }
                } else {
                    std::cout << "Brak tablicy" << std::endl;
                }
                break;
            case 0:
                return;
            default:
                //jakiś kod
                break;
        }
    }
}