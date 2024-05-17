/*
** EPITECH PROJECT, 2022
** server
** File description:
** get_user_by_id
*/

#include "server.h"
#include "taya.h"
#include <stddef.h>

user_t *get_user_by_id(char *id, user_list_t *users)
{
    if (!id)
        return (NULL);
    for (user_list_t *list = users; list; list = list->next)
        if (mystrcmp(id, list->user->id))
            return (list->user);
    return (NULL);
}
