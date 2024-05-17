/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_list_team
*/

#include "logging_client.h"
#include "client.h"

void handle_list_team(char *str)
{
    char *team_description = get_resp_data_arg(str, '\a');
    char *team_uuid = get_resp_data_arg(str, '\a');
    char *team_name = str;

    client_print_teams(
    team_uuid,
    team_name,
    team_description);
}
