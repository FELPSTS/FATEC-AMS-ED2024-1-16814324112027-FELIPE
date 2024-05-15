#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_CONSULTORIOS 5

/*--------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados            */
/*                         Prof Veríssimo                                   */
/*             Objetivo: Exercícios fila de HOSPITAL                        */
/*             autor:Felipe Torquato Santos de Souza                        */
/*             paradigma da programação:fila                                */
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

typedef struct {
    Paciente atendimentos[MAX_CONSULTORIOS];
    int consultorioAtual;
} HistoricoAtendimentos;

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

void atenderPaciente(Fila* filaNormal, Fila* filaPreferencial, Fila* filaUrgente, HistoricoAtendimentos* historico) {
    if (!filaVazia(filaUrgente)) {
        historico->atendimentos[historico->consultorioAtual] = removerPaciente(filaUrgente);
        historico->atendimentos[historico->consultorioAtual].horaAtendimento = time(NULL);
        printf("Atendendo paciente urgente: %s no consultório %d\n", historico->atendimentos[historico->consultorioAtual].nome, historico->consultorioAtual + 1);
        historico->consultorioAtual = (historico->consultorioAtual + 1) % MAX_CONSULTORIOS;
        return;
    }
    if (!filaVazia(filaPreferencial)) {
        historico->atendimentos[historico->consultorioAtual] = removerPaciente(filaPreferencial);
        historico->atendimentos[historico->consultorioAtual].horaAtendimento = time(NULL);
        printf("Atendendo paciente preferencial: %s no consultório %d\n", historico->atendimentos[historico->consultorioAtual].nome, historico->consultorioAtual + 1);
        historico->consultorioAtual = (historico->consultorioAtual + 1) % MAX_CONSULTORIOS;
        return;
    }
    if (!filaVazia(filaNormal)) {
        historico->atendimentos[historico->consultorioAtual] = removerPaciente(filaNormal);
        historico->atendimentos[historico->consultorioAtual].horaAtendimento = time(NULL);
        printf("Atendendo paciente normal: %s no consultório %d\n", historico->atendimentos[historico->consultorioAtual].nome, historico->consultorioAtual + 1);
        historico->consultorioAtual = (historico->consultorioAtual + 1) % MAX_CONSULTORIOS;
        return;
    }
    printf("Não há pacientes para atender.\n");
}

void mostrarHistoricoAtendimentos(HistoricoAtendimentos* historico) {
    printf("Histórico de atendimentos:\n");
    for (int i = 0; i < MAX_CONSULTORIOS; i++) {
        if (strlen(historico->atendimentos[i].nome) > 0) {
            printf("Consultório %d: %s, Motivo da consulta: %s\n", i + 1, historico->atendimentos[i].nome, historico->atendimentos[i].motivoConsulta);
        }
    }
}

int main() {
    Fila filaNormal, filaPreferencial, filaUrgente;
    inicializarFila(&filaNormal);
    inicializarFila(&filaPreferencial);
    inicializarFila(&filaUrgente);

    HistoricoAtendimentos historico;
    historico.consultorioAtual = 0;

    int opcao;
    do {
        printf("\nSelecione uma opção:\n");
        printf("1. Adicionar paciente à fila normal\n");
        printf("2. Adicionar paciente à fila preferencial\n");
        printf("3. Adicionar paciente à fila de atendimento urgente\n");
        printf("4. Atender paciente\n");
        printf("5. Visualizar filas\n");
        printf("6. Mostrar histórico de atendimentos\n");
        printf("7. Sair\n");
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
                atenderPaciente(&filaNormal, &filaPreferencial, &filaUrgente, &historico);
                break;
            }
            case 5: {
                visualizarFila(&filaNormal, "normal");
                visualizarFila(&filaPreferencial, "preferencial");
                visualizarFila(&filaUrgente, "de atendimento urgente");
                break;
            }
            case 6: {
                mostrarHistoricoAtendimentos(&historico);
                break;
            }
            case 7:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Por favor, selecione uma opção válida.\n");
                // Limpar o buffer de entrada
                while (getchar() != '\n');
        }
    } while (opcao != 7);

    return 0;
}
