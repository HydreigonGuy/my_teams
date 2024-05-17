/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_list_comment
*/

#include "logging_client.h"
#include "client.h"

void handle_list_comment(char *str)
{
    char *time = get_resp_data_arg(str, '\a');
    char *user_uuid = get_resp_data_arg(str, '\a');
    char *reply_body = get_resp_data_arg(str, '\a');
    char *thread_uuid = get_resp_data_arg(str, '\a');
    time_t reply_timestamp = get_time_from_str(time);

    client_thread_print_replies(
    thread_uuid,
    user_uuid,
    reply_timestamp,
    reply_body);
}
