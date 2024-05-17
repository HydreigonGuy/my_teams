##
## EPITECH PROJECT, 2022
## myteams
## File description:
## Makefile
##

all:
	@printf "\033[1;95m Making lib\n"
	@make -C ./lib/taya
	@printf "\033[1;32m DONE\n"
	make -C client
	make -C server
	cp client/myteams_cli .
	cp server/myteams_server .

clean:
	@printf "\033[1;31m cleanning lib\n"
	@make clean --silent -C ./lib/taya
	@printf "\033[1;32m DONE\n"
	make clean -C client
	make clean -C server

fclean:
	@printf "\033[1;31m cleanning lib binaries\n"
	@make fclean --silent -C ./lib/taya
	@printf "\033[1;32m DONE\n"
	make fclean -C client
	make fclean -C server
	rm -rf myteams_server myteams_cli

re:	fclean	all

.PHONY: all clean fclean re
