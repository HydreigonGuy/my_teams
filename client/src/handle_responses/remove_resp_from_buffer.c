/*
** EPITECH PROJECT, 2022
** server
** File description:
** remove_resp_from_buffer
*/

#include "client.h"

void remove_resp_from_buffer(buffer_t *buff)
{
    for (; (buff->start) % BUFF_SIZE != buff->end &&
        !(buff->buff[buff->start % BUFF_SIZE] == '\r' &&
        buff->buff[(buff->start + 1) % BUFF_SIZE] == '\n');
        buff->start = (buff->start + 1) % BUFF_SIZE)
        buff->buff[buff->start % BUFF_SIZE] = '\0';
    buff->start = (buff->start + 1) % BUFF_SIZE;
    buff->buff[(buff->start) % BUFF_SIZE] = '\0';
    buff->start = (buff->start + 1) % BUFF_SIZE;
}
