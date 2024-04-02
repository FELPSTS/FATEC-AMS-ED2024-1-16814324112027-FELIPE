#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    char nome[50];
    int codigo;
    float preco;
    int quantidade;
} Produto;

void cadastrarProduto(Produto estoque[], int *quantidadeProdutos) {
    if (*quantidadeProdutos < MAX_PRODUTOS) {
        Produto novoProduto;
        printf("Digite o nome do produto: ");
        scanf(" %[^\n]s", novoProduto.nome);
        printf("Digite o código do produto: ");
        scanf("%d", &novoProduto.codigo);
        printf("Digite o preço do produto: ");
        scanf("%f", &novoProduto.preco);
        printf("Digite a quantidade do produto: ");
        scanf("%d", &novoProduto.quantidade);

        estoque[*quantidadeProdutos] = novoProduto;
        (*quantidadeProdutos)++;

        printf("Produto cadastrado com sucesso!\n");
    } else {
        printf("Estoque cheio! Não é possível adicionar mais produtos.\n");
    }
}

void exibirEstoque(Produto estoque[], int quantidadeProdutos) {
    if (quantidadeProdutos == 0) {
        printf("Estoque vazio!\n");
    } else {
        printf("Produtos no estoque:\n");
        for (int i = 0; i < quantidadeProdutos; i++) {
            printf("Nome: %s\n", estoque[i].nome);
            printf("Código: %d\n", estoque[i].codigo);
            printf("Preço: %.2f\n", estoque[i].preco);
            printf("Quantidade: %d\n", estoque[i].quantidade);
            printf("------------------------\n");
        }
    }
}

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

int main() {
    Produto estoque[MAX_PRODUTOS];
    int quantidadeProdutos = 0;
    int opcao;

    do {
        printf("\n");
        printf("1. Cadastrar produto\n");
        printf("2. Exibir estoque\n");
        printf("3. Buscar produto pelo nome\n");
        printf("4. Buscar produto pelo código\n");
        printf("5. Dar baixa no estoque\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(estoque, &quantidadeProdutos);
                break;
            case 2:
                exibirEstoque(estoque, quantidadeProdutos);
                break;
            case 3: {
                char nome[50];
                printf("Digite o nome do produto: ");
                scanf(" %[^\n]s", nome);
                buscarProdutoNome(estoque, quantidadeProdutos, nome);
                break;
            }
            case 4: {
                int codigo;
                printf("Digite o código do produto: ");
                scanf("%d", &codigo);
                buscarProdutoCodigo(estoque, quantidadeProdutos, codigo);
                break;
            }
            case 5: {
                int codigo, quantidade;
                printf("Digite o código do produto: ");
                scanf("%d", &codigo);
                printf("Digite a quantidade para dar baixa: ");
                scanf("%d", &quantidade);
                darBaixaEstoque(estoque, quantidadeProdutos, codigo, quantidade);
                break;
            }
            case 6:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}
