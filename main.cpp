/*  Aluno: Valfredo Santos Júnior
    Matrícula: 115040304  */

#include "sorter.hpp"

int sortingAlgorithm = 0;
int inputOption = 0;

//Exemplos
int input1[5] = {0, 1, 2, 3, 4};
int input2[5] = {4, 3, 2, 1, 0};
int input3[20] = {95, 31, 47, 97, 62, 74, 27, 66, 67, 81, 50, 44, 63, 8, 21, 88, 91, 41, 4, 43};

Sorter sorter;

int main(){

  while(true){
    std::cout << "\nEscolha o algoritmo de ordenacao desejado\n(1)Selection Sort\n(2)Insertion Sort\n(3)Merge Sort\n(4)Quick Sort\n>: ";
    std::cin >> sortingAlgorithm;

    if(sortingAlgorithm >= 1 && sortingAlgorithm <= 4)
      break;

    std::cout << "Opcao invalida, tente novamente!\n";
  }

  while(true){
    std::cout << "\nEscolha uma das listas de entrada";
    std::cout << "\n(1) Lista: ";
    sorter.printList(input1, 5);
    std::cout << "\n(2) Lista: ";
    sorter.printList(input2, 5);
    std::cout << "\n(3) Lista: ";
    sorter.printList(input3, 20);
    std::cout << "\n>: ";
    std::cin >> inputOption;

    if(inputOption >= 1 && inputOption <= 3)
      break;

    std::cout << "Opcao invalida, tente novamente!\n";

  }

  switch(sortingAlgorithm){
    case 1:
      if(inputOption == 1)
        sorter.selectionSort(input1, 5);
      else if(inputOption == 2)
        sorter.selectionSort(input2, 5);
      else
        sorter.selectionSort(input3, 20);
      break;
    case 2:
      if(inputOption == 1)
        sorter.insertionSort(input1, 5);
      else if(inputOption == 2)
        sorter.insertionSort(input2, 5);
      else
        sorter.insertionSort(input3, 20);
      break;
    case 3:
      if(inputOption == 1)
        sorter.mergeSort(input1, 5);
      else if(inputOption == 2)
        sorter.mergeSort(input2, 5);
      else
        sorter.mergeSort(input3, 20);
      break;
    case 4:
      if(inputOption == 1)
        sorter.quickSort(input1, 5);
      else if(inputOption == 2)
        sorter.quickSort(input2, 5);
      else
        sorter.quickSort(input3, 20);
      break;
    default:
      break;
  }

  std::cout << "\n\nPrograma Finalizado!\n";

  return 0;
}
