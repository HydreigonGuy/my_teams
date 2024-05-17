/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_user_unsubscribe
*/

#include "logging_client.h"
#include "client.h"

void handle_user_unsubscribe(char *str)
{
    char *team_uuid = get_resp_data_arg(str, ',');
    char *user_uuid = str;

    client_print_unsubscribed(user_uuid, team_uuid);
}
