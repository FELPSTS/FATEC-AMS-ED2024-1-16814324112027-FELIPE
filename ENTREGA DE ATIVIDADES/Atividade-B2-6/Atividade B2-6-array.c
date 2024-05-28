#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertInArray(int arr[], int *size, int value, int position) {
  for (int i = *size; i > position; i--) {
    arr[i] = arr[i - 1];
  }
  arr[position] = value;
  (*size)++;
}

/*----------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados              */
/*   Prof: Veríssimo                                                          */
/*   Objetivo: Exercícios array x lista ligada                                */
/*   autor:Felipe Torquato Santos de Souza                                    */
/*   paradigma da programação:lista                                           */
/*                                                          Data:13/03/2024   */
/*----------------------------------------------------------------------------*/

int main() {
  int arr[6] = {10, 25, 40, 80};
  int size = 4;
  int valueToInsert = 30;
  int position = size / 2;

  clock_t start, end;
  double cpu_time_used;

  start = clock();

  insertInArray(arr, &size, valueToInsert, position);

  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("Array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\nTempo de resposta: %f seconds\n", cpu_time_used);

  return 0;
}
