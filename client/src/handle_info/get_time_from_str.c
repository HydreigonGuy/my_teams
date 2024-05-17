/*
** EPITECH PROJECT, 2022
** client
** File description:
** get_time_from_str
*/

#include "time.h"
#include <stdlib.h>
#include <stdio.h>

time_t get_time_from_str(char *str)
{
    time_t timestamp = 0;

    timestamp = atol(str);
    return timestamp;
}
