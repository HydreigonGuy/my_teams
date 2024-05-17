/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_new_thread
*/

#include "logging_client.h"
#include "client.h"

void handle_new_thread(char *str)
{
    char *time = get_resp_data_arg(str, '\a');
    char *user_uuid = get_resp_data_arg(str, '\a');
    char *thread_body = get_resp_data_arg(str, '\a');
    char *thread_title = get_resp_data_arg(str, '\a');
    char *thread_uuid = str;
    time_t thread_timestamp = get_time_from_str(time);

    client_event_thread_created(
    thread_uuid,
    user_uuid,
    thread_timestamp,
    thread_title,
    thread_body);
}
