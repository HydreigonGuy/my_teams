/*
** EPITECH PROJECT, 2022
** server
** File description:
** load threads
*/

#include "server.h"
#include <stdio.h>
#include <string.h>

comment_t *getComment(char *line)
{
    comment_t *comment = malloc(sizeof(comment_t));
    char *token = strtok(line, "¶\n");
    comment->body = malloc(sizeof(char) * strlen(token) + 1);
    strcpy(comment->body, token);
    token = strtok(NULL, "¶\n");
    comment->id = malloc(sizeof(char) * strlen(token) + 1);
    strcpy(comment->id, token);
    token = strtok(NULL, "¶\n");
    comment->time = atol(token);
    token = strtok(NULL, "¶\n");
    comment->user_id = malloc(sizeof(char) * strlen(token) + 1);
    strcpy(comment->user_id, token);
    token = strtok(NULL, "\n");
    if (token == NULL) {
        comment->next = NULL;
    } else {
        comment->next = getComment(token);
    }
    return comment;
}

void fillComments(thread_t *thread, char *line, size_t len, FILE *file)
{
    if (getline(&line, &len, file) == -1 ||
        strcmp(line, "THREAD\n") == 0 ||
        strcmp(line, "TEAM\n") == 0 ||
        strcmp(line, "CHANNEL\n") == 0) {
        thread->comments = NULL;
        return;
    }
    comment_t *comment = getComment(line);
    if (thread->comments == NULL) {
        thread->comments = comment;
    } else {
        comment_t *tmp = thread->comments;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = comment;
    }
}

thread_t *getThread(char *line, size_t len, FILE *file)
{
    char *line_copy = malloc(sizeof(char) * strlen(line) + 1);
    thread_t *thread = malloc(sizeof(thread_t));
    strcpy(line_copy, line);
    char *token = strtok(line_copy, "¶\n");
    thread->title = malloc(sizeof(char) * strlen(token) + 1);
    strcpy(thread->title, token);
    token = strtok(NULL, "¶\n");
    thread->message = malloc(sizeof(char) * strlen(token) + 1);
    strcpy(thread->message, token);
    token = strtok(NULL, "¶\n");
    thread->id = malloc(sizeof(char) * strlen(token) + 1);
    strcpy(thread->id, token);
    token = strtok(NULL, "¶\n");
    thread->time = atol(token);
    token = strtok(NULL, "¶\n");
    thread->user_id = malloc(sizeof(char) * strlen(token) + 1);
    strcpy(thread->user_id, token);
    fillComments(thread, line, len, file);
    return thread;
}

thread_t *getThreadList(char *line, size_t len, FILE *file)
{
    getline(&line, &len, file);
    thread_t *thread = getThread(line, len, file);
    while (getline(&line, &len, file) != -1 &&
        strcmp(line, "CHANNEL\n") != 0 &&
        strcmp(line, "TEAM\n") != 0 &&
        strcmp(line, "THREAD\n") != 0) {
        thread_t *tmp = getThread(line, len, file);
        thread_t *tmp2 = thread;
        while (tmp2->next != NULL) {
            tmp2 = tmp2->next;
        }
        tmp2->next = tmp;
    }
    return thread;
}
