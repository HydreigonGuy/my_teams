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
        myputstr("USAGE: ./myteams_server port\n\n");
        myputstr("\tport is the port number on which the ");
        myputstr("server socket listens.\n");
        return (1);
    }
    return (0);
}
