/*
** EPITECH PROJECT, 2022
** server
** File description:
** destroy_database
*/

#include "server.h"

void destroy_database(database_t *data)
{
    destroy_user_list(data->users);
    destroy_teams(data->teams);
}
