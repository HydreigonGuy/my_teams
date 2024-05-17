/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_user_info
*/

#include "logging_client.h"
#include "client.h"

void handle_user_info(char *data)
{
    char *status = get_resp_data_arg(data, '\a');
    char *user_uuid = get_resp_data_arg(data, '\a');
    char *user_name = data;
    int user_status = 0;

    if (status[0] == '1')
        user_status = 1;
    client_print_user(
    user_uuid,
    user_name,
    user_status);
}
