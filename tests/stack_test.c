#include <stdio.h>
#include "stack.h"

int main()
{
    Stack *stack = create_stack(10, sizeof(char));
    if (stack == NULL)
    {
        printf("Failed to create stack.\n");
        return 1;
    }

    printf("Current Stack:\n");
    print_stack(stack);

    char e = 'y';
    stack_push(stack, &e);
    char c = 'h';
    stack_push(stack, &c);

    printf("New Stack:\n");
    print_stack(stack);

    char popped;
    stack_pop(stack, &popped);
    printf("Popped element: %c\n", popped);

    printf("After popping:\n");
    print_stack(stack);

    stack_free(stack);

    return 0;
}
