/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_args
*/

#include "client.h"
#include "taya.h"

int handle_args(char *ip, char *port_str)
{
    int port = my_str_to_uint(port_str);

    if (port == -1)
        return (84);
    return (start_client(port, ip));
}
