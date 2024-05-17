/*
** EPITECH PROJECT, 2022
** B-NWP-400-TLS-4-1-myteams-adrien.thibault
** File description:
** stdin_handling_utilites
*/

#include <stddef.h>

char *get_command_arg(char *line)
{
    char *arg = NULL;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '"') {
            arg = &line[i + 1];
            break;
        }
    }
    for (int i = 0; arg && arg[i]; i++)
        if (arg[i] == '"') {
            arg[i] = '\0';
            return (arg);
        }
    return (NULL);
}

int is_command(char *line)
{
    if (line[0] == '/')
        return (1);
    return (0);
}
