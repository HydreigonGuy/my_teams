/*
** EPITECH PROJECT, 2022
** client
** File description:
** execute_response
*/

#include "client.h"
#include "logging_client.h"

static void execute_last_response(response_t *resp, my_client_t *cli)
{
    if (resp->code == 387)
        handle_list_thread(resp->data);
    if (resp->code == 388)
        handle_list_comment(resp->data);
    if (resp->code == 389)
        handle_list_user(resp->data);
    if (resp->code == 390)
        handle_user_info(resp->data);
    if (resp->code == 391)
        handle_team_info(resp->data);
    if (resp->code == 392)
        handle_chan_info(resp->data);
    if (resp->code == 393)
        handle_thread_info(resp->data);
    if (resp->code == 405)
        client_error_unauthorized();
}

static void execute_other_response(response_t *resp, my_client_t *cli)
{
    if (resp->code == 357)
        handle_create_thread(resp->data);
    if (resp->code == 358)
        handle_create_comment(resp->data);
    if (resp->code == 250)
        handle_user_subscribe(resp->data);
    if (resp->code == 251)
        handle_user_unsubscribe(resp->data);
    if (resp->code == 362)
        handle_recieving_message(resp->data);
    if (resp->code == 385)
        handle_list_team(resp->data);
    if (resp->code == 386)
        handle_list_chan(resp->data);
    return execute_last_response(resp, cli);
}

void execute_response(response_t *resp, my_client_t *cli)
{
    if (resp->code == 226 && cli->shutdown == 1)
        cli->shutdown = 2;
    if (resp->code == 226)
        handle_user_logout(resp->data);
    if (resp->code == 301)
        handle_user_login(resp->data);
    if (resp->code == 351)
        handle_new_team(resp->data);
    if (resp->code == 352)
        handle_new_chan(resp->data);
    if (resp->code == 353)
        handle_new_thread(resp->data);
    if (resp->code == 354)
        handle_new_comment(resp->data);
    if (resp->code == 355)
        handle_create_team(resp->data);
    if (resp->code == 356)
        handle_create_chan(resp->data);
    return execute_other_response(resp, cli);
}
