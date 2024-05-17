/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_path_info
*/

#include "server.h"

void send_path_info(connection_t *con)
{
    if (!con->path->team) {
        send_user(con, con->user);
        return;
    }
    if (!con->path->chan) {
        send_team_info(con, con->path->team);
        return;
    }
    if (!con->path->thread) {
        send_chan_info(con, con->path->chan);
        return;
    }
    send_thread_info(con, con->path->thread);
}
