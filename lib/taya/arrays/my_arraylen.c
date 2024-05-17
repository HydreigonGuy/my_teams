/*
** EPITECH PROJECT, 2021
** B-PSU-200-TLS-2-1-mysokoban-hakim.redjem
** File description:
** my_arraylen
*/

#include <stddef.h>

int my_arraylen(char **array)
{
    int len = 0;

    for (; array[len] != NULL; len++);
    return len;
}