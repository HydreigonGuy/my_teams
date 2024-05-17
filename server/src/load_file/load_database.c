/*
** EPITECH PROJECT, 2022
** server
** File description:
** load database
*/

#include "server.h"
#include <stdio.h>
#include <string.h>

FILE *openFile(char *fileName, char *mode)
{
    FILE *file = fopen(fileName, mode);

    return file;
}

database_t *loadDatabase(void)
{
    FILE *file = openFile("save.txt", "r");
    char *line = NULL;
    size_t len = 0;
    database_t *database = malloc(sizeof(database_t));

    if (!database)
        return (NULL);
    database->users = NULL;
    database->teams = NULL;
    if (!file)
        return (database);
    getline(&line, &len, file);
    if (strcmp(line, "USERS\n") == 0)
        database->users = getUserList(line, len, file);
    if (strcmp(line, "TEAM\n") == 0)
        database->teams = getTeamList(line, len, file, database->users);
    fclose(file);
    return database;
}
