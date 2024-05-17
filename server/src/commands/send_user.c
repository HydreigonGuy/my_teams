/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_user
*/

#include "server.h"
#include "taya.h"
#include <stdlib.h>

void fill_user_resp_data(char *data, user_t *user)
{
    int c = 0;

    for (; user->name[c]; c++)
        data[c] = user->name[c];
    data[c] = '\a';
    c++;
    for (int i = 0; user->id[i]; i++, c++)
        data[c] = user->id[i];
    data[c] = '\a';
    c++;
    if (user->connections > 0)
        data[c] = '1';
    else
        data[c] = '0';
    c++;
    data[c] = '\0';
}

void send_user(connection_t *connect, user_t *user)
{
    char *data = NULL;

    if (!user) {
        create_response(connect->write_buff, 406, NULL, "Bad argument(s)");
        return;
    }
    data = malloc(sizeof(char) * (my_strlen(user->name) +
    my_strlen(user->id) + 4));
    if (!data)
        return;
    fill_user_resp_data(data, user);
    create_response(connect->write_buff, 390, data, "Sent user info");
    free(data);
}
