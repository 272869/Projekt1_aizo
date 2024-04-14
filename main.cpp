#include "Menu/Menu.h"
#include "Sorting_algorithms/QuickSort.h"
#include "Sorting_algorithms/InsertionSort.h"
#include "Sorting_algorithms/ShellSort.h"
#include "Sorting_algorithms/HeapSort.h"

int main() {
    //Menu menu;
    Arrays<float> arrays;
    long long time;
    long long avg_time;
    int loop = 10;
    std::cout << "insert los"<<std::endl ;
    for(int j=0 ,size=160000; j<3;j++,size = size*2){
        std::cout << "size: " << size << "   " ;
        long long times =0;
        for(int i = 0; i<loop ;i++){
            arrays.setArray(arrays.generateArray(size,4), size);
            time = InsertionSort<float>::insertion_sort(arrays);
            std::cout<< std::endl << "time " <<i<<": "<< time << std::endl ;
            times+=time;
        }
        std::cout << "all: " << times << "  ";
        avg_time = times / loop;
        std::cout << "Czas: " << static_cast<double>(avg_time) / 1000 << " ms\n";
    }

    return 0;
}