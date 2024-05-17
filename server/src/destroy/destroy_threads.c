/*
** EPITECH PROJECT, 2022
** server
** File description:
** destroy_threads
*/

#include "server.h"
#include <stdlib.h>

void destroy_threads(thread_t *threads)
{
    thread_t *tmp = NULL;

    for (thread_t *curr = threads; curr; curr = curr->next) {
        destroy_comments(curr->comments);
        if (curr->id)
            free(curr->id);
        if (curr->message)
            free(curr->message);
        if (curr->title)
            free(curr->title);
    }
    while (threads) {
        tmp = threads;
        threads = threads->next;
        free(tmp);
    }
}
