#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*----------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados              */
/*   Prof: Veríssimo                                                          */
/*   Objetivo: Exercícios array x lista ligada                                */
/*   autor:Felipe Torquato Santos de Souza                                    */
/*   paradigma da programação:lista                                           */
/*                                                          Data:13/03/2024   */
/*----------------------------------------------------------------------------*/

struct Node {
    int data;
    struct Node *next;
};

void insert_in_linked_list(struct Node **head, int value) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node *slow = *head;
    struct Node *fast = *head;
    struct Node *prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    new_node->next = slow;
    if (prev != NULL) {
        prev->next = new_node;
    } else {
        *head = new_node;
    }
}

void print_list(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    struct Node *fourth = NULL;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 25;
    second->next = third;

    third->data = 40;
    third->next = fourth;

    fourth->data = 80;
    fourth->next = NULL;

    int value_to_insert = 30;

    clock_t start_time = clock();
    insert_in_linked_list(&head, value_to_insert);
    clock_t end_time = clock();

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("resultado da lista: ");
    print_list(head);
    printf("tempo resposta de inserção de lista: %f seconds\n", time_taken);

    return 0;
}
