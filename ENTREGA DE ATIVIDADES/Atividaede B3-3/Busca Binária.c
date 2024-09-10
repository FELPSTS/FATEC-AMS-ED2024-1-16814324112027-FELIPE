#include <stdio.h>

/*----------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados              */
/*   Prof: Veríssimo                                                          */
/*   Objetivo: Exercícios analise de desempenho                                */
/*   autor:Felipe Torquato Santos de Souza                                    */                                        
/*                                                          Data:10/09/2024   */
/*----------------------------------------------------------------------------*/

int busca_binaria(int A[], int n, int x) {
    int esq = 0;
    int dir = n - 1;
    while (esq <= dir) {
        int meio = (esq + dir) / 2;
        if (A[meio] == x) {
            return meio;
        }
        else if (A[meio] < x) {
            esq = meio + 1;
        } else {
            dir = meio - 1;
        }
    }
    return -1;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int n = 5;
    int x = 3;
    int result = busca_binaria(A, n, x);
    printf("Resultado: %d\n", result);
    return 0;
}
