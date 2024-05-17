/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** handle_accept
*/

#include "server.h"

void handle_accept(my_server_t *server, connection_t **connect)
{
    int fd = 0;

    if (server->can_accept) {
        fd = accept_connection(server);
        if (fd == 0)
            return;
        create_connection(connect, fd);
    }
}
