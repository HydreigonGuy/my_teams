/*
** EPITECH PROJECT, 2022
** client
** File description:
** read_message
*/

#include "client.h"
#include <unistd.h>
#include <stdlib.h>

void read_message(my_client_t *client)
{
    char *r_buff = NULL;

    if (!(client->status == READ && client->ready))
        return;
    r_buff = malloc(sizeof(char) * READ_SIZE + 1);
    for (int i = 0; i < READ_SIZE + 1; i++)
        r_buff[i] = '\0';
    if (read(client->socket, r_buff, READ_SIZE) == 0)
        client->shutdown = 2;
    for (int i = 0; r_buff[i]; i++) {
        client->read_buff->buff[client->read_buff->end] = r_buff[i];
        client->read_buff->end = (client->read_buff->end + 1) % BUFF_SIZE;
    }
    free(r_buff);
}
