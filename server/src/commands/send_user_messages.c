/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_user_messages
*/

#include "server.h"
#include <stdlib.h>
#include "taya.h"

char *create_time_str(time_t time)
{
    char *ret = NULL;
    int len = 0;

    for (int i = 1; i <= time; i *= 10, len++);
    ret = malloc(sizeof(char) * len);
    if (!ret)
        return (NULL);
    ret[len] = '\0';
    len--;
    for (int tmp = time; tmp; tmp = tmp / 10, len--)
        ret[len] = tmp % 10;
    return (ret);
}

void send_user_messages(connection_t *con, char *user_id)
{
    char *time_str = NULL;
    char *data = NULL;

    if (!user_id) {
        create_response(con->write_buff, 406, NULL, "Arg error");
        return;
    }
    for (messages_t *curr = con->user->messages; curr; curr = curr->next,
        time_str = NULL, data = NULL) {
        if (mystrcmp(curr->userid, user_id)) {
            time_str = create_time_str(curr->time);
            data = create_3_a_data(user_id, time_str, curr->body);
        }
        if (time_str && data) {
            create_response(con->write_buff, 364, data,
            "Sent private message");
            free(data);
            free(time_str);
        }
    }
}
