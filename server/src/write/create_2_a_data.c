/*
** EPITECH PROJECT, 2022
** server
** File description:
** create_2_a_data
*/

#include <stdlib.h>
#include "taya.h"

char *create_2_a_data(char *s1, char *s2)
{
    char *ret = malloc(sizeof(char) * (my_strlen(s1) +
    my_strlen(s2) + 2));
    int c = 0;

    if (!ret)
        return (NULL);
    for (; s1[c]; ret[c] = s1[c], c++);
    ret[c] = '\a';
    c++;
    for (int i = 0; s2[i]; ret[c] = s2[i], c++, i++);
    ret[c] = '\0';
    return (ret);
}
