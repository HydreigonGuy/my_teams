##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## My own Makefile <3
##

cc	=	gcc

#	VARIABLES	#

DEFAULT		=	"\033[00m"
GREEN		=	"\033[1;32m"
CYAN		=	"\033[1;36m"
YELLOW		=	"\033[1;184m"
MAGENTA		=	"\033[1;95m"
RED			=	"\033[1;31m"

#	SOURCES	#

SRC		=	server_settup/bind_server.c	\
			server_settup/fill_server_info.c	\
			server_settup/make_server_listen.c	\
			server_settup/start_server.c	\
			accept_connection/destroy_buffer.c	\
			select/set_all_unready.c	\
			select/check_select.c	\
			select/get_select_num.c	\
			select/set_status.c	\
			accept_connection/accept_connection.c	\
			accept_connection/create_connection.c	\
			accept_connection/handle_accept.c	\
			accept_connection/create_new_path.c	\
			accept_connection/create_buffer.c	\
			end/handle_connection_ends.c	\
			end/close_connection.c	\
			end/destroy_connections.c	\
			write/create_response.c	\
			write/send_response.c	\
			write/write_on_socket.c	\
			write/message_everyone.c	\
			write/create_2_comma_resp.c	\
			write/create_2_a_data.c	\
			write/create_3_a_data.c	\
			write/create_4_a_data.c	\
			write/message_subed.c	\
			write/time_to_str.c	\
			read/read_message.c	\
			read/read_socket.c	\
			commands/login.c	\
			commands/logout_user.c	\
			commands/change_path.c	\
			commands/handle_wrong_path_change.c	\
			commands/subscribe.c	\
			commands/unsubscribe.c	\
			commands/create.c	\
			commands/send_user.c	\
			commands/send_users.c	\
			commands/send_team_info.c	\
			commands/send_chan_info.c	\
			commands/send_thread_info.c	\
			commands/send_teams_info.c	\
			commands/send_chans_info.c	\
			commands/send_threads_info.c	\
			commands/send_comment_info.c	\
			commands/send_sebscribed.c	\
			commands/send_path_info.c	\
			commands/send_path_list.c	\
			commands/send_message.c	\
			commands/send_user_messages.c	\
			get_data/get_user_by_id.c	 \
			get_data/get_users_str.c	\
			get_data/get_user_id.c	\
			get_data/get_team_by_id.c	\
			get_data/get_team_by_name.c	\
			get_data/get_chan_by_name.c	\
			create_data/fill_server_data.c	\
			create_data/create_user.c	\
			create_data/create_id.c	\
			create_data/create_new_team.c	\
			create_data/create_new_chan.c	\
			create_data/create_new_thread.c	\
			create_data/create_new_comment.c	\
			create_data/get_sep_a_arg.c	\
			create_data/create_message.c	\
			handle_responses/handle_responses.c	\
			handle_responses/remove_resp_from_buffer.c	\
			handle_responses/fill_response.c	\
			handle_responses/extract_response_info.c	\
			handle_responses/execute_response.c	\
			handle_stdin/handle_stdin.c	\
			load_file/load_database.c	\
			load_file/load_teams.c   \
			load_file/load_threads.c	\
			load_file/load_users.c	\
			save_file/save_database.c	\
			save_file/save_teams.c	\
			destroy/destroy_user.c	\
			destroy/destroy_user_list.c	\
			destroy/destroy_comments.c	\
			destroy/destroy_threads.c	\
			destroy/destroy_channels.c	\
			destroy/destroy_teams.c	\
			destroy/destroy_database.c	\
			close_server.c	\
			run_server.c	\
			handle_args.c	\
			handle_help.c	\
			main.c

TESTS_SRC	=

$(eval SRC = $(addprefix src/, $(SRC)))

#	OBJECTS	#

OBJ	=	$(SRC:.c=.o)

TESTS_OBJ	=	$(TESTS_SRC:.c=.o)

#	NAME	#

NAME	=	myteams_server

TESTS_NAME	=	unit_tests

#	FLAGS	#

CFLAGS	=	-W -Wpedantic -Wall -Wextra -fno-builtin -I./include/ -L../lib/ -ltaya -luuid -lmyteams

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
	@gcc -o $(TESTS_NAME) $(OBJ) $(TESTS_OBJ) $(TESTS_FLAGS)
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
