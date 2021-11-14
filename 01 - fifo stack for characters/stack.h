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
} stack_storage;

int push_to_stack_storage(stack_storage *stack, char character);
int main(void);