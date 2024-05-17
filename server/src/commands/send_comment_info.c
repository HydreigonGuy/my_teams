/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_comment_info
*/

#include "server.h"
#include "taya.h"
#include <stdlib.h>

void fill_comment_resp_time(char *data, comment_t *msg, int c)
{
    int tmp = msg->time;
    int time_size = 0;

    for (int i = 1; i <= msg->time; i *= 10, time_size++);
    c += time_size;
    data[c + 1] = '\0';
    for (; tmp; tmp = tmp / 10, c--)
        data[c] = tmp % 10;
}

void fill_comment_resp_data(char *data, comment_t *msg)
{
    int c = 0;

    for (; msg->id[c]; c++)
        data[c] = msg->id[c];
    data[c] = '\a';
    c++;
    for (int i = 0; msg->body[i]; i++, c++)
        data[c] = msg->body[i];
    data[c] = '\a';
    c++;
    for (int i = 0; msg->user_id[i]; i++, c++)
        data[c] = msg->user_id[i];
    data[c] = '\a';
    c++;
    fill_comment_resp_time(data, msg, c);
}

void send_comments_info(connection_t *con, comment_t *msg)
{
    char *data = NULL;
    int time_size = 0;

    if (!msg) {
        create_response(con->write_buff, 406, NULL, "Bad argument(s)");
        return;
    }
    for (int i = 1; i <= msg->time; i *= 10, time_size++);
    data = malloc(sizeof(char) * (my_strlen(msg->user_id) +
    my_strlen(msg->id) + my_strlen(msg->body) + 4 + time_size));
    if (!data)
        return;
    fill_comment_resp_data(data, msg);
    create_response(con->write_buff, 388, data, "Sent comment info");
    free(data);
}
