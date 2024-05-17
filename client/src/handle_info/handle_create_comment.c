/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_create_comment
*/

#include "logging_client.h"
#include "client.h"

void handle_create_comment(char *str)
{
    char *time = get_resp_data_arg(str, '\a');
    char *reply_body = get_resp_data_arg(str, '\a');
    char *user_uuid = get_resp_data_arg(str, '\a');
    char *thread_uuid = str;
    time_t reply_timestamp = get_time_from_str(time);

    client_print_reply_created(
    thread_uuid,
    user_uuid,
    reply_timestamp,
    reply_body);
}
