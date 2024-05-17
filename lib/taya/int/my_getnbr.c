/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    if (str[i] == '-') {
        neg = -1;
        i = 1;
    }
    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            nb = nb * 10 + (str[i] - '0');
    }
    return (nb * neg);
}