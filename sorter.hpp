#ifndef SORTER_HPP
#define SORTER_HPP

#include <iostream> //std::cout std::cin
#include <utility> //std::swap()

class Sorter{

  public:

    Sorter();
    ~Sorter();

    void PrintList(int input[], int inputSize);
    void SelectionSort(int input[], int inputSize);
    void InsertionSort(int input[], int inputSize);
    void MergeSort(int input[], int start, int end);
    void QuickSort(int input[], int start, int end);
    void HeapSort(int input[], int inputSize);

};

#endif
