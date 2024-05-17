/*
** EPITECH PROJECT, 2022
** server
** File description:
** create_new_chan
*/

#include "server.h"
#include <stdlib.h>
#include "logging_server.h"

void fill_chan_info(channel_t *new, char *name, char *description)
{
    new->threads = NULL;
    new->description = description;
    new->id = create_id();
    new->name = name;
    new->next = NULL;
}

int create_new_chan_resp(connection_t *all, channel_t *new, team_t *team,
connection_t *con)
{
    char *data = create_3_a_data(new->id, new->name, new->description);

    if (!data)
        return (0);
    create_response(con->write_buff, 356, data, "Created new chan");
    server_event_channel_created(team->id, new->id, new->name);
    message_subed(all, team, 352, data);
    free(data);
    return (1);
}

int create_new_chan(char *data, team_t *team, connection_t *all,
connection_t *con)
{
    char *name = get_sep_a_arg(data, 0);
    char *description = get_sep_a_arg(data, 1);
    channel_t *new = NULL;

    if (!name || !description || get_chan_by_name(name, team->channels))
        return (0);
    new = malloc(sizeof(channel_t));
    if (!new)
        return (0);
    fill_chan_info(new, name, description);
    if (!team->channels) {
        team->channels = new;
        return (create_new_chan_resp(all, new, team, con));
    }
    for (channel_t *curr = team->channels; curr; curr = curr->next)
        if (!curr->next) {
            curr->next = new;
            return (create_new_chan_resp(all, new, team, con));
        }
    return (0);
}
