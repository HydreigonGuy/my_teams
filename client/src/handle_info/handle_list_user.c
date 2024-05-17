/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_list_user
*/

#include "logging_client.h"
#include "client.h"

void handle_list_user(char *str)
{
    char *status = get_resp_data_arg(str, '\a');
    char *user_uuid = get_resp_data_arg(str, '\a');
    char *user_name = str;
    int user_status = 0;

    if (status[0] == '1')
        user_status = 1;
    client_print_users(
    user_uuid,
    user_name,
    user_status);
}
