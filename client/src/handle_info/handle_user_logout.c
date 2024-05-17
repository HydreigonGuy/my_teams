/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_user_logout
*/

#include "logging_client.h"
#include "client.h"

void handle_user_logout(char *str)
{
    char *user_uuid = get_resp_data_arg(str, ',');
    char *user_name = get_resp_data_arg(str, ',');

    client_event_logged_out(user_uuid, user_name);
}
