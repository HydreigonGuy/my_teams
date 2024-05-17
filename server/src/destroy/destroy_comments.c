/*
** EPITECH PROJECT, 2022
** server
** File description:
** destroy_comments
*/

#include "server.h"
#include <stdlib.h>

void destroy_comments(comment_t *comments)
{
    comment_t *tmp = NULL;

    for (comment_t *curr = comments; curr; curr = curr->next) {
        if (curr->body)
            free(curr->body);
        if (curr->id)
            free(curr->id);
    }
    while (comments) {
        tmp = comments;
        comments = comments->next;
        free(tmp);
    }
}
