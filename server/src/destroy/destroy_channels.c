/*
** EPITECH PROJECT, 2022
** server
** File description:
** destroy_channels
*/

#include "server.h"
#include <stdlib.h>

void destroy_channels(channel_t *channels)
{
    channel_t *tmp = NULL;

    for (channel_t *curr = channels; curr; curr = curr->next) {
        destroy_threads(curr->threads);
        if (curr->description)
            free(curr->description);
        if (curr->id)
            free(curr->id);
        if (curr->name)
            free(curr->name);
    }
    while (channels) {
        tmp = channels;
        channels = channels->next;
        free(tmp);
    }
}
