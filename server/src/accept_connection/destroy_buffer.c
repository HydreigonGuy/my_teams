/*
** EPITECH PROJECT, 2022
** server
** File description:
** destroy_buffer
*/

#include "server.h"
#include <stdlib.h>

void destroy_buffer(buffer_t *buff)
{
    free(buff->buff);
    free(buff);
}
