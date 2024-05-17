/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_team_info
*/

#include "server.h"
#include "taya.h"
#include <stdlib.h>

void fill_team_resp_data(char *data, team_t *team)
{
    int c = 0;

    for (; team->name[c]; c++)
        data[c] = team->name[c];
    data[c] = '\a';
    c++;
    for (int i = 0; team->id[i]; i++, c++)
        data[c] = team->id[i];
    data[c] = '\a';
    c++;
    for (int i = 0; team->description[i]; i++, c++)
        data[c] = team->description[i];
    data[c] = '\0';
}

void send_team_info(connection_t *con, team_t *team)
{
    char *data = NULL;

    if (!team) {
        create_response(con->write_buff, 406, NULL, "Bad argument(s)");
        return;
    }
    data = malloc(sizeof(char) * (my_strlen(team->name) +
    my_strlen(team->id) + my_strlen(team->description) + 3));
    if (!data)
        return;
    fill_team_resp_data(data, team);
    create_response(con->write_buff, 391, data, "Sent teams info");
    free(data);
}
