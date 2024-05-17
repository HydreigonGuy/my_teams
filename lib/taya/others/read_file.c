/*
** EPITECH PROJECT, 2022
** lib
** File description:
** read_file
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

char *read_file(char *file_name)
{
    int file_descriptor = open(file_name, O_RDONLY);
    char *file_content = NULL;
    struct stat buffer;

    if (file_descriptor == -1 || stat(file_name, &buffer) == -1)
        return (NULL);
    file_content = malloc(sizeof(char) * (buffer.st_size + 1));
    if (!file_content) {
        close(file_descriptor);
        return (NULL);
    }
    if (read(file_descriptor, file_content, buffer.st_size) == -1) {
        free(file_content);
        close(file_descriptor);
        return (NULL);
    }
    file_content[buffer.st_size] = '\0';
    close(file_descriptor);
    return (file_content);
}