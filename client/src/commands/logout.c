/*
** EPITECH PROJECT, 2022
** client
** File description:
** logout
*/

#include "client.h"
#include <stddef.h>

void logout(my_client_t *client)
{
    create_response(client->write_buff, 225, NULL, "Disconnecting");
    client->shutdown = 1;
}
