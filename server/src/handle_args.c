/*
** EPITECH PROJECT, 2022
** server
** File description:
** handle_args
*/

#include "taya.h"
#include "server.h"

int handle_args(char *port_str)
{
    int port = my_str_to_uint(port_str);

    if (port == -1)
        return (84);
    return (start_server(port));
}
