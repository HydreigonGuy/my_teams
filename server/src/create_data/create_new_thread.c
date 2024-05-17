/*
** EPITECH PROJECT, 2022
** server
** File description:
** create_new_thread
*/

#include "server.h"
#include <stdlib.h>
#include <time.h>
#include "logging_server.h"

void fill_thread_info(thread_t *new, char *title, char *msg, char *user_id)
{
    new->comments = NULL;
    new->id = create_id();
    new->message = msg;
    new->next = NULL;
    time(&new->time);
    new->title = title;
    new->user_id = user_id;
}

int create_new_thread_resp_free(char *s1, char *s2, char *s3)
{
    if (s1)
        free(s1);
    if (s2)
        free(s2);
    if (s3)
        free(s3);
    return (0);
}

void create_new_thread_msgs(connection_t *all, connection_t *con, char *data)
{
    create_response(con->write_buff, 357, data, "Created new thread");
    message_subed(all, con->path->team, 353, data);
}

int create_new_thread_resp(connection_t *all, thread_t *new, char *chan_id,
connection_t *con)
{
    char *data1 = create_3_a_data(new->id, new->title, new->message);
    char *data = NULL;
    char *time = NULL;

    if (!data1)
        return (0);
    time = time_to_str(new->time);
    if (!time)
        return (create_new_thread_resp_free(data1, NULL, NULL));
    data = create_3_a_data(data1, new->user_id, time);
    if (!data)
        return (create_new_thread_resp_free(data, data1, NULL));
    create_new_thread_msgs(all, con, data);
    server_event_thread_created(chan_id, new->id, new->user_id, new->title,
    new->message);
    create_new_thread_resp_free(data, data1, time);
    return (1);
}

int create_new_thread(char *data, channel_t *chan, connection_t *all,
connection_t *con)
{
    char *title = get_sep_a_arg(data, 0);
    char *msg = get_sep_a_arg(data, 1);
    thread_t *new = NULL;

    if (!title || !msg)
        return (0);
    new = malloc(sizeof(thread_t));
    if (!new)
        return (0);
    fill_thread_info(new, title, msg, con->user->id);
    if (!chan->threads) {
        chan->threads = new;
        return (create_new_thread_resp(all, new, chan->id, con));
    }
    for (thread_t *curr = chan->threads; curr; curr = curr->next)
        if (!curr->next) {
            curr->next = new;
            return (create_new_thread_resp(all, new, chan->id, con));
        }
    return (0);
}
