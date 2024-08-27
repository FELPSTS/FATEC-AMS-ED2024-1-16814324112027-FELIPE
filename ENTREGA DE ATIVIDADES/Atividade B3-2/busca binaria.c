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

