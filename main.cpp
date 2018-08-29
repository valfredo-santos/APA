/*  Aluno: Valfredo Santos Júnior
    Matrícula: 115040304  */

#include "sorter.hpp"

int sortingAlgorithm = 0; //Algoritmo de Ordenação Escolhido
int inputOption = 0; //Exemplo escolhido

//Exemplos
int input1[5] = {0, 1, 2, 3, 4}, inputSize1 = 5;
int input2[5] = {4, 3, 2, 1, 0}, inputSize2 = 5;
int input3[20] = {95, 31, 47, 97, 62, 74, 27, 66, 67, 81, 50, 44, 63, 8, 21, 88, 91, 41, 4, 43}, inputSize3 = 20;

Sorter sorter;

int main(){

  //Solicita o algoritmo de ordenação que será utilizado
  while(true){
    std::cout << "\nEscolha o algoritmo de ordenacao desejado\n(1)Selection Sort\n(2)Insertion Sort\n(3)Merge Sort"
                 << "\n(4)Quick Sort\n(5)Counting Sort\n(6)Heap Sort\n>: ";
    std::cin >> sortingAlgorithm;

    if(sortingAlgorithm >= 1 && sortingAlgorithm <= 6)
      break;

    std::cout << "Opcao invalida, tente novamente!\n";
  }

  //Solicita a lista de entrada que será utilizada
  while(true){
    std::cout << "\nEscolha uma das listas de entrada";
    std::cout << "\n(1) Lista: ";
    sorter.PrintList(input1, inputSize1);
    std::cout << "\n(2) Lista: ";
    sorter.PrintList(input2, inputSize2);
    std::cout << "\n(3) Lista: ";
    sorter.PrintList(input3, inputSize3);
    std::cout << "\n>: ";
    std::cin >> inputOption;

    if(inputOption >= 1 && inputOption <= 3)
      break;

    std::cout << "Opcao invalida, tente novamente!\n";

  }

  //Imprime a lista antes da ordenação
  std::cout << "\nLista Original: ";
  switch (inputOption) {
    case 1:
      sorter.PrintList(input1, inputSize1);
      break;
    case 2:
      sorter.PrintList(input2, inputSize2);
      break;
    case 3:
      sorter.PrintList(input3, inputSize3);
      break;
  }

  /*Realiza a ordenação levando em consideração a lista de entrada e o algoritmo
    escolhidos pelo usuario.*/
  switch(sortingAlgorithm){
    case 1:
      if(inputOption == 1)
        sorter.SelectionSort(input1, inputSize1);
      else if(inputOption == 2)
        sorter.SelectionSort(input2, inputSize2);
      else
        sorter.SelectionSort(input3, inputSize3);
      break;
    case 2:
      if(inputOption == 1)
        sorter.InsertionSort(input1, inputSize1);
      else if(inputOption == 2)
        sorter.InsertionSort(input2, inputSize2);
      else
        sorter.InsertionSort(input3, inputSize3);
      break;
    case 3:
      if(inputOption == 1)
        sorter.MergeSort(input1, 0, inputSize1 - 1);
      else if(inputOption == 2)
        sorter.MergeSort(input2, 0, inputSize2 - 1);
      else
        sorter.MergeSort(input3, 0, inputSize3 - 1);
      break;
    case 4:
      if(inputOption == 1)
        sorter.QuickSort(input1, 0, inputSize1 - 1);
      else if(inputOption == 2)
        sorter.QuickSort(input2, 0, inputSize2 - 1);
      else
        sorter.QuickSort(input3, 0, inputSize3 - 1);
      break;
    case 6:
      if(inputOption == 1)
        sorter.HeapSort(input1, inputSize1);
      else if(inputOption == 2)
        sorter.HeapSort(input2, inputSize2);
      else
        sorter.HeapSort(input3, inputSize3);
      break;
    default:
      break;
  }

  //Imprime a lista após a ordenação
  std::cout << "\nLista Ordenada: ";
  switch (inputOption) {
    case 1:
      sorter.PrintList(input1, inputSize1);
      break;
    case 2:
      sorter.PrintList(input2, inputSize2);
      break;
    case 3:
      sorter.PrintList(input3, inputSize3);
      break;
  }

  std::cout << "\n\nPrograma Finalizado!\n";

  return 0;
}
