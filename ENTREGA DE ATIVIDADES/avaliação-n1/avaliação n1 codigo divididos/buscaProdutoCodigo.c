#include <stdio.h>
#include "estoque.h"

void darBaixaEstoque(Produto estoque[], int quantidadeProdutos, int codigo, int quantidade) {
    int encontrado = 0;
    for (int i = 0; i < quantidadeProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            if (estoque[i].quantidade >= quantidade) {
                estoque[i].quantidade -= quantidade;
                printf("Baixa no estoque realizada com sucesso!\n");
            } else {
                printf("Quantidade insuficiente em estoque!\n");
            }
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto não encontrado!\n");
    }
}
