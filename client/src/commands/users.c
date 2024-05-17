/*
** EPITECH PROJECT, 2022
** B-NWP-400-TLS-4-1-myteams-adrien.thibault
** File description:
** users
*/

#include "client.h"
#include <stddef.h>

void users(my_client_t *client)
{
    create_response(client->write_buff, 380, NULL, "listing the users..");
}
