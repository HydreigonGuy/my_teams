/*
** EPITECH PROJECT, 2022
** lib
** File description:
** myputstrerr
*/

#include <unistd.h>

void myputstrerr(char *str)
{
    for (int i = 0; str[i]; i++)
        write(2, &str[i], 1);
}