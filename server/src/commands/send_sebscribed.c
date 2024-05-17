/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_sebscribed
*/

#include "server.h"

void send_team_users_info(connection_t *con, team_t *team)
{
    for (user_list_t *curr = team->users; curr; curr = curr->next)
        send_user_list(con, curr->user);
}

void send_subscribed_teams(connection_t *con, team_t *teams)
{
    for (team_t *curr = teams; curr; curr = curr->next)
        if (get_user_by_id(con->user->id, curr->users))
            send_teams_info(con, curr);
}

void send_sebscribed(connection_t *con, char *data, team_t *teams)
{
    if (data) {
        send_team_users_info(con, get_team_by_id(data, teams));
    } else
        send_subscribed_teams(con, teams);
}
