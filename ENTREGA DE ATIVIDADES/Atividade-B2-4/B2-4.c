#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/*--------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados            */
/*                         Prof Veríssimo                                   */
/*             Objetivo: Exercícios fila de HOSPITAL                        */
/*             autor:Felipe Torquato Santos de Souza                         */
/*                                                                          */
/*                                                          Data:13/03/2024 */
/*--------------------------------------------------------------------------*/

typedef struct {
    char nome[50];
    int idade;
    char motivoConsulta[100];
    time_t horaChegada;
    time_t horaAtendimento;
} Paciente;

typedef struct No {
    Paciente paciente;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

void inicializarFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int filaVazia(Fila* fila) {
    return (fila->inicio == NULL);
}

void adicionarPaciente(Fila* fila, Paciente paciente) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro: falha ao alocar memória para o novo paciente.\n");
        return;
    }
    novoNo->paciente = paciente;
    novoNo->proximo = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novoNo;
    } else {
        fila->fim->proximo = novoNo;
    }
    fila->fim = novoNo;
}

Paciente removerPaciente(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Erro: a fila está vazia.\n");
        Paciente pacienteVazio;
        strcpy(pacienteVazio.nome, "");
        pacienteVazio.idade = -1;
        strcpy(pacienteVazio.motivoConsulta, "");
        return pacienteVazio;
    }
    No* noRemovido = fila->inicio;
    Paciente paciente = noRemovido->paciente;
    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(noRemovido);
    return paciente;
}

void visualizarFila(Fila* fila, const char* tipoFila) {
    No* atual = fila->inicio;
    printf("Fila de pacientes %s:\n", tipoFila);
    while (atual != NULL) {
        printf("Nome: %s, Idade: %d, Motivo da consulta: %s\n",
               atual->paciente.nome, atual->paciente.idade, atual->paciente.motivoConsulta);
        atual = atual->proximo;
    }
}

int contemApenasLetras(char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}

void atenderPaciente(Fila* filaNormal, Fila* filaPreferencial, Fila* filaUrgente) {
    if (!filaVazia(filaUrgente)) {
        Paciente pacienteAtendido = removerPaciente(filaUrgente);
        pacienteAtendido.horaAtendimento = time(NULL);
        printf("Atendendo paciente urgente: %s\n", pacienteAtendido.nome);
        printf("Tempo de chegada: %ld, Tempo de atendimento: %ld\n", pacienteAtendido.horaChegada, pacienteAtendido.horaAtendimento);
        return;
    }
    if (!filaVazia(filaPreferencial)) {
        Paciente pacienteAtendido = removerPaciente(filaPreferencial);
        pacienteAtendido.horaAtendimento = time(NULL);
        printf("Atendendo paciente preferencial: %s\n", pacienteAtendido.nome);
        printf("Tempo de chegada: %ld, Tempo de atendimento: %ld\n", pacienteAtendido.horaChegada, pacienteAtendido.horaAtendimento);
        return;
    }
    if (!filaVazia(filaNormal)) {
        Paciente pacienteAtendido = removerPaciente(filaNormal);
        pacienteAtendido.horaAtendimento = time(NULL);
        printf("Atendendo paciente normal: %s\n", pacienteAtendido.nome);
        printf("Tempo de chegada: %ld, Tempo de atendimento: %ld\n", pacienteAtendido.horaChegada, pacienteAtendido.horaAtendimento);
        return;
    }
    printf("Não há pacientes para atender.\n");
}

int main() {
    Fila filaNormal, filaPreferencial, filaUrgente;
    inicializarFila(&filaNormal);
    inicializarFila(&filaPreferencial);
    inicializarFila(&filaUrgente);

    int opcao;
    do {
        printf("\nSelecione uma opção:\n");
        printf("1. Adicionar paciente à fila normal\n");
        printf("2. Adicionar paciente à fila preferencial\n");
        printf("3. Adicionar paciente à fila de atendimento urgente\n");
        printf("4. Atender paciente\n");
        printf("5. Visualizar filas\n");
        printf("6. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Paciente novoPaciente;
                printf("Digite o nome do paciente: ");
                scanf("%s", novoPaciente.nome);
                if (!contemApenasLetras(novoPaciente.nome)) {
                    printf("Erro: o nome do paciente não pode conter números.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Digite a idade do paciente: ");
                if (scanf("%d", &novoPaciente.idade) != 1 || novoPaciente.idade <= 0) {
                    printf("Erro: idade inválida. Digite um número inteiro maior que zero.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Digite o motivo da consulta: ");
                scanf("%s", novoPaciente.motivoConsulta);
                novoPaciente.horaChegada = time(NULL);
                adicionarPaciente(&filaNormal, novoPaciente);
                printf("Paciente adicionado com sucesso à fila normal.\n");
                break;
            }
            case 2: {
                Paciente novoPaciente;
                printf("Digite o nome do paciente: ");
                scanf("%s", novoPaciente.nome);
                if (!contemApenasLetras(novoPaciente.nome)) {
                    printf("Erro: o nome do paciente não pode conter números.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Digite a idade do paciente: ");
                if (scanf("%d", &novoPaciente.idade) != 1 || novoPaciente.idade <= 0) {
                    printf("Erro: idade inválida. Digite um número inteiro maior que zero.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Digite o motivo da consulta: ");
                scanf("%s", novoPaciente.motivoConsulta);
                novoPaciente.horaChegada = time(NULL);
                adicionarPaciente(&filaPreferencial, novoPaciente);
                printf("Paciente adicionado com sucesso à fila preferencial.\n");
                break;
            }
            case 3: {
                Paciente novoPaciente;
                printf("Digite o nome do paciente: ");
                scanf("%s", novoPaciente.nome);
                if (!contemApenasLetras(novoPaciente.nome)) {
                    printf("Erro: o nome do paciente não pode conter números.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Digite a idade do paciente: ");
                if (scanf("%d", &novoPaciente.idade) != 1 || novoPaciente.idade <= 0) {
                    printf("Erro: idade inválida. Digite um número inteiro maior que zero.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Digite o motivo da consulta: ");
                scanf("%s", novoPaciente.motivoConsulta);
                novoPaciente.horaChegada = time(NULL);
                adicionarPaciente(&filaUrgente, novoPaciente);
                printf("Paciente adicionado com sucesso à fila de atendimento urgente.\n");
                break;
            }
            case 4: {
                atenderPaciente(&filaNormal, &filaPreferencial, &filaUrgente);
                break;
            }
            case 5: {
                visualizarFila(&filaNormal, "normal");
                visualizarFila(&filaPreferencial, "preferencial");
                visualizarFila(&filaUrgente, "de atendimento urgente");
                break;
            }
            case 6:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Por favor, selecione uma opção válida.\n");
               
                while (getchar() != '\n');
        }
    } while (opcao != 6);

    return 0;
}
