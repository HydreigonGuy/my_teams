/*
** EPITECH PROJECT, 2022
** server
** File description:
** get_user_id
*/

#include "server.h"
#include <stddef.h>
#include "taya.h"

char *get_user_id(char *name, user_list_t **users)
{
    if (!name)
        return (NULL);
    for (user_list_t *list = *users; list; list = list->next)
        if (mystrcmp(name, list->user->name))
            return (list->user->id);
    create_user(name, users);
    for (user_list_t *list = *users; list; list = list->next)
        if (mystrcmp(name, list->user->name))
            return (list->user->id);
    return (NULL);
}
