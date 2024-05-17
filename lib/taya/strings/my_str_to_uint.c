/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_str_to_uint
*/

int my_str_to_uint(char *str)
{
    int ret = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (-1);
        ret = ret * 10 + str[i] - '0';
    }
    return (ret);
}