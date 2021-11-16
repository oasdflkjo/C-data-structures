/*
 *  ring_buffer.h
 *
 *  Created on: Oct 15, 2021
 *      Author: oasdflkjo
 * 
 * I just have to say that the assignment instructions are not very clear
 * and just by following them this becomes so messy.
 */
#include <stdio.h>
#include <stdint.h>

#define MAX_BUFFER_SIZE 200

typedef enum
{
    OK,
    EMPTY_BUFFER,
    POINTER_ERROR,
    BUFFER_FULL,
} error_type_t;

static unsigned char recive_buffer[MAX_BUFFER_SIZE];

typedef struct
{
    unsigned char *head;
    unsigned char *tail;
    unsigned char *buffer;
} buffer_type;

/* 
    initializes the buffer, by placing the pointers to beginning of buffer
    test with
    init_buffer(&b,buff);
    assert(b.head==buff);
    assert(b.tail==buff);
    assert(b.buffer==buff);
 */
void init_buffer(buffer_type *b, unsigned char *buffer);

/* 
    Empties the buffer by moving tail to head
    error_type  indicates error condition (use enum error_type)

    0 OK
    1 BUFFER_OVER_FLOW (Should not be possible)
    2 EMPTY_BUFFER
    3 POINTER_ERROR (Should not happen ever)
    4 BUFFER_FULL

    Only OK as a return value is used in this function
 */
error_type_t empty_buffer(buffer_type *b);
/*
    Checks the status of buffer and returns
    1. Amount of characters in buffer

    2. -1 in error condition (example pointer should not
         point outside of buffer ) *err holds type of error

 */
int get_buffer_state(buffer_type *b, error_type_t *err);

/*
    adding one character to buffer
    Do not try to make complete function at once, do circulation later
    Function will return 
    1. amount of character in buffer 
    2. -1 - in error condition,  err more info of error

 */
int add_char_to_buffer(buffer_type *b, unsigned char c, error_type_t *err);
/*
    
    get one character from buffer
    function will return 
    1. character read from buffer
    2. -1 - in error condition,  err more info of error

 */
char get_char_from_buffer(buffer_type *b, error_type_t *err);

/* 
    list characters from buffer, use clear reading printing (without moving pointers)
    Function will return 
        amount of character in buffer 
        -1 - in error condition,  err more info of error
 */
int print_buffer(buffer_type b, error_type_t *err);

/*
    add will return
    1. amount of characters added to buffer
    2. -1 if all characters cannot be added to buffer, in this case whole buffer will remain unchanged
*/
int add_string_to_buffer(buffer_type *b, unsigned char *s, error_type_t *err);

/* 
    get_string_from buffer will get numbers of characters 
    to be read from buffer by parameter will return
    1. amount of characters read from buffer
    2. 1 error condition, err will have reason
 */
int get_string_from_buffer(buffer_type *b, unsigned char *dest, int len, error_type_t *err);
