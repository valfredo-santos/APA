#include "sorter.hpp"

Sorter::Sorter(){;}
Sorter::~Sorter(){;}

void Sorter::printList(int input[], int inputSize){
  std::cout << "{ ";
  for(int i = 0; i < inputSize; i++)
    std::cout << input[i] << " ";
  std::cout << "}";
}

void Sorter::selectionSort(int input[], int inputSize){
  std::cout << "\nLista Original: ";
  printList(input, inputSize);

  for(int i = 0; i < inputSize - 1; i++){
    int min = i;
    for(int j = i + 1; j < inputSize; j++){
      if(input[j] < input[min])
        min = j;
    }
    if(min != i){
      int aux = input[i];
      input[i] = input[min];
      input[min] = aux;
    }
  }

  std::cout << "\nLista Ordenada: ";
  printList(input, inputSize);
}

void Sorter::insertionSort(int input[], int inputSize){
  std::cout << "\nLista Original: ";
  printList(input, inputSize);

  int aux, j;
  for(int i = 1; i < inputSize; i++){
    aux = input[i];
    j = i - 1;
    while(j >= 0 && input[j] > aux){
      input[j+1] = input[j];
      j--;
    }
    input[j+1] = aux;
  }

  std::cout << "\nLista Ordenada: ";
  printList(input, inputSize);
}

void Sorter::mergeSort(int input[], int inputSize){
  std::cout << "\nLista Original: ";
  printList(input, inputSize);

  std::cout << "\nLista Ordenada: ";
  printList(input, inputSize);
}

void Sorter::quickSort(int input[], int inputSize){
  std::cout << "\nLista Original: ";
  printList(input, inputSize);

  std::cout << "\nLista Ordenada: ";
  printList(input, inputSize);
}
