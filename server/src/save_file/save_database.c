/*
** EPITECH PROJECT, 2022
** server
** File description:
** save_database
*/

#include "server.h"
#include <stdio.h>
#include <string.h>

void saveUsers(FILE *file, user_list_t *user_l)
{
    fprintf(file, "USERS");
    while (user_l != NULL) {
        fprintf(file, "\n%s¶%s", user_l->user->name,
            user_l->user->id);
            while (user_l->user->messages != NULL) {
                fprintf(file, "¶%s¶%s¶%ld",
                user_l->user->messages->userid,
                user_l->user->messages->body,
                user_l->user->messages->time);
                user_l->user->messages = user_l->user->messages->next;
            }
        user_l = user_l->next;
    }
}

void saveTeams(FILE *file, team_t *teams)
{
    while (teams != NULL) {
        fprintf(file, "TEAM");
        saveTeam(file, teams);
        if (teams->channels != NULL)
            saveChannel(file, teams->channels);
        teams = teams->next;
        if (teams != NULL)
            fprintf(file, "\n");
    }
}

void createDatabase(database_t *db)
{
    FILE *file = openFile("save.txt", "w");

    if (db->users != NULL) {
        saveUsers(file, db->users);
        if (db->teams != NULL)
            fprintf(file, "\n");
    }
    if (db->teams != NULL)
        saveTeams(file, db->teams);
    fclose(file);
}
