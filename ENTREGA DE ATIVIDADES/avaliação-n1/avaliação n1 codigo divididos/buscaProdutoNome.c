#include <stdio.h>
#include "estoque.h"

void buscarProdutoCodigo(Produto estoque[], int quantidadeProdutos, int codigo) {
    int encontrado = 0;
    for (int i = 0; i < quantidadeProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            printf("Produto encontrado:\n");
            printf("Nome: %s\n", estoque[i].nome);
            printf("Código: %d\n", estoque[i].codigo);
            printf("Preço: %.2f\n", estoque[i].preco);
            printf("Quantidade: %d\n", estoque[i].quantidade);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto não encontrado!\n");
    }
}
