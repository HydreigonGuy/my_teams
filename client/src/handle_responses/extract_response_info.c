/*
** EPITECH PROJECT, 2022
** client
** File description:
** extract_response_info
*/

#include "client.h"
#include <stdlib.h>

void fill_resp_code(response_t *new, buffer_t *buff)
{
    new->code = 0;
    if (buff->buff[buff->start] <= '9' && buff->buff[buff->start] >= '0')
        new->code = (buff->buff[buff->start] - '0') * 100;
    if (buff->buff[(buff->start + 1) % BUFF_SIZE] <= '9' &&
        buff->buff[(buff->start + 1) % BUFF_SIZE] >= '0')
        new->code = new->code +
            (buff->buff[(buff->start + 1) % BUFF_SIZE] - '0') * 10;
    if (buff->buff[(buff->start + 2) % BUFF_SIZE] <= '9' &&
        buff->buff[(buff->start + 2) % BUFF_SIZE] >= '0')
        new->code = new->code +
            buff->buff[(buff->start + 2) % BUFF_SIZE] - '0';
}

void fill_resp_data(response_t *new, buffer_t *buff)
{
    int i = 4;
    int len = 0;

    if (buff->buff[(buff->start + i) % BUFF_SIZE] != '[')
        return;
    for (i = i + 1; (buff->start + i + len) % BUFF_SIZE != buff->end &&
        buff->buff[(buff->start + i + len) % BUFF_SIZE] != ']'; len++);
    new->data = malloc(sizeof(char) * (len + 1));
    if (!new->data)
        return;
    for (; i - 5 < len; i++)
        new->data[i - 5] = buff->buff[(buff->start + i) % BUFF_SIZE];
    new->data[len] = '\0';
}

void fill_resp_msg(response_t *new, buffer_t *buff)
{
    int i = 4;
    int len = 0;

    if (buff->buff[(buff->start + i) % BUFF_SIZE] == '[') {
        for (i = i + 1; (buff->start + i) % BUFF_SIZE != buff->end &&
            buff->buff[(buff->start + i) % BUFF_SIZE] != ']'; i++);
        i += 2;
    }
    if ((buff->start + i - 1) % BUFF_SIZE == buff->end)
        return;
    for (; (buff->start + i + len) % BUFF_SIZE != buff->end &&
        !(buff->buff[(buff->start + i + len) % BUFF_SIZE] == '\r' &&
        buff->buff[(buff->start + i + len + 1) % BUFF_SIZE] == '\n'); len++);
    new->msg = malloc(sizeof(char) * (len + 1));
    if (!new->msg)
        return;
    for (int j = 0; j < len; j++)
        new->msg[j] = buff->buff[(buff->start + i + j) % BUFF_SIZE];
    new->msg[len] = '\0';
}

void extract_response_info(response_t *new, buffer_t *buff)
{
    fill_resp_code(new, buff);
    fill_resp_data(new, buff);
    fill_resp_msg(new, buff);
    if (!new->msg) {
        free(new);
        new = NULL;
    }
}
