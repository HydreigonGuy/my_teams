/*
** EPITECH PROJECT, 2022
** B-NWP-400-TLS-4-1-myteams-adrien.thibault
** File description:
** info
*/

#include <client.h>
#include <stddef.h>

void info(my_client_t *client)
{
    create_response(client->write_buff, 383, NULL, "getting infos");
}
