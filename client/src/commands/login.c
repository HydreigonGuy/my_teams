/*
** EPITECH PROJECT, 2022
** client
** File description:
** login
*/

#include "client.h"

void login(my_client_t *client, char *username)
{
    create_response(client->write_buff, 300, username, "Logging in");
}
