/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_responses
*/

#include "client.h"
#include "taya.h"
#include <stdlib.h>
#include <unistd.h>

void handle_responses(my_client_t *client)
{
    response_t *resp = fill_response(client->read_buff);

    if (!resp)
        return;
    execute_response(resp, client);
    myputstr(resp->msg);
    write(1, "\n", 1);
    free(resp->msg);
    if (resp->data)
        free(resp->data);
    free(resp);
}
