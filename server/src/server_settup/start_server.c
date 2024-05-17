/*
** EPITECH PROJECT, 2022
** server
** File description:
** start_server
*/

#include "server.h"
#include <stdlib.h>
#include <unistd.h>

int start_server(int port)
{
    my_server_t *server = fill_server_info(port);

    if (!server || !bind_server(server) || !make_server_listen(server))
        return (84);
    run_server(server);
    close(server->server_socket);
    free(server);
    return (0);
}
