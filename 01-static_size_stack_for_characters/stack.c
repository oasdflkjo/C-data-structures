/*
 * stack.c
 *
 *  Created on: Oct 14, 2021
 *      Author: oasdflkjo
 * 
 * Implementation of a static stack to store characters.
 * Using int returns on functions 0 meaning succesfull operation
 * and 1 meaning error.
 * 
 * Creating stack does not initialise the array with anything so 
 * it will contain random chars.
 */

#include <stdio.h>

#include "stack.h"

int push_to_array_stack(array_stack *stack, char character)
{
    // TODO so apparently struct is never null so how should i do error checks?
    // how to deal with bad inputs? do i even need to know that the array exists?
    if (stack->location < MAX_STACK_SIZE)
    {
        stack->array[stack->location] = character;
        stack->location++;
        return 0;
    }
    return 1;
}

int pop_from_array_stack(array_stack *stack)
{
    if (stack->location != 0 && stack != NULL)
    {
        stack->location--;
        return 0;
    }
    return 1;
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

// test function for the "class"
int main(void)
{
    array_stack stack;
    stack.location = 0;
    printf("%d\n", push_to_array_stack(&stack, 'a'));
    printf("%d\n", push_to_array_stack(&stack, 'b'));
    printf("%d\n", push_to_array_stack(&stack, 'v'));
    printf("%d\n", pop_from_array_stack(&stack));
    printf("%d\n", print_current_stack(&stack));
    return 0;
}
