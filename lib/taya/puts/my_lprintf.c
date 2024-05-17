/*
** EPITECH PROJECT, 2021
** B-CPE-210-TLS-2-1-stumper2-hakim.redjem
** File description:
** my_lprintf
*/

#include "taya.h"
#include <stdarg.h>
#include <unistd.h>

int check_flag(char *format, int index, va_list vargs)
{
    if (format[index] == '%') {
            switch (format[index + 1])
            {
            case 'd':
                my_putnbr(va_arg(vargs, int));
                break;
            case 's':
                my_putstr(va_arg(vargs, char *));
                break;
            case 'c':
                my_putchar(va_arg(vargs, int));
                break;
            }
            index++;
        }
        else
            write(1, &format[index], 1);
    return index;
}

void my_lprintf(char *format, ...)
{
    va_list vargs;

    if (!format)
        write(1, NULL, 0);
    va_start(vargs, format);
    for (int i = 0; format[i] != '\0'; i++){
        i = check_flag(format, i, vargs);
    }
    va_end(vargs);
}