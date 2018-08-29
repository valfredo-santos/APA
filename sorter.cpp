#include "sorter.hpp"

Sorter::Sorter(){;}
Sorter::~Sorter(){;}

//Imprime a lista
void Sorter::PrintList(int input[], int inputSize){
  std::cout << "{ ";
  for(int i = 0; i < inputSize; i++)
    std::cout << input[i] << " ";
  std::cout << "}";
}

/*Selection Sort
  Complexidade - Melhor: n*n Média: n*n Pior: n*n */
void Sorter::SelectionSort(int input[], int inputSize){
  for(int i = 0; i < inputSize - 1; i++){
    int min = i;
    for(int j = i + 1; j < inputSize; j++){
      if(input[j] < input[min])
        min = j;
    }
    if(min != i){
      std::swap(input[i], input[min]);
    }
  }
}

/*Insertion Sort
  Complexidade - Melhor: n Média: n*n Pior: n*n */
void Sorter::InsertionSort(int input[], int inputSize){
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
}

void Merge(int input[], int start, int mid, int end){
  int a = start;
  int b = mid + 1;
  int k = 0;
  int aux[end - start + 1];

  for(int i = start; i <= end; i++){
    if(a > mid)
      aux[k++] = input[b++];
    else if(b > end)
      aux[k++] = input[a++];
    else if(input[a] < input[b])
      aux[k++] = input[a++];
    else
      aux[k++] = input[b++];
  }

  for(int j = 0; j < k; j++){
    input[start++] = aux[j];
  }
}

/*Merge Sort
  Complexidade - Melhor: n*Log(n) Média: n*Log(n) Pior: n*Log(n) */
void Sorter::MergeSort(int input[], int start, int end){
  if (start < end){
    int mid = (start + end)/2;
    MergeSort(input, start, mid);
    MergeSort(input, mid+1, end);
    Merge(input, start, mid, end);
  }
}

int Partition(int input[], int start, int end){
  int i = start - 1;
  int pivo = input[end];

  for(int j = start; j <= end - 1; j++){
    if(input[j] <= pivo){
      i++;
      std::swap(input[i], input[j]);
    }
  }

  std::swap(input[end], input[i+1]);
  return i+1;
}

/*Quick Sort
  Complexidade - Melhor: n*Log(n) Média: n*Log(n) Pior: n*n */
void Sorter::QuickSort(int input[], int start, int end){
  if (start < end){
    int pivo = Partition(input, start, end);
    QuickSort(input, start, pivo - 1);
    QuickSort(input, pivo + 1, end);
  }
}

int Pai(int i){
  return (i - 1) / 2;
}

int FilhoEsquerdo(int i){
  return (2 * i) + 1;
}

int FilhoDireito(int i){
  return (2 * i) + 2;
}

void MaxHeapify(int input[], int i, int tamanho_heap){
  int L = FilhoEsquerdo(i);
  int R = FilhoDireito(i);
  int maior = i;

  if (L < tamanho_heap && input[L] > input[maior])
    maior = L;
  if (R < tamanho_heap && input[R] > input[maior])
    maior = R;
  if (maior != i){
    std::swap(input[i], input[maior]);
    MaxHeapify(input, maior, tamanho_heap);
  }
}

void BuildMaxHeap(int input[], int inputSize){
  for(int i = inputSize / 2 - 1; i >= 0; i--)
    MaxHeapify(input, i, inputSize);
}

/*Heap Sort
  Complexidade - Melhor: n*Log(n) Média: n*Log(n) Pior: n*Log(n) */
void Sorter::HeapSort(int input[], int inputSize){
  BuildMaxHeap(input, inputSize);

  for (int i = inputSize - 1; i >= 0; i--){
    std::swap(input[0], input[i]);
    MaxHeapify(input, 0, i);
  }
}
