/*
** EPITECH PROJECT, 2022
** server
** File description:
** login
*/

#include "server.h"
#include <stdlib.h>
#include "taya.h"
#include "logging_server.h"

void login(char *name, my_server_t *serv, connection_t *con,
connection_t *all)
{
    char *id = get_user_id(name, &serv->data->users);
    user_t *user = get_user_by_id(id, serv->data->users);
    char *data = get_users_str(user);

    if (!id || !data || !user) {
        if (id)
            free(id);
        if (data)
            free(data);
        if (user)
            free(user);
        create_response(con->write_buff, 406, NULL, "Bad argument(s)");
        return;
    }
    con->user = user;
    user->connections++;
    message_everyone(all, 301, data, "A user has logged in");
    server_event_user_logged_in(user->id);
    free(data);
}
