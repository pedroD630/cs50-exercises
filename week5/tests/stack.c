#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Tamanho máximo da pilha

// Estrutura da pilha
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Função para inicializar a pilha
void initialize(Stack *stack) {
    stack->top = -1;
}

// Função para verificar se a pilha está vazia
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Função para verificar se a pilha está cheia
bool isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Função para adicionar um elemento à pilha (push)
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push.\n");
    } else {
        stack->top++;
        stack->items[stack->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

// Função para remover um elemento da pilha (pop)
void pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop.\n");
    } else {
        printf("Popped %d from the stack.\n", stack->items[stack->top]);
        stack->top--;
    }
}

int main() {
    Stack stack;
    initialize(&stack);

    int size;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid stack size. Exiting program.\n");
        return 1;
    }

    while (1) {
        char choice;
        printf("\nEnter P for push, O for pop, or N to stop: ");
        scanf(" %c", &choice);

        if (choice == 'P' || choice == 'p') {
            if (stack.top < size - 1) {
                int value;
                printf("Enter the value to push onto the stack: ");
                scanf("%d", &value);
                push(&stack, value);
            } else {
                printf("Stack is full. Cannot push.\n");
            }
        } else if (choice == 'O' || choice == 'o') {
            if (!isEmpty(&stack)) {
                pop(&stack);
            } else {
                printf("Stack is empty. Cannot pop.\n");
            }
        } else if (choice == 'N' || choice == 'n') {
            break;
        } else {
            printf("Invalid choice. Please enter P, O, or N.\n");
        }
    }

    printf("\nFinal stack contents:\n");
    while (!isEmpty(&stack)) {
        printf("%d ", stack.items[stack.top]);
        pop(&stack);
    }

    return 0;
}
