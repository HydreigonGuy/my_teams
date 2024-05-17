/*
** EPITECH PROJECT, 2022
** server
** File description:
** create_new_comment
*/

#include "server.h"
#include <stdlib.h>
#include <time.h>
#include "logging_server.h"
#include "taya.h"

char *my_time_to_str(time_t time)
{
    char *ret = NULL;
    int len = 0;

    for (int i = 1; i <= time; i *= 10, len++);
    ret = malloc(sizeof(char) * (len + 1));
    ret[len] = '\0';
    len--;
    for (; time; time = time / 10, len--)
        ret[len] = time % 10;
    return (ret);
}

void fill_comment_info(comment_t *new, char *body, char *user_id)
{
    new->id = create_id();
    new->body = my_strdup(body);
    new->next = NULL;
    time(&new->time);
    new->user_id = user_id;
}

int create_new_comment_resp(connection_t *all, comment_t *new, path_t *path,
connection_t *con)
{
    char *data = create_4_a_data(path->team->id, path->thread->id,
    new->user_id, new->body);
    char *data2 = create_4_a_data(path->thread->id, new->user_id, new->body,
    my_time_to_str(new->time));

    if (!data || !data2)
        return (0);
    create_response(con->write_buff, 358, data2, "Created new comment");
    message_subed(all, path->team, 354, data);
    server_event_reply_created(path->thread->id, new->user_id, new->body);
    free(data);
    return (1);
}

int create_new_comment(char *data, path_t *path, connection_t *all,
connection_t *con)
{
    comment_t *new = NULL;

    new = malloc(sizeof(comment_t));
    if (!new)
        return (0);
    fill_comment_info(new, data, con->user->id);
    if (!path->thread->comments) {
        path->thread->comments = new;
        return (create_new_comment_resp(all, new, path, con));
    }
    for (comment_t *curr = path->thread->comments; curr; curr = curr->next)
        if (!curr->next) {
            curr->next = new;
            return (create_new_comment_resp(all, new, path, con));
        }
    return (0);
}
