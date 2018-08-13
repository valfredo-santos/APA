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
    std::cout << "\nEscolha o algoritmo de ordenacao desejado\n(1)Selection Sort\n(2)Insertion Sort\n(3)Merge Sort\n(4)Quick Sort\n>: ";
    std::cin >> sortingAlgorithm;

    if(sortingAlgorithm >= 1 && sortingAlgorithm <= 4)
      break;

    std::cout << "Opcao invalida, tente novamente!\n";
  }

  //Solicita a lista de entrada que será utilizada
  while(true){
    std::cout << "\nEscolha uma das listas de entrada";
    std::cout << "\n(1) Lista: ";
    sorter.printList(input1, inputSize1);
    std::cout << "\n(2) Lista: ";
    sorter.printList(input2, inputSize2);
    std::cout << "\n(3) Lista: ";
    sorter.printList(input3, inputSize3);
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
      sorter.printList(input1, inputSize1);
      break;
    case 2:
      sorter.printList(input2, inputSize2);
      break;
    case 3:
      sorter.printList(input3, inputSize3);
      break;
  }

  /*Realiza a ordenação levando em consideração a lista de entrada e o algoritmo
    escolhidos pelo usuario.*/
  switch(sortingAlgorithm){
    case 1:
      if(inputOption == 1)
        sorter.selectionSort(input1, inputSize1);
      else if(inputOption == 2)
        sorter.selectionSort(input2, inputSize2);
      else
        sorter.selectionSort(input3, inputSize3);
      break;
    case 2:
      if(inputOption == 1)
        sorter.insertionSort(input1, inputSize1);
      else if(inputOption == 2)
        sorter.insertionSort(input2, inputSize2);
      else
        sorter.insertionSort(input3, inputSize3);
      break;
    case 3:
      if(inputOption == 1)
        sorter.mergeSort(input1, 0, inputSize1 - 1);
      else if(inputOption == 2)
        sorter.mergeSort(input2, 0, inputSize2 - 1);
      else
        sorter.mergeSort(input3, 0, inputSize3 - 1);
      break;
    case 4:
      if(inputOption == 1)
        sorter.quickSort(input1, 0, inputSize1 - 1);
      else if(inputOption == 2)
        sorter.quickSort(input2, 0, inputSize2 - 1);
      else
        sorter.quickSort(input3, 0, inputSize3 - 1);
      break;
    default:
      break;
  }

  //Imprime a lista após a ordenação
  std::cout << "\nLista Ordenada: ";
  switch (inputOption) {
    case 1:
      sorter.printList(input1, inputSize1);
      break;
    case 2:
      sorter.printList(input2, inputSize2);
      break;
    case 3:
      sorter.printList(input3, inputSize3);
      break;
  }

  std::cout << "\n\nPrograma Finalizado!\n";

  return 0;
}
