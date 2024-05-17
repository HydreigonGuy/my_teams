/*
** EPITECH PROJECT, 2022
** client
** File description:
** get_resp_data_arg
*/

char *get_resp_data_arg(char *str, char split)
{
    int c = 0;

    for (; str[c]; c++);
    for (; c > 0 && str[c] != split; c--);
    if (c == 0)
        return (str);
    str[c] = '\0';
    return (&str[c + 1]);
}
