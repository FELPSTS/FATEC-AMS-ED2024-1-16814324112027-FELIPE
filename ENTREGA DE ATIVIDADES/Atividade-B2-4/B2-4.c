#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
/*--------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados            */
/*                         Prof Veríssimo                                   */
/*             Objetivo: Exercícios fila de HOSPITAL                        */
/*             dono:Felipe Torquato santos de souza                         */
/*                                                                          */
/*                                                          Data:13/03/2024 */
/*--------------------------------------------------------------------------*/
typedef struct {
    char nome[50];
    int idade;
    char motivoConsulta[100];
} Paciente;

typedef struct Node {
    Paciente paciente;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int count;
} Fila;

void initializeQueue(Fila* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;
}

int isEmpty(Fila* queue) {
    return (queue->count == 0);
}

void enqueue(Fila* queue, Paciente paciente) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->paciente = paciente;
    newNode->next = NULL;
    
    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->count++;
}

Paciente dequeue(Fila* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia!\n");
        exit(EXIT_FAILURE);
    }

    Paciente paciente = queue->front->paciente;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    queue->count--;
    return paciente;
}

void displayQueue(Fila* queue) {
    Node* current = queue->front;
    while (current != NULL) {
        printf("Nome: %s, Idade: %d, Motivo da Consulta: %s\n", current->paciente.nome, current->paciente.idade, current->paciente.motivoConsulta);
        current = current->next;
    }
}

int main() {
    Fila filaNormal, filaPrioritaria, filaUrgente;
    initializeQueue(&filaNormal);
    initializeQueue(&filaPrioritaria);
    initializeQueue(&filaUrgente);

    Paciente p1 = {"Joao", 25, "Dor de cabeça"};
    Paciente p2 = {"Maria", 35, "Febre"};
    Paciente p3 = {"Jose", 70, "Pressão alta"};
    enqueue(&filaNormal, p1);
    enqueue(&filaNormal, p2);
    enqueue(&filaPrioritaria, p3);

    printf("Fila Normal:\n");
    displayQueue(&filaNormal);
    printf("\nFila Prioritaria:\n");
    displayQueue(&filaPrioritaria);

    // Atender pacientes
    printf("\nPaciente atendido: %s\n", dequeue(&filaNormal).nome);

    return 0;
}
