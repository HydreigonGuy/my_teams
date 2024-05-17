/*
** EPITECH PROJECT, 2022
** client
** File description:
** send_response
*/

#include "client.h"
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

void send_response(my_client_t *client)
{
    char *w_buff = NULL;
    int len = 0;
    int written = 0;

    if (!(client->status == WRITE && client->ready))
        return;
    w_buff = create_w_buff(client->write_buff);
    if (!w_buff)
        return;
    for (; w_buff[len]; len++);
    written = write(client->socket, w_buff, len);
    for (int i = client->write_buff->start;
        i < client->write_buff->start + written; i++)
        client->write_buff->buff[i % BUFF_SIZE] = '\0';
    client->write_buff->start = (client->write_buff->start +
        written) % BUFF_SIZE;
    free(w_buff);
}
