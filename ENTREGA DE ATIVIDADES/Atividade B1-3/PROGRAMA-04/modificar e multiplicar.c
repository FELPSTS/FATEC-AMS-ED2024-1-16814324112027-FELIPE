#include <stdio.h>

int multiplicarArray(int *array, int tamanho,int *multiplicador) {
    for (int i = 0; i < tamanho; ++i) {
       array[i] *= *multiplicador;
    }
}
int main() {
    int tamanho = 5;
    int Numeros[tamanho];
    int multiplicador;

    printf("Insira 5 números:\n");

    for (int i = 0; i < tamanho; ++i) {
        printf("Número %d: ", i + 1);
        scanf("%d", &Numeros[i]);
    }

    printf("\nOs números inseridos são: \n");
    for (int i = 0; i < tamanho; ++i) {
        printf("%d ", Numeros[i]);
    }

    printf("\nInsira um valor para multiplicar-los\n");
    scanf("%d", &multiplicador);

   multiplicarArray(Numeros, tamanho, &multiplicador);
  
      printf("\nO array após a multiplicação:\n");
      for (int i = 0; i < tamanho; ++i) {
          printf("%d ", Numeros[i]);
      }
      
    return 0;
}