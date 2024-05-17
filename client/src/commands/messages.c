/*
** EPITECH PROJECT, 2022
** B-NWP-400-TLS-4-1-myteams-adrien.thibault
** File description:
** messages
*/

#include <client.h>

void messages(my_client_t *client, char *user_uuid)
{
    create_response(client->write_buff, 363, user_uuid, "listing messages");
}
