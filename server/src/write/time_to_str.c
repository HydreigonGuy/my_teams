/*
** EPITECH PROJECT, 2022
** server
** File description:
** time_to_str
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

char *time_to_str(time_t timestamp)
{
    char *str;
    size_t i = 0;
    long int tmp = timestamp;

    while (tmp > 0) {
        tmp /= 10;
        i++;
    }
    str = malloc(sizeof(char) * (i + 1));
    if (!str)
        return (NULL);
    sprintf(str, "%ld", timestamp);
    return str;
}
