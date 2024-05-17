##
## EPITECH PROJECT, 2022
## B-NWP-400-TLS-4-1-myteams-adrien.thibault
## File description:
## Makefile
##

CC	=	gcc

#	VARIABLES	#

DEFAULT		=	"\033[00m"
GREEN		=	"\033[1;32m"
CYAN		=	"\033[1;36m"
YELLOW		=	"\033[1;184m"
MAGENTA		=	"\033[1;95m"
RED			=	"\033[1;31m"

#	SOURCES	#

SRC =	settup/start_client.c	\
		settup/fill_client_info.c	\
		settup/destroy_buffer.c	\
		settup/create_buffer.c	\
		settup/destroy_client.c	\
		select/check_select.c	\
		select/set_status.c	\
		read/read_message.c	\
		write/send_response.c	\
		write/create_response.c	\
		handle_responses/handle_responses.c	\
		handle_responses/fill_response.c	\
		handle_responses/remove_resp_from_buffer.c	\
		handle_responses/extract_response_info.c	\
		handle_responses/execute_response.c	\
		handle_responses/get_resp_data_arg.c	\
		handle_info/handle_user_info.c	\
		handle_info/handle_user_unsubscribe.c	\
		handle_info/handle_user_subscribe.c	\
		handle_info/handle_new_comment.c	\
		handle_info/handle_new_thread.c	\
		handle_info/handle_new_chan.c	\
		handle_info/handle_new_team.c	\
		handle_info/handle_user_login.c	\
		handle_info/handle_user_logout.c	\
		handle_info/handle_recieving_message.c	\
		handle_info/handle_list_team.c	\
		handle_info/handle_list_chan.c	\
		handle_info/get_time_from_str.c	\
		handle_info/handle_list_thread.c	\
		handle_info/handle_list_comment.c	\
		handle_info/handle_list_user.c	\
		handle_info/handle_team_info.c	\
		handle_info/handle_chan_info.c	\
		handle_info/handle_thread_info.c	\
		handle_info/handle_create_team.c	\
		handle_info/handle_create_chan.c	\
		handle_info/handle_create_thread.c	\
		handle_info/handle_create_comment.c	\
		stdin/handle_stdin.c	\
		stdin/stdin_handling_utilities.c	\
		commands/help.c	\
		commands/login.c	\
		commands/logout.c	\
		commands/users.c	\
		commands/user.c	\
		commands/send.c	\
		commands/messages.c	\
		commands/subscribe.c	\
		commands/subscribed.c	\
		commands/unsubscribe.c	\
		commands/use.c	\
		commands/create.c	\
		commands/list.c	\
		commands/info.c	\
		run_client.c	\
		handle_args.c	\
		handle_help.c	\
		main.c


TESTS_SRC	=

$(eval SRC = $(addprefix src/, $(SRC)))

#	OBJECTS	#

OBJ	=	$(SRC:.c=.o)

TESTS_OBJ	=	$(TESTS_SRC:.c=.o)

#	NAME	#

NAME	=	myteams_cli

TESTS_NAME	=	unit_tests

#	FLAGS	#

CFLAGS	= -W -Wpedantic -Wall -Wextra -fno-builtin -I./include/ -L../lib/ -ltaya -lmyteams

TESTS_FLAGS	=	--coverage -lcriterion


#	RULES	#

all:	$(NAME)

$(NAME):	$(OBJ)
	@printf "\033[1;36m Compiling .C\n"
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

tests_run: $(OBJ)	$(TESTS_OBJ)
	@printf "\033[1;36m Compiling .C\n"
	@$(CC) -o $(TESTS_NAME) $(OBJ) $(TESTS_OBJ) $(TESTS_FLAGS)
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

clean:
	@printf "\033[1;31m Cleanning .o\n"
	@rm -f $(OBJ) $(TESTS_OBJ)
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

fclean: clean
	@printf "\033[1;31m Cleanning binaries\n"
	@rm -f $(NAME) $(TESTS_NAME)
	@printf "\033[1;32m DONE\n"
	@printf "\033[1;31m cleanning vgcore\n"
	@rm -f vgcore.*
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

re:	fclean	all
	@printf "\033[1;32m REBULDING DONE\n"
	@printf "\033[00m"

#	END		-Made by VulkreoN	#
