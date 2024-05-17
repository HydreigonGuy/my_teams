/*
** EPITECH PROJECT, 2022
** server
** File description:
** handle_connection_ends
*/

#include "server.h"
#include <unistd.h>
#include <stdlib.h>

void handle_connection_ends(connection_t **connect)
{
    connection_t *tmp = *connect;

    while (tmp && ((tmp->status == SHUTDOWN &&
    tmp->write_buff->start == tmp->write_buff->end)
    || tmp->status == DISCONNECTED)) {
        close_connection(tmp);
        *connect = tmp->next;
        free(tmp);
        tmp = *connect;
    }
    for (connection_t *curr = tmp; curr && curr->next; curr = curr->next) {
        if (curr->next->status == DISCONNECTED || (curr->next->status ==
        SHUTDOWN && tmp->next->write_buff->start ==
        tmp->next->write_buff->end)) {
            close_connection(curr->next);
            tmp = curr->next;
            curr->next = tmp->next;
            free(tmp);
        }
    }
}
