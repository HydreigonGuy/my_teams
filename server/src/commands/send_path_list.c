/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_path_list
*/

#include "server.h"

void send_path_list(connection_t *con, team_t *teams)
{
    if (!con->path->team) {
        for (team_t *curr = teams; curr; curr = curr->next)
            send_teams_info(con, curr);
        return;
    }
    if (!con->path->chan) {
        for (channel_t *curr = con->path->team->channels; curr;
        curr = curr->next)
            send_chans_info(con, curr);
        return;
    }
    if (!con->path->thread) {
        for (thread_t *curr = con->path->chan->threads; curr;
        curr = curr->next)
            send_threads_info(con, curr);
        return;
    }
    for (comment_t *curr = con->path->thread->comments; curr;
    curr = curr->next)
        send_comments_info(con, curr);
}
