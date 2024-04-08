#ifndef ESTOQUE_H
#define ESTOQUE_H

#define MAX_PRODUTOS 100

typedef struct {
    char nome[50];
    int codigo;
    float preco;
    int quantidade;
} Produto;

void cadastrarProduto(Produto estoque[], int *quantidadeProdutos);
void exibirEstoque(Produto estoque[], int quantidadeProdutos);
void buscarProdutoNome(Produto estoque[], int quantidadeProdutos, char *nome);
void buscarProdutoCodigo(Produto estoque[], int quantidadeProdutos, int codigo);
void darBaixaEstoque(Produto estoque[], int quantidadeProdutos, int codigo, int quantidade);

#endif /* ESTOQUE_H */
