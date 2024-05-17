/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_new_team
*/

#include "logging_client.h"
#include "client.h"

void handle_new_team(char *str)
{
    char *team_description = get_resp_data_arg(str, '\a');
    char *team_name = get_resp_data_arg(str, '\a');
    char *team_uuid = str;

    client_event_team_created(
    team_uuid,
    team_name,
    team_description);
}
