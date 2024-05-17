##
## EPITECH PROJECT, 2021
## lib_Taya
## File description:
## Makefile
##

CC	=	gcc

CFLAGS	=	-W -Werror -Wpedantic -Wall -Wextra -I./include

SRC	=	int/my_getnbr.c	\
		int/my_isneg.c	\
		puts/my_putchar.c	\
		puts/my_putnbr.c	\
		puts/my_putnbr_unsigned.c	\
		puts/my_putoctal.c	\
		puts/my_puthexa.c	\
		puts/my_putuhexa.c	\
		puts/my_putstr.c	\
		puts/my_putstr_error.c	\
		puts/my_print_array.c	\
		puts/my_lprintf.c	\
		puts/myputstr.c \
		puts/myputstrerr.c \
		strings/my_revstr.c	\
		strings/my_str_isnum.c	\
		strings/my_strcmp.c	\
		strings/my_strlen.c	\
		strings/my_strupcase.c	\
		strings/my_strlowcase.c	\
		strings/my_strcpy.c	\
		strings/my_strncpy.c	\
		strings/my_strdup.c	\
		strings/my_strndup.c	\
		strings/my_swap.c	\
		strings/my_str_to_uint.c \
		strings/my_str_len.c \
		strings/mystrcmp.c	\
		arrays/my_str_to_word_array.c	\
		arrays/my_arraylen.c	\
		others/check_ip.c	\
		others/read_file.c

NAME	=	libtaya.a

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@cp $(NAME) ../
	@rm $(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)

auteur:
	@echo $(USER) > auteur

re:	fclean	all