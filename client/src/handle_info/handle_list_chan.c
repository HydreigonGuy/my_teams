/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_list_chan
*/

#include "logging_client.h"
#include "client.h"

void handle_list_chan(char *str)
{
    char *channel_description = get_resp_data_arg(str, '\a');
    char *channel_uuid = get_resp_data_arg(str, '\a');
    char *channel_name = str;

    client_team_print_channels(
    channel_uuid,
    channel_name,
    channel_description);
}
