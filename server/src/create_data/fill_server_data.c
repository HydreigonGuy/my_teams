/*
** EPITECH PROJECT, 2022
** server
** File description:
** fill_server_data
*/

#include "server.h"
#include <stdlib.h>

database_t *fill_server_data(void)
{
    return (loadDatabase());
}
