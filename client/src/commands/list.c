/*
** EPITECH PROJECT, 2022
** B-NWP-400-TLS-4-1-myteams-adrien.thibault
** File description:
** list
*/

#include <client.h>
#include <stddef.h>

void list(my_client_t *client)
{
    create_response(client->write_buff, 384, NULL, "listing");
}
