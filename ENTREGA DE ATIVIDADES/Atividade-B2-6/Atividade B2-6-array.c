#include <stdio.h>
#include <time.h>

void insertIntoArray(int arr[], int size, int value, int position) {
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
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
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size + 1];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    int valueToInsert;
    printf("Enter the value to insert: ");
    scanf("%d", &valueToInsert);

    int positionToInsert = size / 2;

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    insertIntoArray(array, size, valueToInsert, positionToInsert);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Array after insertion: ");
    for (int i = 0; i < size + 1; i++) {
        printf("%d ", array[i]);
    }
    printf("\nTime taken: %f seconds\n", cpu_time_used);

    return 0;
}
