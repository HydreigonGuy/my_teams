/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** make_server_listen
*/

#include "server.h"
#include <stdlib.h>
#include <unistd.h>

int make_server_listen(my_server_t *server)
{
    if (listen(server->server_socket, MAX_BACKLOG) == -1) {
        close(server->server_socket);
        free(server);
        return (0);
    }
    return (1);
}
