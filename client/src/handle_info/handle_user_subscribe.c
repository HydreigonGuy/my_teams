/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_user_subscribe
*/

#include "logging_client.h"
#include "client.h"

void handle_user_subscribe(char *str)
{
    char *team_uuid = get_resp_data_arg(str, ',');
    char *user_uuid = str;

    client_print_subscribed(user_uuid, team_uuid);
}
