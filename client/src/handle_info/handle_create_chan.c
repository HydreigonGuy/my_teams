/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_create_chan
*/

#include "logging_client.h"
#include "client.h"

void handle_create_chan(char *str)
{
    char *channel_description = get_resp_data_arg(str, '\a');
    char *channel_name = get_resp_data_arg(str, '\a');
    char *channel_uuid = str;

    client_print_channel_created(
    channel_uuid,
    channel_name,
    channel_description);
}
