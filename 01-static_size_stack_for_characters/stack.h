/*
 * stack.h
 *
 *  Created on: Oct 14, 2021
 *      Author: oasdflkjo
 */

#define MAX_STACK_SIZE 200
typedef struct
{
    char array[MAX_STACK_SIZE];
    int location;
} array_stack;

int push_to_array_stack(array_stack *stack, char character);
int pop_from_array_stack(array_stack *stack);
int main(void);