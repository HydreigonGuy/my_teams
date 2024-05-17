/*
** EPITECH PROJECT, 2022
** server
** File description:
** create_new_team
*/

#include "server.h"
#include "logging_server.h"
#include <stdlib.h>

void fill_team_info(team_t *new, char *name, char *description)
{
    new->channels = NULL;
    new->description = description;
    new->id = create_id();
    new->name = name;
    new->next = NULL;
    new->users = NULL;
}

int create_new_team_resp(connection_t *all, team_t *new, connection_t *con)
{
    char *data = create_3_a_data(new->id, new->name, new->description);

    if (!data)
        return (0);
    create_response(con->write_buff, 355, data, "Created new team");
    message_everyone(all, 351, data, "Created new team");
    server_event_team_created(new->id, new->name, con->user->id);
    free(data);
    return (1);
}

int create_new_team(char *data, database_t *db, connection_t *all,
connection_t *con)
{
    char *name = get_sep_a_arg(data, 0);
    char *description = get_sep_a_arg(data, 1);
    team_t *new = NULL;

    if (!name || !description || get_team_by_name(name, db->teams))
        return (0);
    new = malloc(sizeof(team_t));
    if (!new)
        return (0);
    fill_team_info(new, name, description);
    if (!db->teams) {
        db->teams = new;
        return (create_new_team_resp(all, new, con));
    }
    for (team_t *curr = db->teams; curr; curr = curr->next)
        if (!curr->next) {
            curr->next = new;
            return (create_new_team_resp(all, new, con));
        }
    return (0);
}
