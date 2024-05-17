/*
** EPITECH PROJECT, 2022
** server
** File description:
** destroy_teams
*/

#include "server.h"
#include <stdlib.h>

void destroy_teams(team_t *teams)
{
    team_t *tmp = NULL;

    for (team_t *curr = teams; curr; curr = curr->next) {
        destroy_channels(curr->channels);
        if (curr->id)
            free(curr->id);
        if (curr->description)
            free(curr->description);
        if (curr->name)
            free(curr->name);
    }
    while (teams) {
        tmp = teams;
        teams = teams->next;
        free(tmp);
    }
}
