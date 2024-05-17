/*
** EPITECH PROJECT, 2022
** server
** File description:
** message_everyone
*/

#include "server.h"

void message_everyone(connection_t *con, int code, char *data, char *msg)
{
    for (connection_t *curr = con; curr; curr = curr->next)
        if (curr->user)
            create_response(curr->write_buff, code, data, msg);
}
