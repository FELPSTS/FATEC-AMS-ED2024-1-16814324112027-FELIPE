#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pacote {
    int id;
    char conteudo[100];
    char origem[50];
    char destino[50];
    int status; 
    struct Pacote *prox;
} Pacote;

Pacote* criarPacote(int id, char conteudo[], char origem[], char destino[], int status) {
    Pacote *novoPacote = (Pacote *)malloc(sizeof(Pacote));
    if (novoPacote == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        return NULL;
    }
    novoPacote->id = id;
    strcpy(novoPacote->conteudo, conteudo);
    strcpy(novoPacote->origem, origem);
    strcpy(novoPacote->destino, destino);
    novoPacote->status = status;
    novoPacote->prox = NULL;
    return novoPacote;
}

void buscarDetalhes(Pacote *lista, int id) {
    Pacote *pacote = lista;
    while (pacote != NULL && pacote->id != id) {
        pacote = pacote->prox;
    }
    if (pacote != NULL) {
        printf("Detalhes do pacote ID %d:\n", id);
        printf("Conteúdo: %s\n", pacote->conteudo);
        printf("Origem: %s\n", pacote->origem);
        printf("Destino: %s\n", pacote->destino);
        printf("Status: %d\n", pacote->status);
    } else {
        printf("Pacote ID %d não encontrado.\n", id);
    }
}

int main() {
    Pacote *lista = NULL;
    int id = 1; 
    char conteudo[100], origem[50], destino[50];
    int status;

    printf("Insira a ID do produto: ");
    scanf("%d", &id);
    printf("Insira os detalhes do pacote:\n");
    printf("Conteúdo: ");
    scanf(" %[^\n]", conteudo);
    printf("Nome cidade origem: ");
    scanf(" %[^\n]", origem);
    printf("Nome cidade destino: ");
    scanf(" %[^\n]", destino);
    printf("Status (1=Em processamento, 2=Em trânsito, 3=Em espera, 4=Entregue, 99=Extraviado): ");
    scanf("%d", &status);

    Pacote *novoPacote = criarPacote(id, conteudo, origem, destino, status);
    if (novoPacote != NULL) {
        novoPacote->prox = lista;
        lista = novoPacote;
        printf("Pacote incluído com sucesso!\n");
    }

    int idBusca;
    printf("Insira a ID do pacote a ser buscado: ");
    scanf("%d", &idBusca);
    buscarDetalhes(lista, idBusca);

    Pacote *temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }

    return 0;
}
