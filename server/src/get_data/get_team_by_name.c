/*
** EPITECH PROJECT, 2022
** server
** File description:
** get_team_by_name
*/

#include "server.h"
#include <stddef.h>
#include "taya.h"

team_t *get_team_by_name(char *name, team_t *teams)
{
    for (team_t *curr = teams; curr; curr = curr->next)
        if (mystrcmp(name, curr->id))
            return (curr);
    return (NULL);
}
