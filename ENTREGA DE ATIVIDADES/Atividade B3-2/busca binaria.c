#include <stdio.h>

int busca_binaria(int A[], int n, int x) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (A[meio] == x) {
            return meio;
        } else if (A[meio] < x) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}

int main() {
    int A[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(A) / sizeof(A[0]);

    int resultado = busca_binaria(A, n, x);
    if (resultado != -1) {
        printf("Elemento encontrado no índice %d\n", resultado);
    } else {
        printf("Elemento não encontrado\n");
    }

    return 0;
}
