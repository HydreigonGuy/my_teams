/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** taya
*/

#ifndef TAYA_H_
    #define TAYA_H_

    /* INTS */
    int my_getnbr(char const *str);
    int my_isneg(int n);

    /* PUTS */
    void my_putchar(char c);
    void my_putnbr(int nb);
    void my_putnbr_unsigned(unsigned int nb);
    void my_putoctal(int nb);
    void my_puthexa(int nb, int capital);
    void my_putuhexa(unsigned int nb, int capital);
    int my_putstr(char const *str);
    int my_putstr_error(char const *str);
    void my_print_array(char **array);
    void my_lprintf(char *format, ...);
    void myputstr(char *str);
    void myputstrerr(char *str);

    /* STRINGS */
    char *my_revstr(char *str);
    int my_str_isnum(char const *str);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strcpy(char *dest, char const *src);
    char *my_strncpy(char *dest, char const *src, int n);
    int my_strlen(char const *str);
    char *my_strupcase(char *str);
    char *my_strlowcase(char *str);
    void my_swap(int *a, int *b);
    char *my_strndup(char const *str, int n);
    char *my_strdup(char const *str);
    int mystrcmp(char *s1, char *s2);
    int my_str_to_uint(char *str);
    int my_str_len(char *str);

    /* ARRAYS */
    char **my_str_to_word_array(char *str, char c);
    void my_free_word_array(char **array);
    int my_arraylen(char **array);

    /* OTHERS */
    char *read_file(char *file_name);
    int check_ip(char *ip);

#endif /* !TAYA_H_ */
