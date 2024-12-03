#include <stdlib.h>

typedef struct
{
    void **collection;
    int size;
    size_t capacity;
    size_t element_size;
} Stack;

Stack *create_stack(size_t capacity, size_t element_size);

void stack_push(Stack *stack, void *element);

void stack_pop(Stack *stack, void *out);

void stack_free(Stack *stack);

void print_stack(Stack *stack);