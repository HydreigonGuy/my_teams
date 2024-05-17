/*
** EPITECH PROJECT, 2022
** server
** File description:
** load users
*/

#include "server.h"
#include <stdio.h>
#include <string.h>

messages_t *getMessage(char *token)
{
    messages_t *messages = NULL;
    messages = malloc(sizeof(messages_t));
    messages->userid = malloc(sizeof(char) * strlen(token) + 1);
    strcpy(messages->userid, token);
    token = strtok(NULL, "¶");
    messages->body = malloc(sizeof(char) * strlen(token) + 1);
    strcpy(messages->body, token);
    token = strtok(NULL, "¶\n");
    messages->time = atol(token);
    messages->next = NULL;
    return messages;
}

void fillMessages(user_t *user, char *token)
{
    messages_t *messages = getMessage(token);
    if (user->messages == NULL) {
        user->messages = messages;
    } else {
        messages_t *tmp = user->messages;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = messages;
    }
}

user_t *getUser(char *line)
{
    user_t *user = malloc(sizeof(user_t));
    char *token = strtok(line, "¶\n");
    user->name = malloc(sizeof(char) * strlen(token) + 1);
    strcpy(user->name, token);
    token = strtok(NULL, "¶\n");
    user->id = malloc(sizeof(char) * strlen(token) + 1);
    strcpy(user->id, token);
    user->connections = 0;
    token = strtok(NULL, "¶\n");
    while (token != NULL) {
        fillMessages(user, token);
        token = strtok(NULL, "¶\n");
    }
    return user;
}

void fillUserList(user_list_t *user_list, char *line)
{
    user_t *user = getUser(line);
    if (user_list->user == NULL) {
        user_list->user = user;
    } else {
        user_list_t *tmp = user_list;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = malloc(sizeof(user_list_t));
        tmp->next->user = user;
        tmp->next->next = NULL;
    }
}

user_list_t *getUserList(char *line, size_t len, FILE *file)
{
    user_list_t *user_list = malloc(sizeof(user_list_t));

    while (getline(&line, &len, file) != -1 && strcmp(line, "TEAM\n") != 0) {
        fillUserList(user_list, line);
    }
    return user_list;
}
