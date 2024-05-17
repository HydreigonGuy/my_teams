/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_chan_info
*/

#include "logging_client.h"
#include "client.h"

void handle_chan_info(char *str)
{
    char *channel_description = get_resp_data_arg(str, '\a');
    char *channel_uuid = get_resp_data_arg(str, '\a');
    char *channel_name = str;

    client_print_channel(
    channel_uuid,
    channel_name,
    channel_description);
}
