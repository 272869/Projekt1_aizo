#include "Menu/Menu.h"
#include "Sorting_algorithms/QuickSort.h"
#include "Sorting_algorithms/InsertionSort.h"

int main() {
    //Menu menu;
    Arrays<float> arrays;
    long long time;
    long long avg_time;
    for(int j=0 ,size=320000; j<2;j++,size = size*2){
        std::cout << "size: " << size << "   ";
        long long times =0;
        for(int i = 0; i<3 ;i++){
            arrays.setArray(arrays.generateArray(size,5), size);
            time = InsertionSort<float>::insertion_sort(arrays);
            std::cout << "time " <<i<<": "<< time << std::endl ;
            times+=time;
        }
        std::cout << "all: " << times << "  ";
        avg_time = times / 3;
        std::cout << "Czas: " << static_cast<double>(avg_time) / 1000 << " ms\n";
    }
    return 0;
}