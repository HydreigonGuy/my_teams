/*
** EPITECH PROJECT, 2022
** client
** File description:
** check_select
*/

#include "client.h"
#include <sys/select.h>

void fill_fds(my_client_t *cli, fd_set *r_fds, fd_set *w_fds, fd_set *e_fds)
{
    FD_ZERO(r_fds);
    FD_ZERO(w_fds);
    FD_ZERO(e_fds);
    cli->ready = 0;
    cli->stdin->ready = 0;
    if (cli->status == READ)
        FD_SET(cli->socket, r_fds);
    if (cli->status == WRITE)
        FD_SET(cli->socket, w_fds);
    if (cli->status == EXCEPT)
        FD_SET(cli->socket, e_fds);
    if (cli->stdin->status == READ)
        FD_SET(0, r_fds);
}

void check_select(my_client_t *client)
{
    struct timeval tv;
    fd_set read_fds;
    fd_set write_fds;
    fd_set ex_fds;

    tv.tv_sec = 0;
    tv.tv_usec = 0;
    fill_fds(client, &read_fds, &write_fds, &ex_fds);
    if (select(client->socket + 1,
        &read_fds, &write_fds, &ex_fds, &tv) == -1)
        return;
    if (client->stdin->status == READ && FD_ISSET(0, &read_fds))
        client->stdin->ready = 1;
    if ((client->status == READ && FD_ISSET(client->socket, &read_fds))
        || (client->status == WRITE && FD_ISSET(client->socket, &write_fds))
        || (client->status == EXCEPT && FD_ISSET(client->socket, &ex_fds)))
        client->ready = 1;
}
