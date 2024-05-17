/*
** EPITECH PROJECT, 2022
** server
** File description:
** create_buffer
*/

#include <stdlib.h>
#include "server.h"

buffer_t *create_buffer(void)
{
    buffer_t *buff = malloc(sizeof(buffer_t));

    if (!buff)
        return (NULL);
    buff->start = 0;
    buff->end = 0;
    buff->buff = malloc(sizeof(char) * BUFF_SIZE);
    if (!buff->buff) {
        free(buff);
        return (NULL);
    }
    for (int i = 0; i < BUFF_SIZE; i++)
        buff->buff[i] = '\0';
    return (buff);
}
