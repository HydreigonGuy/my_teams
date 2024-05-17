/*
** EPITECH PROJECT, 2022
** server
** File description:
** handle_stdin
*/

#include "server.h"
#include <stddef.h>
#include <stdio.h>
#include "taya.h"

int handle_stdin(my_server_t *server)
{
    char *line = NULL;
    size_t len = 0;

    if (!server->stdin_ready)
        return (0);
    getline(&line, &len, stdin);
    if (mystrcmp(line, "exit\n"))
        return (1);
    return (0);
}
