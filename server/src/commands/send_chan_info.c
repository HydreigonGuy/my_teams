/*
** EPITECH PROJECT, 2022
** server
** File description:
** send_chan_info
*/

#include "server.h"
#include "taya.h"
#include <stdlib.h>

void fill_chan_resp_data(char *data, channel_t *chan)
{
    int c = 0;

    for (; chan->name[c]; c++)
        data[c] = chan->name[c];
    data[c] = '\a';
    c++;
    for (int i = 0; chan->id[i]; i++, c++)
        data[c] = chan->id[i];
    data[c] = '\a';
    c++;
    for (int i = 0; chan->description[i]; i++, c++)
        data[c] = chan->description[i];
    data[c] = '\0';
}

void send_chan_info(connection_t *con, channel_t *chan)
{
    char *data = NULL;

    if (!chan) {
        create_response(con->write_buff, 406, NULL, "Bad argument(s)");
        return;
    }
    data = malloc(sizeof(char) * (my_strlen(chan->name) +
    my_strlen(chan->id) + my_strlen(chan->description) + 3));
    if (!data)
        return;
    fill_chan_resp_data(data, chan);
    create_response(con->write_buff, 392, data, "Sent chan info");
    free(data);
}
