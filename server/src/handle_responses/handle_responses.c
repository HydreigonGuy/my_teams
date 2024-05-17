/*
** EPITECH PROJECT, 2022
** server
** File description:
** handle_responses
*/

#include "server.h"
#include "taya.h"
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

void handle_responses(my_server_t *server, connection_t *connect)
{
    response_t *resp = NULL;

    for (connection_t *curr = connect; curr; curr = curr->next) {
        resp = fill_response(curr->read_buff);
        if (resp) {
            myputstr(resp->msg);
            write(1, "\n", 1);
            execute_response(server, curr, resp, connect);
            free(resp->msg);
        }
        if (resp && resp->data)
            free(resp->data);
        if (resp)
            free(resp);
    }
}
