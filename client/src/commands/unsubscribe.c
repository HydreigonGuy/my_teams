/*
** EPITECH PROJECT, 2022
** B-NWP-400-TLS-4-1-myteams-adrien.thibault
** File description:
** unsubscribe
*/

#include <client.h>

void unsubscribe(my_client_t *client, char *team_uuid)
{
    create_response(client->write_buff, 312, team_uuid, "unsubscribing");
}
