/*
** EPITECH PROJECT, 2022
** server
** File description:
** get_team_by_id
*/

#include "server.h"
#include <stddef.h>
#include "taya.h"

team_t *get_team_by_id(char *id, team_t *teams)
{
    for (team_t *curr = teams; curr; curr = curr->next)
        if (mystrcmp(id, curr->id))
            return (curr);
    return (NULL);
}
