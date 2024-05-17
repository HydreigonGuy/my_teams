/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_message
*/

#include "server.h"
#include "taya.h"
#include "logging_server.h"

void send_message(connection_t *con, user_list_t *users, char *data,
connection_t *all)
{
    char *user_id = get_sep_a_arg(data, 0);
    char *body = get_sep_a_arg(data, 1);
    user_t *user = NULL;

    if (!user_id || !body) {
        create_response(con->write_buff, 406, NULL, "Arg error");
        return;
    }
    user = get_user_by_id(user_id, users);
    if (!user) {
        create_response(con->write_buff, 406, NULL, "Arg error");
        return;
    }
    create_message(user, con->user->id, body);
    create_response(con->write_buff, 361, NULL, "Message sent successfully");
    for (connection_t *curr = all; curr; curr = curr->next)
        if (curr->user && mystrcmp(user->id, curr->user->id))
            create_response(curr->write_buff, 362,
            create_2_a_data(con->user->id, body), "Message recieved");
    server_event_private_message_sended(con->user->id, user->id, body);
}
