/*
** EPITECH PROJECT, 2022
** server
** File description:
** create_message
*/

#include "server.h"
#include <time.h>
#include <stdlib.h>

messages_t *create_new_message(char *user_id, char *body)
{
    messages_t *ret = malloc(sizeof(messages_t));

    if (!ret)
        return (NULL);
    ret->body = body;
    ret->next = NULL;
    time(&ret->time);
    ret->userid = user_id;
    return (ret);
}

void create_message(user_t *user, char *user_id, char *body)
{
    messages_t *msg = user->messages;

    if (!msg) {
        user->messages = create_new_message(user_id, body);
    } else {
        for (; msg && msg->next; msg = msg->next);
        msg->next = create_new_message(user_id, body);
    }
}
