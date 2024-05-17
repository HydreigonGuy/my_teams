/*
** EPITECH PROJECT, 2022
** B-NWP-400-TLS-4-1-myteams-adrien.thibault
** File description:
** check_ip
*/

#include <arpa/inet.h>

int check_ip(char *ip)
{
    struct sockaddr_in in;

    return !inet_pton(AF_INET, ip, &in.sin_addr);
}