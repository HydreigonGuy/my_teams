/*
** EPITECH PROJECT, 2022
** server
** File description:
** logout_user
*/

#include "server.h"
#include <stddef.h>
#include "logging_server.h"

void logout_user(connection_t *connect, connection_t *all)
{
    char *data = NULL;

    connect->status = SHUTDOWN;
    if (connect->user) {
        server_event_user_logged_out(connect->user->id);
        data = create_2_comma_resp(connect->user->name, connect->user->id);
        if (!data)
            return;
        message_everyone(all, 226, data, "User disconnected");
    }
}
