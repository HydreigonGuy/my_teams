/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_thread_info
*/

#include "server.h"
#include "taya.h"
#include <stdlib.h>

void fill_threads_resp_time(char *data, thread_t *thread, int c)
{
    int tmp = thread->time;
    int time_size = 0;

    for (int i = 1; i <= thread->time; i *= 10, time_size++);
    c += time_size;
    data[c + 1] = '\0';
    for (; tmp; tmp = tmp / 10, c--)
        data[c] = tmp % 10;
}

void fill_threads_resp_data(char *data, thread_t *thread)
{
    int c = 0;

    for (; thread->title[c]; c++)
        data[c] = thread->title[c];
    data[c] = '\a';
    c++;
    for (int i = 0; thread->id[i]; i++, c++)
        data[c] = thread->id[i];
    data[c] = '\a';
    c++;
    for (int i = 0; thread->message[i]; i++, c++)
        data[c] = thread->message[i];
    data[c] = '\a';
    c++;
    for (int i = 0; thread->user_id[i]; i++, c++)
        data[c] = thread->user_id[i];
    data[c] = '\a';
    c++;
    fill_threads_resp_time(data, thread, c);
}

void send_threads_info(connection_t *con, thread_t *thread)
{
    char *data = NULL;
    int time_size = 0;

    if (!thread) {
        create_response(con->write_buff, 406, NULL, "Bad argument(s)");
        return;
    }
    for (int i = 1; i <= thread->time; i *= 10, time_size++);
    data = malloc(sizeof(char) * (my_strlen(thread->title) +
    my_strlen(thread->id) + my_strlen(thread->message) +
    my_strlen(thread->user_id) + time_size + 5));
    if (!data)
        return;
    fill_threads_resp_data(data, thread);
    create_response(con->write_buff, 387, data, "Sent thread info");
    free(data);
}
