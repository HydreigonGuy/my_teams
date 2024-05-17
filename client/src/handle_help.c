/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** handle_help
*/

#include "taya.h"

int handle_help(int ac, char **av)
{
    if (ac == 2 && mystrcmp(av[1], "-help")) {
        myputstr("USAGE: ./myteams_cli ip port\n");
        myputstr("\tip is the server ip address on which ");
        myputstr("the server socket listens\n");
        myputstr("\tport is the port number on which ");
        myputstr("the server socket listen\n");
        return (1);
    }
    return (0);
}
