/*
** EPITECH PROJECT, 2022
** client
** File description:
** help
*/

#include <stdio.h>

static void print_info_help(void)
{
    printf("/INFO\n When the context is not defined (/use)\n\
    /info : display currently logged user infos\n\
    When team_uuid is defined (/use team_uuid)\n\
    /info : display currently selected team infos\n\
    When channel_uuid is defined (/use team_uuid channel_uuid)\n\
    /info : display currently selected channel infos\n\
    When thread is defined (/use team_uuid channel_uuid thread_uuid)\n\
    /info : display currently selected thread infos\n");
}

static void print_list_help(void)
{
    printf("/LIST\n When the context is not defined (/use)\n\
    /list : list all existing teams\n\
    When the team_uuid is defined (/use team_uuid)\n\
    /list : list all existing channels\n\
    When the channel_uuid is defined (/use team_uuid channel_uuid)\n\
    /list : list all existing threads\n\
    When the user_uuid is defined (/use team_uuid channel_uuid thread_uuid)\n\
    /list : list all existing replies\n\n");
    print_info_help();
}

static void print_create_help(void)
{
    printf("Context:\n\n/CREATE\n\
    When the context is not defined (/use)\n\
    /create ['team_name'] ['team_description']: create a new team\n\
    When team_uuid is defined (/use [team_uuid]):\n\
    /create ['channel_name'] ['channel_description']: create a new channel\n\
    When channel_uuid is defined (/use [team_uuid] [channel_uuid]):\n\
    /create ['thread_title'] ['thread_message']: create a new thread\n\
    When thread_uuid is defined (/use [team_uuid] [channel_uuid] \
    [thread_uuid]):\n\
    /create ['comment_body']: create a new reply\n\n");
    print_list_help();
}

void help(void)
{
    printf("List of accepted commands :\n\n\
    /login <username>\t\t connect the user\n\
    /logout\t\t disconnect the user\n\
    /users\t\t list of connected users\n\
    /user <user_UUID>\t\t get the user's informations\n\
    /send <user_UUID> <message>\t\t send a message to the user\n\
    /messages <user_UUID>\t\t \n\
    /subscribe <team_UUID>\t\t subscribe to the team\n\
    /subscribed ?<team_UUID>\t\t list all subscribed teams or\
    list all users subscribed to a team\n\
    /unsubscribe <team_UUID>\t\t unsubscribe to the team\n\
    use ?<team_UUID> ?<channel_UUID> ?<thread_UUID>\
    \t\t use specify a context team|channel|thread\n\
    /create based on what is being used list all the sub resources\n\
    /list based on what is being used list all the sub resources\n\
    /info based on what is being used list the current\n\n\n");
    print_create_help();
}
