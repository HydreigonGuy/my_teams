/*
** EPITECH PROJECT, 2022
** lib
** File description:
** mystrcmp
*/

int mystrcmp(char *s1, char *s2)
{
    int c = 0;

    for (; s1[c] && s2[c] && s1[c] == s2[c]; c++);
    if (s1[c] || s2[c])
        return (0);
    return (1);
}