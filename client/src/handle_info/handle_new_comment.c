/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_new_comment
*/

#include "logging_client.h"
#include "client.h"

void handle_new_comment(char *str)
{
    char *reply_body = get_resp_data_arg(str, '\a');
    char *user_uuid = get_resp_data_arg(str, '\a');
    char *thread_uuid = get_resp_data_arg(str, '\a');
    char *team_uuid = str;

    client_event_thread_reply_received(
    team_uuid,
    thread_uuid,
    user_uuid,
    reply_body);
}
