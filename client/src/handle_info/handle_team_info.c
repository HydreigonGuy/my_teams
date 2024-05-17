/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_team_info
*/

#include "logging_client.h"
#include "client.h"

void handle_team_info(char *str)
{
    char *team_description = get_resp_data_arg(str, '\a');
    char *team_uuid = get_resp_data_arg(str, '\a');
    char *team_name = str;

    client_print_team(
    team_uuid,
    team_name,
    team_description);
}
