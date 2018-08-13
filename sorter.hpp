#ifndef SORTER_HPP
#define SORTER_HPP

#include <iostream>
#include <math.h>

class Sorter{

  public:

    Sorter();
    ~Sorter();

    void printList(int input[], int inputSize);
    void selectionSort(int input[], int inputSize);
    void insertionSort(int input[], int inputSize);
    void mergeSort(int input[], int start, int end);
    void quickSort(int input[], int inputSize);

};

#endif
