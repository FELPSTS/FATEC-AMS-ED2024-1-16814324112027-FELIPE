#include <stdio.h>

int MaiorNumero(int *array, int tamanho) {
    int maior = *array; 
    for (int i = 1; i < tamanho; ++i) {
        if (*(array + i) > maior) {
            maior = *(array + i);
        }
    }
    return maior;
}

int main() {
    int tamanho = 5;
    int Numeros[tamanho];

    printf("Insira 5 números:\n");

    for (int i = 0; i < tamanho; ++i) {
        printf("Número %d: ", i + 1);
        scanf("%d", &Numeros[i]);
    }
  
    int maior = MaiorNumero(Numeros, tamanho);

    printf("\nO maior número é: %d\n", maior);

    return 0;
}
