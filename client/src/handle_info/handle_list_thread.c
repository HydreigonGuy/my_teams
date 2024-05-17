/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_list_thread
*/

#include "logging_client.h"
#include "client.h"

void handle_list_thread(char *str)
{
    char *time = get_resp_data_arg(str, '\a');
    char *user_uuid = get_resp_data_arg(str, '\a');
    char *thread_body = get_resp_data_arg(str, '\a');
    char *thread_uuid = get_resp_data_arg(str, '\a');
    char *thread_title = str;
    time_t thread_timestamp = get_time_from_str(time);

    client_channel_print_threads(
    thread_uuid,
    user_uuid,
    thread_timestamp,
    thread_title,
    thread_body);
}
