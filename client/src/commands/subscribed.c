/*
** EPITECH PROJECT, 2022
** B-NWP-400-TLS-4-1-myteams-adrien.thibault
** File description:
** subscribed
*/

#include <client.h>

void subscribed(my_client_t *client, char *team_uuid)
{
    create_response(client->write_buff, 382, team_uuid,
    "requesting subscribed");
}
