#include <stdio.h>

  // Função para mudar a posição de dois elementos
  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

  void heapify(int arr[], int n, int i) {
    // Ache o maior entre a raiz, o filho esquerdo e o direito
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && arr[esquerda] > arr[maior])
      maior = esquerda;

    if (direita < n && arr[direita] > arr[maior])
      maior = direita;

    // Troque e continue empilhando se a raiz não for maior
    if (maior != i) {
      swap(&arr[i], &arr[maior]);
      heapify(arr, n, maior);
    }
  }

  // Função main para fazer Heap sort
  void heapSort(int arr[], int n) {
    // Construir pilha máxima
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);

      // Agrupar (heapify) elemento raiz para obter o elemento mais alto na raiz novamente
      heapify(arr, i, 0);
    }
  }

  // Imprimir um array
  void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }

  // Driver code
  int main() {
    int arr[] = {1, 12, 9, 5, 6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("O array ordenado é \n");
    printArray(arr, n);
  }