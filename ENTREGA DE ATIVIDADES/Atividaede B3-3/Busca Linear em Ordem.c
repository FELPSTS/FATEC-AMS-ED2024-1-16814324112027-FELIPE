#include <stdio.h>

int busca_linear_em_ordem(int A[], int n, int x) {
    for (int i = 0; i < n && A[i] >= x; i++) {
        if (A[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int A[] = {9, 7, 5, 3, 1};
    int n = 5;
    int x = 3;
    int result = busca_linear_em_ordem(A, n, x);
    printf("Resultado: %d\n", result);
    return 0;
}
