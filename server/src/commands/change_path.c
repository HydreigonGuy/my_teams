/*
** EPITECH PROJECT, 2022
** server
** File description:
** change_path
*/

#include "server.h"
#include <stdlib.h>
#include "taya.h"

team_t *get_path_teams(char *data, team_t *teams)
{
    char *id = NULL;
    int len = 0;

    for (; data[len] && data[len] != ','; len++);
    if (len == 0)
        return (NULL);
    id = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; id[i] = data[i], i++);
    id[len] = '\0';
    for (team_t *curr = teams; curr; curr = curr->next)
        if (mystrcmp(id, curr->id)) {
            free(id);
            return (curr);
        }
    free(id);
    return (NULL);
}

channel_t *get_path_channel(char *data, channel_t *chans)
{
    char *id = NULL;
    int start = 0;
    int len = 0;

    for (; data[start] && data[start] != ','; start++);
    if (!data[start])
        return (NULL);
    start++;
    for (; data[start + len] && data[start + len] != ','; len++);
    id = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; id[i] = data[start + i], i++);
    id[len] = '\0';
    for (channel_t *curr = chans; curr; curr = curr->next)
        if (mystrcmp(id, curr->id)) {
            free(id);
            return (curr);
        }
    free(id);
    return (NULL);
}

thread_t *get_path_tread(char *data, thread_t *threads)
{
    char *id = NULL;
    int start = 0;
    int len = 0;

    for (int i = 0; i < 2; i++, start++) {
        for (; data[start] && data[start] != ','; start++);
        if (!data[start])
            return (NULL);
    }
    for (; data[start + len] && data[start + len] != ','; len++);
    id = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; id[i] = data[start + i], i++);
    id[len] = '\0';
    for (thread_t *curr = threads; curr; curr = curr->next)
        if (mystrcmp(id, curr->id)) {
            free(id);
            return (curr);
        }
    free(id);
    return (NULL);
}

void change_path(char *data, connection_t *con, team_t *teams)
{
    con->path->team = NULL;
    con->path->chan = NULL;
    con->path->thread = NULL;
    if (!data)
        return;
    con->path->team = get_path_teams(data, teams);
    if (con->path->team)
        con->path->chan = get_path_channel(data, con->path->team->channels);
    if (con->path->team && con->path->chan)
        con->path->thread = get_path_tread(data, con->path->chan->threads);
    if (handle_wrong_path_change(con->path, data)) {
        con->path->team = NULL;
        con->path->chan = NULL;
        con->path->thread = NULL;
        create_response(con->write_buff, 407, NULL, "Bad path");
    } else
        create_response(con->write_buff, 240, NULL, "Path changed");
}
