/*
** EPITECH PROJECT, 2022
** server
** File description:
** destroy_user
*/

#include "server.h"
#include <stdlib.h>

void destroy_user(user_t *user)
{
    if (user->name)
        free(user->name);
    if (user->id)
        free(user->id);
    free(user);
}
