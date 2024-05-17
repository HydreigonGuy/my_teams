/*
** EPITECH PROJECT, 2022
** client
** File description:
** start_client
*/

#include "client.h"
#include <stdlib.h>
#include <unistd.h>

int start_client(int port, char *ip)
{
    my_client_t *client = fill_client_info(port, ip);

    if (!client)
        return (84);
    if (connect(client->socket, (struct sockaddr *) &client->address,
        sizeof(client->address)) == -1)
        return (84);
    run_client(client);
    destroy_client(client);
    return (0);
}
