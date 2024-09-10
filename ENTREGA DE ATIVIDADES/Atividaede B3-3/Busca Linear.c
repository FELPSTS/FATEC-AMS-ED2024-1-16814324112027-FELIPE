#include <stdio.h>

/*----------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados              */
/*   Prof: Veríssimo                                                          */
/*   Objetivo: Exercícios analise de desempenho                                */
/*   autor:Felipe Torquato Santos de Souza                                    */                                        
/*                                                          Data:10/09/2024   */
/*----------------------------------------------------------------------------*/

int busca_linear(int A[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (A[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int n = 5;
    int x = 3;
    int result = busca_linear(A, n, x);
    printf("Resultado: %d\n", result);
    return 0;
}
