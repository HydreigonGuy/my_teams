/*
** EPITECH PROJECT, 2022
** client
** File description:
** handle_recieving_message
*/

#include "logging_client.h"
#include "client.h"

void handle_recieving_message(char *str)
{
    char *message_body = get_resp_data_arg(str, '\a');
    char *user_uuid = str;

    client_event_private_message_received(
    user_uuid,
    message_body);
}
