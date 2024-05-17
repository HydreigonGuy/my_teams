/*
** EPITECH PROJECT, 2022
** server
** File description:
** get_users_str
*/

#include "server.h"
#include <stdlib.h>
#include "taya.h"

char *get_users_str(user_t *user)
{
    int len = 0;
    char *ret = NULL;
    int i = 0;

    if (!user || !user->name || !user->id)
        return (NULL);
    len = my_str_len(user->name) + my_str_len(user->id) + 2;
    ret = malloc(sizeof(char) * len);
    if (!ret)
        return (NULL);
    for (; user->name[i]; i++)
        ret[i] = user->name[i];
    ret[i] = ',';
    i++;
    for (int j = 0; user->id[j]; j++, i++)
        ret[i] = user->id[j];
    ret[i] = '\0';
    return (ret);
}
