/*
** EPITECH PROJECT, 2022
** B-NWP-400-TLS-4-1-myteams-adrien.thibault
** File description:
** use
*/

#include <client.h>
#include <stdio.h>

static int create_use_resp_data1(char *line, int c)
{
    if ((line[c + 1] != ' ' && line[c + 1] != '\t') || line[c + 2] != '"')
        return (0);
    line[c] = ',';
    c++;
    for (; line[c + 2]; c++)
        line[c] = line[c + 2];
    for (int i = 0; line && line[i]; i++)
        if (line[i] == '"') {
            return (1);
        }
    return (0);
}

static int create_use_resp_data2(char *line, int c)
{
    for (; line[c] && line[c + 1] && line[c] != '"'; c++);
    if ((line[c + 1] != ' ' && line[c + 1] != '\t') || line[c + 2] != '"')
        return (0);
    line[c] = ',';
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

static void add_use_arg_end(char *line)
{
    for (int i = 0; line && line[i]; i++)
        if (line[i] == '"') {
            line[i] = '\0';
            return;
        }
}

void use(my_client_t *client, char *line)
{
    int c = 0;

    for (; line[0] && line[0] != '"'; line = &line[1]);
    if (!line[0]) {
        create_response(client->write_buff, 310, line, "changing context");
        return;
    }
    line = &line[1];
    for (; line[c] && line[c] != '"'; c++);
    if (!line[c]) {
        printf("Missing or bad format arguments\n");
        return;
    }
    if (!create_use_resp_data1(line, c))
        line[c] = '\0';
    if (line[c] != '\0' && !create_use_resp_data2(line, c))
        add_use_arg_end(line);
    create_response(client->write_buff, 310, line, "changing context");
}
