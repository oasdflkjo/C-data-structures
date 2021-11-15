/*
 * ring_buffer.c
 *
 *  Created on: Oct 15, 2021
 *      Author: oasdflkjo
 * 
 * Ring buffer implementation that i had to make for school assignment.
 * TODO: 
 * include guards
 */

#include <stdio.h>
#include "ring_buffer.h"

void init_buffer(buffer_type *b, unsigned char *buffer)
{
    b->head = buffer;
    b->tail = buffer;
}

// If this problem is the point of this assignment, then i guess its a good one.
// But if its not then this is imo very bad assignment.
enum error_type empty_buffer(buffer_type *b)
{
    enum error_type error;
    error = OK;
    return error;
}

int get_buffer_state(buffer_type *b, error_type *err)
{
    if (b->head == b->tail)
    {
        return 0;
    }
    else if (b->head > b->tail)
    {
        err->error = BUF_FULL;
        return 1;
    }
    else
    {
        return (b->head - b->tail);
    }
}

int add_char_to_buffer(buffer_type *b, unsigned char c, error_type *err)
{
    if (get_buffer_state(b, err) == 0)
    {
        *b->head = c;
        b->head++;
        if (b->head == b->buffer + MAX_BUFFER_SIZE)
        {
            b->head = b->buffer;
        }
        return 0;
    }
    else
    {
        err->error = BUF_FULL;
        return -1;
    }
}

char get_char_from_buffer(buffer_type *b, error_type *err)
{
    if (get_buffer_state(b, err) == 0)
    {
        char c = *b->tail;
        b->tail++;
        if (b->tail == b->buffer + MAX_BUFFER_SIZE)
        {
            b->tail = b->buffer;
        }
        return c;
    }
    else
    {
        err->error = BUF_EMPTY;
        return -1;
    }
}

int print_buffer(buffer_type b, error_type *err)
{
    if (get_buffer_state(&b, err) == 0)
    {
        return -1;
    }
    else
    {
        unsigned char *temp = b.head;
        while (temp != b.tail)
        {
            printf("%c", *temp);
            temp++;
            if (temp == b.buffer + MAX_BUFFER_SIZE)
            {
                temp = b.buffer;
            }
        }
        return 0;
    }
}

int add_string_to_buffer(buffer_type *b, unsigned char *s, error_type *err)
{
    if (get_buffer_state(b, err) == 0)
    {
        while (*s != '\0')
        {
            *b->head = *s;
            b->head++;
            if (b->head == b->buffer + MAX_BUFFER_SIZE)
            {
                b->head = b->buffer;
            }
            s++;
        }
        return 0;
    }
    else
    {
        err->error = BUF_FULL;
        return -1;
    }
}

int get_string_from_buffer(buffer_type *b, unsigned char *dest, int len, error_type *err)
{
    if (get_buffer_state(b, err) == 0)
    {
        return -1;
    }
    else
    {
        int i = 0;
        while (i < len)
        {
            *dest = *b->tail;
            b->tail++;
            if (b->tail == b->buffer + MAX_BUFFER_SIZE)
            {
                b->tail = b->buffer;
            }
            dest++;
            i++;
        }
        return 0;
    }
}
