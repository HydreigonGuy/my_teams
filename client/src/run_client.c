/*
** EPITECH PROJECT, 2022
** client
** File description:
** run_client
*/

#include "client.h"

void run_client(my_client_t *client)
{
    while (1) {
        set_status(client);
        check_select(client);
        send_response(client);
        read_message(client);
        if (client->shutdown == 2)
            return;
        handle_responses(client);
        handle_stdin(client);
    }
}
