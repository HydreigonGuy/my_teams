/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** fillServerInfo
*/

#include "server.h"
#include <stddef.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

my_server_t *fill_server_info(int port)
{
    my_server_t *serv = malloc(sizeof(my_server_t));

    if (!serv)
        return (NULL);
    serv->data = fill_server_data();
    if (!serv->data) {
        free(serv);
        return (NULL);
    }
    serv->server_socket = socket(AF_INET, SOCK_STREAM, 0);
    serv->address.sin_family = AF_INET;
    serv->address.sin_port = htons(port);
    inet_aton("127.0.0.1", (struct in_addr *) &serv->address.sin_addr.s_addr);
    serv->stdin_ready = 0;
    serv->can_accept = 0;
    return (serv);
}
