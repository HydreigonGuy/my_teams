/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** run_server
*/

#include "server.h"
#include <stddef.h>

int run_server(my_server_t *server)
{
    connection_t *connect = NULL;

    while (!handle_stdin(server)) {
        set_status(connect);
        check_select(server, connect);
        handle_accept(server, &connect);
        send_response(connect);
        read_message(connect);
        handle_responses(server, connect);
        handle_connection_ends(&connect);
    }
    destroy_connections(&connect);
    close_server(server);
    return (0);
}
