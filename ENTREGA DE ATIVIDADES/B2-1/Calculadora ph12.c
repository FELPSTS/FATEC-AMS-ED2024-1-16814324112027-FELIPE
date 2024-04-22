#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_SIZE 50

typedef struct {
    double data[STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isFull(Stack *stack) {
    return stack->top == STACK_SIZE - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, double value) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = value;
    } else {
        printf("Erro: Pilha cheia.\n");
        exit(EXIT_FAILURE);
    }
}

double pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    } else {
        printf("Erro: Pilha vazia.\n");
        exit(EXIT_FAILURE);
    }
}

double evaluateRPN(char *expression, Stack *stack) {
    char *token = strtok(expression, " ");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(stack, atof(token));
        } else {
            double operand2 = pop(stack);
            double operand1 = pop(stack);

            switch (token[0]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        push(stack, operand1 / operand2);
                    } else {
                        printf("Erro: Divisão por zero.\n");
                        exit(EXIT_FAILURE);
                    }
                    break;
                default:
                    printf("Erro: Operador inválido.\n");
                    exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, " ");
    }

    return pop(stack);
}

int main() {
    char expression[100];
    printf("Digite a expressão em RPN: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = '\0';

    Stack stack;
    initStack(&stack);

    double result = evaluateRPN(expression, &stack);
    printf("Resultado: %.2lf\n", result);
    printf("Expressão algébrica equivalente: ");

    char *token = strtok(expression, " ");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            printf("%s ", token);
        } else {
            printf("(");
            char operator = token[0];
            double operand2 = pop(&stack);
            double operand1 = pop(&stack);
            printf("%.2lf %c %.2lf) ", operand1, operator, operand2);
            push(&stack, operand1);
            push(&stack, operand2);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}
