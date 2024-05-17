/*
** EPITECH PROJECT, 2022
** server
** File description:
** fill_response
*/

#include "server.h"
#include <stdlib.h>

response_t *fill_response(buffer_t *buff)
{
    response_t *new = NULL;
    int check = 0;

    for (; (buff->start + check) % BUFF_SIZE != buff->end &&
        !(buff->buff[(buff->start + check) % BUFF_SIZE] == '\r' &&
        buff->buff[(buff->start + check + 1) % BUFF_SIZE] == '\n'); check++);
    if ((buff->start + check) % BUFF_SIZE != buff->end)
        new = malloc(sizeof(response_t));
    if (!new)
        return (NULL);
    extract_response_info(new, buff);
    remove_resp_from_buffer(buff);
    if (!new)
        return (NULL);
    return (new);
}
