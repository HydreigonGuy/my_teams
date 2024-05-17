/*
** EPITECH PROJECT, 2022
** client
** File description:
** destroy_buffer
*/

#include "client.h"
#include <stdlib.h>

void destroy_buffer(buffer_t *buff)
{
    free(buff->buff);
    free(buff);
}
