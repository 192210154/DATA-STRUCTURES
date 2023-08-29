#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    char data[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, char element) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = element;
}

// Function to pop an element from the stack
char pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

// Function to check if a given sequence of parentheses is a valid stack
bool isValidStack(char *sequence) {
    struct Stack stack;
    initialize(&stack);

    int length = strlen(sequence);
    for (int i = 0; i < length; i++) {
        if (sequence[i] == '(') {
            push(&stack, '(');
        } else if (sequence[i] == ')') {
            if (pop(&stack) != '(') {
                return false;
            }
        }
    }

    return stack.top == -1; // Stack should be empty if it's a valid sequence
}

int main() {
    char sequence[MAX_SIZE];
    printf("Enter a sequence of parentheses: ");
    scanf("%s", sequence);

    if (isValidStack(sequence)) {
        printf("Valid stack\n");
    } else {
        printf("Not a valid stack\n");
    }

    return 0;
}
