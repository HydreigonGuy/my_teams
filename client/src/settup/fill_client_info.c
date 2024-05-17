/*
** EPITECH PROJECT, 2022
** client
** File description:
** fill_client_info
*/

#include "client.h"
#include <stddef.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

stdin_check_t *fill_client_stdin(void)
{
    stdin_check_t *new = malloc(sizeof(stdin_check_t));

    if (!new)
        return (NULL);
    new->status = READ;
    new->ready = 0;
    new->read = NULL;
    new->write = NULL;
    return (new);
}

int set_client_buffers(my_client_t *client)
{
    client->read_buff = create_buffer();
    if (!client->read_buff) {
        free(client->stdin);
        return (0);
    }
    client->write_buff = create_buffer();
    if (!client->write_buff) {
        free(client->stdin);
        destroy_buffer(client->read_buff);
        return (0);
    }
    return (1);
}

my_client_t *fill_client_info(int port, char *ip)
{
    my_client_t *client = malloc(sizeof(my_client_t));

    if (!client)
        return (NULL);
    client->stdin = fill_client_stdin();
    if (!client->stdin || !set_client_buffers(client)) {
        free(client);
        return (NULL);
    }
    client->socket = socket(AF_INET, SOCK_STREAM, 0);
    client->address.sin_family = AF_INET;
    client->address.sin_port = htons(port);
    inet_aton(ip, (struct in_addr *) &client->address.sin_addr.s_addr);
    client->status = READ;
    client->ready = 0;
    client->shutdown = 0;
    return (client);
}
