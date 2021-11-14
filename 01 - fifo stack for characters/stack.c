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

int push_to_stack_storage(stack_storage *stack, char character)
{
    stack->array[stack->location] = character;
    stack->location++;
    return 0;
}

int pop_from_stack_storage(stack_storage *stack)
{
    stack->location--;
    return 0;
}

int print_current_stack(stack_storage *stack)
{
    for (int i = 0; i < stack->location; i++)
    {
        printf("%c", stack->array[i]);
    }
    return 0;
}

int main(void)
{
    stack_storage stack;
    stack.location = 0;
    push_to_stack_storage(&stack, 'a');
    push_to_stack_storage(&stack, 'b');
    push_to_stack_storage(&stack, 'c');
    pop_from_stack_storage(&stack);
    print_current_stack(&stack);

    return 0;
}
