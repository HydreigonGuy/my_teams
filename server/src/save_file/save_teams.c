/*
** EPITECH PROJECT, 2022
** server
** File description:
** save_database
*/

#include "server.h"
#include <stdio.h>
#include <string.h>

void saveComments(FILE *file, comment_t *comment_l)
{
    while (comment_l != NULL) {
        fprintf(file, "%s¶%s¶%ld¶%s", comment_l->body,
            comment_l->id, comment_l->time, comment_l->user_id);
        comment_l = comment_l->next;
        if (comment_l != NULL)
            fprintf(file, "¶");
    }
}

void saveThread(FILE *file, thread_t *thread)
{
    fprintf(file, "\nTHREAD");
    while (thread != NULL) {
        fprintf(file, "\n%s¶%s¶%s¶%ld¶%s",
            thread->title,
            thread->message,
            thread->id,
            thread->time,
            thread->user_id);
        if (thread->comments != NULL) {
            fprintf(file, "\n");
            saveComments(file, thread->comments);
        }
        thread = thread->next;
    }
}

void saveChannel(FILE *file, channel_t *chan)
{
    while (chan != NULL) {
        fprintf(file, "\nCHANNEL");
        fprintf(file, "\n%s¶%s¶%s",
            chan->name,
            chan->description,
            chan->id);
        if (chan->threads != NULL) {
            saveThread(file, chan->threads);
        }
        chan = chan->next;
    }
}

void saveTeam(FILE *file, team_t *team)
{
    fprintf(file, "\n%s¶%s¶%s", team->name,
        team->description, team->id);
    if (team->users != NULL) {
        while (team->users != NULL) {
            fprintf(file, "¶%s", team->users->user->id);
            team->users = team->users->next;
        }
    }
}
