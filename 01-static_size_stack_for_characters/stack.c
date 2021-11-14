/*
 * stack.c
 *
 *  Created on: Oct 14, 2021
 *      Author: oasdflkjo
 * 
 * Implemntation of a fifo data structure to store characters
 */

#include <stdio.h>

#include "stack.h"

// TODO
// prolly could be done using with pointer that points to the current element
// null handle
// location can go negative
// location can grow bigger than the max stack size

int push_to_array_stack(array_stack *stack, char character)
{
    stack->array[stack->location] = character;
    stack->location++;
    return 0;
}

int pop_from_array_stack(array_stack *stack)
{
    stack->location--;
    return 0;
}

int print_current_stack(array_stack *stack)
{
    for (int i = 0; i < stack->location; i++)
    {
        printf("%c", stack->array[i]);
    }
    printf("\n");
    return 0;
}

int main(void)
{
    array_stack stack;
    stack.location = 0;
    push_to_array_stack(&stack, 'a');
    push_to_array_stack(&stack, 'b');
    push_to_array_stack(&stack, 'c');
    pop_from_array_stack(&stack);
    print_current_stack(&stack);

    return 0;
}
