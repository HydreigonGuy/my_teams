/*
** EPITECH PROJECT, 2022
** lib
** File description:
** myputstr
*/

#include <unistd.h>

void myputstr(char *str)
{
    for (int i = 0; str[i]; i++)
        write(1, &str[i], 1);
}