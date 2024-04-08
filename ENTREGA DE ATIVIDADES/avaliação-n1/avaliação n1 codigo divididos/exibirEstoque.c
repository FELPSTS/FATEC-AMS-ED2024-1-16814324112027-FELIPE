#include <stdio.h>
#include <string.h>
#include "estoque.h"

void buscarProdutoNome(Produto estoque[], int quantidadeProdutos, char *nome) {
    int encontrado = 0;
    for (int i = 0; i < quantidadeProdutos; i++) {
        if (strcmp(estoque[i].nome, nome) == 0) {
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
