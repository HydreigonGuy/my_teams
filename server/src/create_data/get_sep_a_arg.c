/*
** EPITECH PROJECT, 2022
** server
** File description:
** get_sep_a_arg
*/

#include "server.h"
#include <stdlib.h>

char *get_sep_a_arg(char *data, int arg)
{
    int c = 0;
    char *ret = NULL;
    int len = 0;

    for (int i = 0; i < arg && data[c]; c++)
        if (data[c] == '\a')
            i++;
    if (!data[c])
        return (NULL);
    for (; data[c + len] && data[c + len] != '\a'; len++);
    ret = malloc(sizeof(char) * (len + 1));
    if (!ret)
        return (NULL);
    for (int i = 0; data[c + i] && data[c + i] != '\a'; i++)
        ret[i] = data[i + c];
    ret[len] = '\0';
    return (ret);
}
