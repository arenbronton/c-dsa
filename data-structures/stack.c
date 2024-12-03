#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

Stack *create_stack(size_t capacity, size_t element_size)
{
    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL)
    {
        free(stack);
        printf("Stack memory could not be allocated\n");
        return NULL;
    }
    stack->collection = malloc(capacity * sizeof(void *));
    if (stack->collection == NULL)
    {
        free(stack);
        printf("Stack collection memory could not be allocated\n");
        return NULL;
    }
    stack->size = 0;
    stack->capacity = capacity;
    stack->element_size = element_size;

    return stack;
}

void stack_push(Stack *stack, void *element) {
    if (stack->size >= stack->capacity) {
        printf("Failed to push item to stack: Stack Overflow");
        return;
    }
    stack->size++;
    stack->collection[stack->size] = malloc(stack->element_size);
    memcpy(stack->collection[stack->size], element, stack->element_size);
}

void stack_pop(Stack *stack, void *out) {
    if (stack->size == 0) {
        printf("Failed to pop stack: stack is empty");
        return;
    }
    memcpy(out, stack->collection[stack->size], stack->element_size);
    free(stack->collection[stack->size]);
    stack->size--;
}

void stack_free(Stack *stack) {
    for (size_t i = 0; i < stack->size; i++) {
        free(stack->collection[i]);
    }
    free(stack->collection);
    free(stack);
}

void print_stack(Stack *stack) {
    if (stack == NULL || stack->collection == NULL) {
        printf("Stack is empty or uninitialized.\n");
        return;
    }

    for (size_t i = 0; i < stack->size; i++) {
        char str = *(char*) stack->collection[i];
        if (str) {
            printf("%c\t", str);
        }
        else {
            printf("(null)\t");
        } // Handle NULL ptrs
    }
    printf("\n");
}