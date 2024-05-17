/*
** EPITECH PROJECT, 2022
** client
** File description:
** main
*/

#include "client.h"

int main(int ac, char **av)
{
    if (handle_help(ac, av))
        return (0);
    if (ac != 3)
        return (84);
    return (handle_args(av[1], av[2]));
}
