/*
** EPITECH PROJECT, 2022
** server
** File description:
** unsubscribe
*/

#include "server.h"
#include <stdlib.h>
#include "taya.h"
#include "logging_server.h"

int unsubscribe_user(user_t *user, team_t *team)
{
    user_list_t *tmp = NULL;

    if (!team->users)
        return (0);
    if (mystrcmp(user->id, team->users->user->id)) {
        tmp = team->users;
        team->users = team->users->next;
    }
    for (user_list_t *curr; curr && curr->next; curr = curr->next)
        if (mystrcmp(user->id, curr->next->user->id)) {
            tmp = curr->next;
            curr->next = curr->next->next;
        }
    if (tmp) {
        free(tmp);
        return (1);
    }
    return (0);
}

void unsubscribe(char *data, team_t *teams, connection_t *con,
connection_t *all)
{
    team_t *team = NULL;
    char *resp_data = NULL;

    if (!data) {
        create_response(con->write_buff, 406, NULL, "Arg error");
        return;
    }
    team = get_team_by_id(data, teams);
    if (!team || !unsubscribe_user(con->user, team)) {
        create_response(con->write_buff, 407, NULL, "Bad path");
        return;
    }
    resp_data = create_2_comma_resp(con->user->id, team->id);
    server_event_user_unsubscribed(team->id, con->user->id);
    if (resp_data) {
        message_subed(all, team, 251, resp_data);
        free(resp_data);
    }
}
