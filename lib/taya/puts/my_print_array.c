/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_print_array
*/

#include "taya.h"
#include <stddef.h>

void my_print_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        if (i != 0)
            my_putchar('\n');
        my_putstr(array[i]);
    }
}