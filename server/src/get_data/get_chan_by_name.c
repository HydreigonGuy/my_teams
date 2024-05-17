/*
** EPITECH PROJECT, 2022
** server
** File description:
** get_chan_by_name
*/

#include "server.h"
#include "taya.h"
#include <stddef.h>

channel_t *get_chan_by_name(char *name, channel_t *chans)
{
    for (channel_t *curr = chans; curr; curr = curr->next)
        if (mystrcmp(name, curr->name))
            return (curr);
    return (NULL);
}
