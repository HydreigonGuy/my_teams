/*
** EPITECH PROJECT, 2022
** server
** File description:
** create
*/

#include "server.h"
#include <stddef.h>

void create2(char *data, connection_t *con, connection_t *all)
{
    if (!con->path->thread) {
        if (!create_new_thread(data, con->path->chan, all, con))
            create_response(con->write_buff, 406, NULL, "Arg error");
        return;
    }
    create_new_comment(data, con->path, all, con);
}

void create(char *data, connection_t *con, database_t *db, connection_t *all)
{
    if (!data) {
        create_response(con->write_buff, 406, NULL, "Arg error");
        return;
    }
    if (!con->path->team) {
        if (!create_new_team(data, db, all, con))
            create_response(con->write_buff, 406, NULL, "Arg error");
        return;
    }
    if (!get_user_by_id(con->user->id, con->path->team->users)) {
        create_response(con->write_buff, 405, NULL, "Permission denied");
        return;
    }
    if (!con->path->chan) {
        if (!create_new_chan(data, con->path->team, all, con))
            create_response(con->write_buff, 406, NULL, "Arg error");
        return;
    }
    create2(data, con, all);
}
