#include <stdio.h>

int somarArray(int *array, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; ++i) {
        soma += array[i];
    }
    return soma;
}
int main() {
    int tamanho = 5;
    int Numeros[tamanho];

    printf("Insira 5 números:\n");

    for (int i = 0; i < tamanho; ++i) {
        printf("Número %d: ", i + 1);
        scanf("%d", &Numeros[i]);
    }

    printf("\nOs números inseridos são: \n");
    for (int i = 0; i < tamanho; ++i) {
        printf("%d ", Numeros[i]);
    }

    printf("\nA soma dos números inseridos é: %d\n",                 somarArray(Numeros, tamanho));

    return 0;
}