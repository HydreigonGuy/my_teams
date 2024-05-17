/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** create_connection
*/

#include "server.h"
#include <stddef.h>
#include <taya.h>
#include <stdlib.h>

int fill_new_connection_info(connection_t *new, int fd)
{
    new->fd = fd;
    new->status = WRITE;
    new->ready = 0;
    new->next = NULL;
    new->path = create_new_path();
    new->user = NULL;
    if (!new->path) {
        destroy_buffer(new->read_buff);
        destroy_buffer(new->write_buff);
        free(new);
        return (0);
    }
    create_response(new->write_buff, 220, NULL, "Connected successfully");
    return (1);
}

connection_t *create_new_connection(int fd)
{
    connection_t *new = malloc(sizeof(connection_t));

    if (!new)
        return (NULL);
    new->read_buff = create_buffer();
    if (!new->read_buff) {
        free(new);
        return (NULL);
    }
    new->write_buff = create_buffer();
    if (!new->write_buff) {
        destroy_buffer(new->read_buff);
        free(new);
        return (NULL);
    }
    if (!fill_new_connection_info(new, fd))
        return (NULL);
    return (new);
}

void create_connection(connection_t **connect, int fd)
{
    connection_t *curr = *connect;

    if (!curr) {
        *connect = create_new_connection(fd);
        return;
    }
    for (; curr && curr->next; curr = curr->next);
    curr->next = create_new_connection(fd);
}
