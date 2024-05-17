/*
** EPITECH PROJECT, 2022
** server
** File description:
** close_connection
*/

#include "server.h"
#include <unistd.h>
#include <stdlib.h>

void close_connection(connection_t *connect)
{
    if (connect->user)
        connect->user->connections -= 1;
    close(connect->fd);
    destroy_buffer(connect->read_buff);
    destroy_buffer(connect->write_buff);
}
