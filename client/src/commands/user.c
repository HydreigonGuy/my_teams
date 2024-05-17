/*
** EPITECH PROJECT, 2022
** B-NWP-400-TLS-4-1-myteams-adrien.thibault
** File description:
** user
*/

#include "client.h"
#include <string.h>

void user(my_client_t *client, char *user_uuid)
{
    create_response(client->write_buff, 381, user_uuid, "Requesting User");
}
