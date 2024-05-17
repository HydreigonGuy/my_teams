/*
** EPITECH PROJECT, 2022
** server
** File description:
** create_new_path
*/

#include "server.h"
#include <stdlib.h>

path_t *create_new_path(void)
{
    path_t *new = malloc(sizeof(path_t));

    if (!new)
        return (NULL);
    new->chan = NULL;
    new->team = NULL;
    new->thread = NULL;
    return (new);
}
