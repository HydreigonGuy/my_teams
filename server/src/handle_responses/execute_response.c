/*
** EPITECH PROJECT, 2022
** server
** File description:
** execute_response
*/

#include "server.h"
#include <stddef.h>

int login_required3(my_server_t *serv, connection_t *con, response_t *resp)
{
    if (resp->code == 381) {
        send_user(con, get_user_by_id(resp->data, serv->data->users));
        return (1);
    }
    if (resp->code == 382) {
        send_sebscribed(con, resp->data, serv->data->teams);
        return (1);
    }
    if (resp->code == 383) {
        send_path_info(con);
        return (1);
    }
    if (resp->code == 384) {
        send_path_list(con, serv->data->teams);
        return (1);
    }
    return (0);
}

int login_required2(my_server_t *serv, connection_t *con, response_t *resp,
connection_t *all)
{
    if (resp->code == 350) {
        create(resp->data, con, serv->data, all);
        return (1);
    }
    if (resp->code == 360) {
        send_message(con, serv->data->users, resp->data, all);
        return (1);
    }
    if (resp->code == 363) {
        send_user_messages(con, resp->data);
        return (1);
    }
    if (resp->code == 380) {
        send_users(con, serv->data->users);
        return (1);
    }
    return (login_required3(serv, con, resp));
}

int login_required(my_server_t *serv, connection_t *con, response_t *resp,
connection_t *all)
{
    if (resp->code == 225) {
        logout_user(con, all);
        return (1);
    }
    if (resp->code == 310) {
        change_path(resp->data, con, serv->data->teams);
        return (1);
    }
    if (resp->code == 311) {
        subscribe(resp->data, serv->data->teams, con, all);
        return (1);
    }
    if (resp->code == 312) {
        unsubscribe(resp->data, serv->data->teams, con, all);
        return (1);
    }
    return (login_required2(serv, con, resp, all));
}

int anyone(my_server_t *serv, connection_t *con, response_t *resp,
connection_t *all)
{
    if (resp->code == 300) {
        login(resp->data, serv, con, all);
        return (1);
    }
    return (0);
}

void execute_response(my_server_t *serv, connection_t *con, response_t *resp,
connection_t *all)
{
    if (anyone(serv, con, resp, all))
        return;
    if (!con->user) {
        create_response(con->write_buff, 405, NULL, "Permission denied");
        return;
    }
    if (login_required(serv, con, resp, all))
        return;
    create_response(con->write_buff, 404, NULL, "Bad command");
}
