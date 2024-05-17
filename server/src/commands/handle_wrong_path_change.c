/*
** EPITECH PROJECT, 2022
** server
** File description:
** handle_wrong_path_change
*/

#include "server.h"

int get_use_arg_count(char *data)
{
    int c = 0;

    for (int i = 0; data[i]; i++)
        if (data[i] == ',')
            c++;
    if (data[0])
        c++;
    return (c);
}

int handle_wrong_path_change(path_t *path, char *data)
{
    int args = get_use_arg_count(data);

    if (args == 1 && !path->team)
        return (1);
    if (args == 2 && !path->chan)
        return (1);
    if (args == 3 && !path->thread)
        return (1);
    return (0);
}
