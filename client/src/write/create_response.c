/*
** EPITECH PROJECT, 2022
** client
** File description:
** create_response
*/

#include "client.h"

void fill_code_resp(buffer_t *buff, int code)
{
    buff->buff[buff->end] = (code / 100) % 10 + '0';
    buff->end = (buff->end + 1) % BUFF_SIZE;
    buff->buff[buff->end] = (code / 10) % 10 + '0';
    buff->end = (buff->end + 1) % BUFF_SIZE;
    buff->buff[buff->end] = code % 10 + '0';
    buff->end = (buff->end + 1) % BUFF_SIZE;
}

void fill_data_resp(buffer_t *buff, char *data)
{
    buff->buff[buff->end] = ' ';
    buff->end = (buff->end + 1) % BUFF_SIZE;
    buff->buff[buff->end] = '[';
    buff->end = (buff->end + 1) % BUFF_SIZE;
    for (int i = 0; data[i]; i++) {
        buff->buff[buff->end] = data[i];
        buff->end = (buff->end + 1) % BUFF_SIZE;
    }
    buff->buff[buff->end] = ']';
    buff->end = (buff->end + 1) % BUFF_SIZE;
}

void fill_message_resp(buffer_t *buff, char *message)
{
    buff->buff[buff->end] = ' ';
    buff->end = (buff->end + 1) % BUFF_SIZE;
    for (int i = 0; message[i]; i++) {
        buff->buff[buff->end] = message[i];
        buff->end = (buff->end + 1) % BUFF_SIZE;
    }
    buff->buff[buff->end] = '\r';
    buff->end = (buff->end + 1) % BUFF_SIZE;
    buff->buff[buff->end] = '\n';
    buff->end = (buff->end + 1) % BUFF_SIZE;
}

void create_response(buffer_t *buff, int code, char *data, char *message)
{
    fill_code_resp(buff, code);
    if (data)
        fill_data_resp(buff, data);
    fill_message_resp(buff, message);
}
