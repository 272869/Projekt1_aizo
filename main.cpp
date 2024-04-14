#include "Menu/Menu.h"
#include "Sorting_algorithms/QuickSort.h"
#include "Sorting_algorithms/InsertionSort.h"
#include "Sorting_algorithms/ShellSort.h"
#include "Sorting_algorithms/HeapSort.h"

int main() {
    Menu menu;
    Arrays<int> arrays;
    /*long long time;
    long long avg_time;
    int loop = 100;
    for(int j=0 ,size=10000; j<7;j++,size = size*2){
        std::cout << "size: " << size << "   " ;
        long long times =0;
        for(int i = 0; i<loop ;i++){
            arrays.setArray(arrays.generateArray(size,5), size);
            time = HeapSort::heap_sort(arrays.getArray(),arrays.getSize());
            //std::cout<< std::endl << "time " <<i<<": "<< time << std::endl ;
            times+=time;
        }
        //std::cout << "all: " << times << "  ";
        avg_time = times / loop;
        std::cout << "Czas: " << static_cast<double>(avg_time) / 1000 << " ms\n";
    }*/
    return 0;
}