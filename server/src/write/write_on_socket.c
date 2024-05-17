/*
** EPITECH PROJECT, 2022
** server
** File description:
** write_on_socket
*/

#include "server.h"
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

char *create_w_buff(buffer_t *buff)
{
    char *w_buff = NULL;
    int len = 0;

    for (; buff->buff[(buff->start + len) % BUFF_SIZE] &&
        (buff->start + len) % BUFF_SIZE != buff->end; len++);
    w_buff = malloc(sizeof(char) * (len + 1));
    if (!w_buff)
        return (NULL);
    for (int i = 0; buff->buff[(buff->start + i) % BUFF_SIZE] &&
        (buff->start + i) % BUFF_SIZE != buff->end; i++)
        w_buff[i] = buff->buff[(buff->start + i) % BUFF_SIZE];
    w_buff[len] = '\0';
    return (w_buff);
}

void write_on_socket(int fd, buffer_t *buff)
{
    char *w_buff = create_w_buff(buff);
    int len = 0;
    int written = 0;

    if (!w_buff)
        return;
    for (; w_buff[len]; len++);
    written = write(fd, w_buff, len);
    for (int i = buff->start; i < buff->start + written; i++)
        buff->buff[i % BUFF_SIZE] = '\0';
    buff->start = (buff->start + written) % BUFF_SIZE;
    free(w_buff);
}
