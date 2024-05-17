/*
** EPITECH PROJECT, 2022
** server
** File description:
** create_user
*/

#include "server.h"
#include <stdlib.h>
#include "taya.h"
#include "logging_server.h"

user_t *fill_user(char *name)
{
    user_t *ret = malloc(sizeof(user_t));

    ret->name = my_strdup(name);
    ret->connections = 0;
    ret->id = create_id();
    ret->messages = NULL;
    return (ret);
}

user_list_t *fill_user_list(char *name)
{
    user_list_t *ret = malloc(sizeof(user_list_t));

    if (!ret)
        return (NULL);
    ret->user = fill_user(name);
    if (!ret->user) {
        free(ret);
        return (NULL);
    }
    ret->next = NULL;
    server_event_user_created(ret->user->id, ret->user->name);
    return (ret);
}

void create_user(char *name, user_list_t **users)
{
    user_list_t *list = *users;

    if (!list) {
        *users = fill_user_list(name);
    } else {
        for (; list && list->next; list = list->next);
        list->next = fill_user_list(name);
    }
}
