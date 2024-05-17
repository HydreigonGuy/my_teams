/*
** EPITECH PROJECT, 2022
** server
** File description:
** message_subed
*/

#include "server.h"

void add_message_to_sub_resp(connection_t *con, int code, char *data)
{
    if (code == 250)
        create_response(con->write_buff, code, data, "User subscribed");
    if (code == 251)
        create_response(con->write_buff, code, data, "User unsubscribed");
    if (code == 352)
        create_response(con->write_buff, code, data, "New chan created");
    if (code == 353)
        create_response(con->write_buff, code, data, "New thread created");
    if (code == 354)
        create_response(con->write_buff, code, data, "New Comment created");
}

void message_subed(connection_t *con, team_t *team, int code, char *data)
{
    for (connection_t *curr = con; curr; curr = curr->next)
        if (curr->user && get_user_by_id(curr->user->id, team->users))
            add_message_to_sub_resp(curr, code, data);
}
