/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_stdin
*/

#include "taya.h"
#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include <string.h>

static void check_other_commands(char *line, my_client_t *client)
{
    if (strstr(line, "/subscribe ") != NULL)
        subscribe(client, get_command_arg(line));
    if (strstr(line, "/subscribed") != NULL)
        subscribed(client, get_command_arg(line));
    if (strstr(line, "/unsubscribe") != NULL)
        unsubscribe(client, get_command_arg(line));
    if (mystrcmp(line, "/list\n"))
        list(client);
    if (mystrcmp(line, "/info\n"))
        info(client);
    if (strstr(line, "/create") != NULL)
        create(client, line);
    if (strstr(line, "/use ") != NULL || mystrcmp(line, "/use\n"))
        use(client, line);
}

static void check_commands(char *line, my_client_t *client)
{
    if (strstr(line, "/login") != NULL)
        login(client, get_command_arg(line));
    if (mystrcmp(line, "/logout\n"))
        logout(client);
    if (mystrcmp(line, "/help\n"))
        help();
    if (mystrcmp(line, "/users\n"))
        users(client);
    if (strstr(line, "/user ") != NULL)
        user(client, get_command_arg(line));
    if (strstr(line, "/send") != NULL)
        command_send(client, line);
    if (strstr(line, "/messages") != NULL)
        messages(client, get_command_arg(line));
    check_other_commands(line, client);
}

void handle_stdin(my_client_t *client)
{
    char *line = NULL;
    size_t len = 0;

    if (!client->stdin->status == READ || !client->stdin->ready)
        return;
    getline(&line, &len, stdin);
    if (!is_command(line))
        printf("%s\n", "Command not found");
    else
        check_commands(line, client);
}
