/*--------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados            */
/*                         Prof Veríssimo                                   */
/*             Objetivo: Exercícios envolvendo ponteiros e arrays           */
/*             Paradigama: Programação Modular                              */
/*                                                                          */
/*                                                          Data:18/03/2024 */
/*--------------------------------------------------------------------------*/
#include <stdio.h>

void multiplicarArray(float *array, int tamanho, int multiplicador) {
    for (int i = 0; i < tamanho; ++i) {
        array[i] *= multiplicador;
    }
}

int main() {
    int tamanho = 5;
    float notas[tamanho];
    int multiplicador;

    printf("Insira 5 notas:\n");

    for (int i = 0; i < tamanho; ++i) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    printf("\nAs notas inseridas são: \n");
    for (int i = 0; i < tamanho; ++i) {
        printf("%.2f ", notas[i]);
    }

    printf("\nInsira um valor inteiro para multiplicá-las: ");
    scanf("%d", &multiplicador);

    multiplicarArray(notas, tamanho, multiplicador);

    printf("\nO array após a multiplicação:\n");
    for (int i = 0; i < tamanho; ++i) {
        printf("%.2f ", notas[i]);
    }

    return 0;
}
