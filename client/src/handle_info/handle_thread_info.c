/*
** EPITECH PROJECT, 2022
** clinet
** File description:
** handle_thread_info
*/

#include "logging_client.h"
#include "client.h"

void handle_thread_info(char *str)
{
    char *time = get_resp_data_arg(str, '\a');
    char *user_uuid = get_resp_data_arg(str, '\a');
    char *thread_body = get_resp_data_arg(str, '\a');
    char *thread_uuid = get_resp_data_arg(str, '\a');
    char *thread_title = str;
    time_t thread_timestamp = get_time_from_str(time);

    client_print_thread(
    thread_uuid,
    user_uuid,
    thread_timestamp,
    thread_title,
    thread_body);
}
