/*
** EPITECH PROJECT, 2022
** client
** File description:
** destroy_client
*/

#include "client.h"
#include <stdlib.h>
#include <unistd.h>

void destroy_client(my_client_t *client)
{
    destroy_buffer(client->read_buff);
    destroy_buffer(client->write_buff);
    free(client->stdin);
    close(client->socket);
    free(client);
}
