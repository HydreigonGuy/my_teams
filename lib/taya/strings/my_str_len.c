/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** my_str_len
*/

int my_str_len(char *str)
{
    int ret = 0;

    for (; str[ret]; ret++);
    return (ret);
}