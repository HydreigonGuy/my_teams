/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_users
*/

#include "server.h"
#include "taya.h"

void fill_users_resp_data(char *data, user_t *user)
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

void send_user_list(connection_t *connect, user_t *user)
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
    fill_users_resp_data(data, user);
    create_response(connect->write_buff, 389, data, "Sent user info");
    free(data);
}

void send_users(connection_t *connect, user_list_t *users)
{
    for (user_list_t *user = users; user; user = user->next)
        send_user_list(connect, user->user);
}
