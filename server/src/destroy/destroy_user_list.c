/*
** EPITECH PROJECT, 2022
** server
** File description:
** destroy_user_list
*/

#include "server.h"
#include "stdlib.h"

void destroy_user_list(user_list_t *list)
{
    user_list_t *tmp = NULL;

    for (user_list_t *curr = list; curr; curr = curr->next)
        destroy_user(curr->user);
    while (list) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}
