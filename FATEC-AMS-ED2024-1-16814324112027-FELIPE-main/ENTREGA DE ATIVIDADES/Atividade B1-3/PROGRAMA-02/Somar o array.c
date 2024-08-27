/*--------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados            */
/*                         Prof Veríssimo                                   */
/*             Objetivo: Exercícios envolvendo ponteiros e arrays           */
/*             Paradigama: Programação Modular                              */
/*                                                                          */
/*                                                          Data:18/03/2024 */
/*--------------------------------------------------------------------------*/
#include <stdio.h>

float somarArray(float *array, int tamanho) {
    float soma = 0;
    for (int i = 0; i < tamanho; ++i) {
        soma += array[i];
    }
    return soma;
}

int main() {
    int tamanho = 5;
    float notas[tamanho];

    printf("Insira 5 notas:\n");

    for (int i = 0; i < tamanho; ++i) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    printf("\nAs notas inseridas são: \n");
    for (int i = 0; i < tamanho; ++i) {
        printf("%.2f ", notas[i]);
    }

    printf("\nA soma das notas inseridas é: %.2f\n",               
        somarArray(notas, tamanho));

    return 0;
}
