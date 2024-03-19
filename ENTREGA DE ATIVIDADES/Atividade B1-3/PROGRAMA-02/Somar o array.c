/*--------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados            */
/*                         Prof Veríssimo                                   */
/*             Objetivo: Exercícios envolvendo ponteiros e arrays           */
/*             Paradigama: Programação Modular                              */
/*                                                                          */
/*                                                          Data:18/03/2024 */
/*--------------------------------------------------------------------------*/
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
    int Notas[tamanho];

    printf("Insira 5 Nota:\n");

    for (int i = 0; i < tamanho; ++i) {
        printf("Nota %d: ", i + 1);
        scanf("%d", &Notas[i]);
    }

    printf("\nAs Notas inseridos são: \n");
    for (int i = 0; i < tamanho; ++i) {
        printf("%d ", Notas[i]);
    }

    printf("\nA soma das notas inseridas é: %d\n",               
        somarArray(Notas, tamanho));

    return 0;
}
