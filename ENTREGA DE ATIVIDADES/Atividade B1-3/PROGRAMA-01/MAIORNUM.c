/*--------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados            */
/*                         Prof Veríssimo                                   */
/*             Objetivo: Exercícios envolvendo ponteiros e arrays           */
/*             Paradigama: Programação Modular                              */
/*                                                                          */
/*                                                          Data:18/03/2024 */
/*--------------------------------------------------------------------------*/
#include <stdio.h>

int MaiorNota(int *array, int tamanho) {
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
    int Notas[tamanho];

    printf("Insira 5 notas:\n");

    for (int i = 0; i < tamanho; ++i) {
        printf("notas %d: ", i + 1);
        scanf("%d", &Notas[i]);
    }

    int maior = MaiorNota(Notas, tamanho);

    printf("\nA maior Notas é: %d\n", maior);

    return 0;
}
