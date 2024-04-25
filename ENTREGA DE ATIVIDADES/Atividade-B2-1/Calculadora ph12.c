#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

/*--------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados            */
/*                         Prof Veríssimo                                   */
/*             Objetivo: Exercícios calculadora ph12c utilizando pila                    */
/*                       autor:FELIPE TORQUATO*/
/*                                                          Data:23/04/2024 */
/*--------------------------------------------------------------------------*/

typedef struct {
    double data[MAX_SIZE];
    int top;
} Stack;

typedef struct {
    Stack x_stack;
    Stack y_stack;
    Stack z_stack;
    Stack t_stack;
} Memory;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

int isFull(Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

void push(Stack *s, double item) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->data[++s->top] = item;
}

double pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top--];
}

void storeMemory(Stack *dest, Stack *source) {
    while (!isEmpty(source)) {
        push(dest, pop(source));
    }
}

void recallMemory(Stack *source, Stack *dest) {
    storeMemory(dest, source);
}

double calculate(double operand1, double operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
            return operand1 / operand2;
        default:
            printf("Invalid operator\n");
            exit(EXIT_FAILURE);
    }
}

int main() {
    Memory memory;
    init(&memory.x_stack);
    init(&memory.y_stack);
    init(&memory.z_stack);
    init(&memory.t_stack);

    char rpn[MAX_SIZE];
    printf("Enter the RPN expression: ");
    fgets(rpn, MAX_SIZE, stdin);

    int i = 0;
    while (rpn[i] != '\0') {
        if (rpn[i] >= '0' && rpn[i] <= '9') {
            push(&memory.x_stack, atof(&rpn[i]));
            while (rpn[i] >= '0' && rpn[i] <= '9')
                i++;
        } else if (rpn[i] == '+' || rpn[i] == '-' || rpn[i] == '*' || rpn[i] == '/') {
            double operand2 = pop(&memory.x_stack);
            double operand1 = pop(&memory.x_stack);
            double result = calculate(operand1, operand2, rpn[i]);
            push(&memory.x_stack, result);
            i++;
        } else if (rpn[i] == ' ' || rpn[i] == '\n' || rpn[i] == '\r') {
            i++;
        } else {
            printf("Invalid character in RPN expression\n");
            exit(EXIT_FAILURE);
        }
    }

    double final_result = pop(&memory.x_stack);
    printf("Result: %.2lf\n", final_result);

    return 0;
}
