/*  Aluno: Valfredo Santos Júnior
    Matrícula: 115040304  */

#include <iostream>

int sortingAlgorithm = 0;
int inputOption = 0;

//Exemplos
int input1[5] = {0, 1, 2, 3, 4};
int input2[5] = {4, 3, 2, 1, 0};
int input3[20] = {95, 31, 47, 97, 62, 74, 27, 66, 67, 81, 50, 44, 63, 8, 21, 88, 91, 41, 4, 43};

void printList(int input[], int inputSize){
  std::cout << "{ ";
  for(int i = 0; i < inputSize; i++)
    std::cout << input[i] << " ";
  std::cout << "}";
}

void selectionSort(int input[], int inputSize){
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

void insertionSort(int input[], int inputSize){
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


int main(){
  while(true){
    std::cout << "\nEscolha o algoritmo de ordenacao desejado\n(1)Selection Sort\n(2)Insertion Sort\n>: ";
    std::cin >> sortingAlgorithm;

    if(sortingAlgorithm == 1 || sortingAlgorithm == 2)
      break;

    std::cout << "Opcao invalida, tente novamente!\n";
  }

  while(true){
    std::cout << "\nEscolha uma das listas de entrada";
    std::cout << "\n(1) Lista: ";
    printList(input1, 5);
    std::cout << "\n(2) Lista: ";
    printList(input2, 5);
    std::cout << "\n(3) Lista: ";
    printList(input3, 20);
    std::cout << "\n>: ";
    std::cin >> inputOption;

    if(inputOption >= 1 && inputOption <= 3)
      break;

    std::cout << "Opcao invalida, tente novamente!\n";

  }

  switch(sortingAlgorithm){
    case 1:
      if(inputOption == 1)
        selectionSort(input1, 5);
      else if(inputOption == 2)
        selectionSort(input2, 5);
      else
        selectionSort(input3, 20);
      break;
    case 2:
      if(inputOption == 1)
        insertionSort(input1, 5);
      else if(inputOption == 2)
        insertionSort(input2, 5);
      else
        insertionSort(input3, 20);
      break;
    default:
      break;
  }

  std::cout << "\n\nPrograma Finalizado!\n";

  return 0;
}
