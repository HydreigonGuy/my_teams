/*
** EPITECH PROJECT, 2022
** server
** File description:
** load teams
*/

#include "server.h"
#include <stdio.h>
#include <string.h>


channel_t *getChannel(char *line, size_t len, FILE *file)
{
    channel_t *channel = malloc(sizeof(channel_t));
    char *token = strtok(line, "¶\n");
    channel->name = malloc(sizeof(char) * strlen(token) + 1);
    strcpy(channel->name, token);
    token = strtok(NULL, "¶\n");
    channel->description = malloc(sizeof(char) * strlen(token) + 1);
    strcpy(channel->description, token);
    token = strtok(NULL, "¶\n");
    channel->id = malloc(sizeof(char) * strlen(token) + 1);
    strcpy(channel->id, token);
    if (getline(&line, &len, file) != -1 && strcmp(line, "THREAD\n") == 0) {
        channel->threads = getThreadList(line, len, file);
    } else {
        channel->threads = NULL;
    }
    return channel;
}

channel_t *getChannelList(char *line, size_t len, FILE *file)
{
    getline(&line, &len, file);
    channel_t *channel = getChannel(line, len, file);
    while (strcmp(line, "CHANNEL\n") == 0 &&
        getline(&line, &len, file) != -1) {
        channel_t *tmp = getChannel(line, len, file);
        channel_t *tmp2 = channel;
        while (tmp2->next != NULL) {
            tmp2 = tmp2->next;
        }
        tmp2->next = tmp;
    }
    return channel;
}

user_list_t *fillUserInTeam(user_list_t *user_list, char *token)
{
    user_list_t *start = user_list;
    user_list_t *sub = malloc(sizeof(user_list_t));
    while (start != NULL && token != NULL) {
        if (strcmp(start->user->id, token) == 0) {
            sub->user = start->user;
            token = strtok(NULL, "¶\n");
            start = user_list;
            sub->next = fillUserInTeam(user_list, token);
            return sub;
        } else {
            start = start->next;
        }
    }
    return NULL;
}

team_t *getTeam(char *line, size_t len, FILE *file, user_list_t *user_l)
{
    team_t *team = malloc(sizeof(team_t));
    char *token = strtok(line, "¶\n");
    team->name = malloc(sizeof(char) * strlen(token) + 1);
    strcpy(team->name, token);
    token = strtok(NULL, "¶\n");
    team->description = malloc(sizeof(char) * strlen(token) + 1);
    strcpy(team->description, token);
    token = strtok(NULL, "¶\n");
    team->id = malloc(sizeof(char) * strlen(token) + 1);
    strcpy(team->id, token);
    token = strtok(NULL, "¶\n");
    if (token != NULL) {
        team->users = fillUserInTeam(user_l, token);
    } else {
        team->users = NULL;
    }
    if (getline(&line, &len, file) != -1 && strcmp(line, "CHANNEL\n") == 0) {
        team->channels = getChannelList(line, len, file);
    } else {
        team->channels = NULL;
    }
    return team;
}

team_t *getTeamList(char *line, size_t len, FILE *file, user_list_t *user_l)
{
    getline(&line, &len, file);
    team_t *team = getTeam(line, len, file, user_l);
    while (strcmp(line, "TEAM\n") == 0 && getline(&line, &len, file) != -1) {
        team_t *tmp = getTeam(line, len, file, user_l);
        team_t *tmp2 = team;
        while (tmp2->next != NULL) {
            tmp2 = tmp2->next;
        }
        tmp2->next = tmp;
    }
    return team;
}
