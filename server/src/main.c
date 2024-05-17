/*
** EPITECH PROJECT, 2022
** server
** File description:
** main
*/

#include "server.h"

int main(int ac, char **av)
{
    if (handle_help(ac, av))
        return (0);
    if (ac != 2)
        return (84);
    return (handle_args(av[1]));
}
