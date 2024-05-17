/*
** EPITECH PROJECT, 2022
** B-NWP-400-TLS-4-1-myteams-adrien.thibault
** File description:
** subscribe
*/

#include <client.h>

void subscribe(my_client_t *client, char *team_uuid)
{
    create_response(client->write_buff, 311, team_uuid, "subscribing");
}
