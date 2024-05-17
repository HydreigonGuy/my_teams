/*
** EPITECH PROJECT, 2022
** server
** File description:
** create_2_comma_resp
*/

#include "server.h"
#include <stdlib.h>
#include "taya.h"

char *create_2_comma_resp(char *s1, char *s2)
{
    int len = my_strlen(s1) + my_strlen(s2) + 1;
    char *resp = malloc(sizeof(char) * (len + 1));
    int i = 0;

    if (!resp)
        return (NULL);
    for (; s1[i]; i++)
        resp[i] = s1[i];
    resp[i] = ',';
    i++;
    for (int j = 0; s2[j]; j++, i++)
        resp[i] = s2[j];
    resp[i] = '\0';
    return (resp);
}
