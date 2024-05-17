/*
** EPITECH PROJECT, 2022
** server
** File description:
** subscribe
*/

#include "server.h"
#include <stdlib.h>
#include "logging_server.h"

void subscribe_user(user_t *user, team_t *team)
{
    user_list_t *list = team->users;

    if (get_user_by_id(user->id, team->users))
        return;
    if (!list) {
        team->users = malloc(sizeof(user_list_t));
        if (!team->users)
            return;
        team->users->next = NULL;
        team->users->user = user;
        return;
    }
    for (; list && list->next; list = list->next);
    list->next = malloc(sizeof(user_list_t));
    if (!list->next)
        return;
    list->next->next = NULL;
    list->next->user = user;
}

void subscribe(char *data, team_t *teams, connection_t *con,
connection_t *all)
{
    team_t *team = NULL;
    char *resp_data = NULL;

    if (!data) {
        create_response(con->write_buff, 406, NULL,\
        "Missing or invalid argument(s)");
        return;
    }
    team = get_team_by_id(data, teams);
    if (!team) {
        create_response(con->write_buff, 407, NULL, "Bad path");
        return;
    }
    subscribe_user(con->user, team);
    server_event_user_subscribed(team->id, con->user->id);
    resp_data = create_2_comma_resp(con->user->id, team->id);
    if (resp_data) {
        message_subed(all, team, 250, resp_data);
        free(resp_data);
    }
}
