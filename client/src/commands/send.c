/*
** EPITECH PROJECT, 2022
** B-NWP-400-TLS-4-1-myteams-adrien.thibault
** File description:
** send
*/

#include <client.h>
#include <stdio.h>
#include "taya.h"

static int create_send_resp_data(char *line, int c)
{
    if ((line[c + 1] != ' ' && line[c + 1] != '\t') || line[c + 2] != '"')
        return (0);
    line[c] = '\a';
    c++;
    for (; line[c + 2]; c++)
        line[c] = line[c + 2];
    for (int i = 0; line && line[i]; i++)
        if (line[i] == '"') {
            line[i] = '\0';
            return (1);
        }
    return (0);
}

void command_send(my_client_t *client, char *line)
{
    int c = 0;

    for (; line[0] && line[0] != '"'; line = &line[1]);
    if (!line) {
        printf("Missing or bad format arguments\n");
        return;
    }
    line = &line[1];
    for (; line[c] && line[c] != '"'; c++);
    if (!line[c]) {
        printf("Missing or bad format arguments\n");
        return;
    }
    if (!create_send_resp_data(line, c))
        printf("Missing or bad format arguments\n");
    else
        create_response(client->write_buff, 360, line, "sending message");
}
