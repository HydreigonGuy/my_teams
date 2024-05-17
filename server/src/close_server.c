/*
** EPITECH PROJECT, 2022
** server
** File description:
** close_server
*/

#include "server.h"

void close_server(my_server_t *server)
{
    createDatabase(server->data);
    destroy_database(server->data);
}
