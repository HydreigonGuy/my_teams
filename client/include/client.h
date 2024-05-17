/*
** EPITECH PROJECT, 2022
** client
** File description:
** header
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

    #include <netinet/in.h>

    #define BUFF_SIZE       2049
    #define READ_SIZE       1024

    enum Status {
        READ,
        WRITE,
        EXCEPT
    };

    typedef struct response_s {
        int code;
        char *data;
        char *msg;
    } response_t;

    typedef struct buffer_s {
        char *buff;
        int start;
        int end;
    } buffer_t;

    typedef struct stdin_check_s {
        enum Status status;
        int ready;
        char *read;
        char *write;
    } stdin_check_t;

    typedef struct my_client_s {
        int socket;
        struct sockaddr_in address;
        enum Status status;
        int ready;
        int shutdown;
        buffer_t *read_buff;
        buffer_t *write_buff;
        stdin_check_t *stdin;
    } my_client_t;

    // miscellaneous
    int handle_help(int ac, char **av);
    void destroy_buffer(buffer_t *buff);

    // settup
    int handle_args(char *ip, char *port_str);
    int start_client(int port, char *ip);
    my_client_t *fill_client_info(int port, char *ip);
    buffer_t *create_buffer(void);
    void destroy_client(my_client_t *client);

    // run client
    void run_client(my_client_t *client);

    // select
    void check_select(my_client_t *client);
    void set_status(my_client_t *client);

    // write
    void send_response(my_client_t *client);
    void create_response(buffer_t *, int code, char *data, char *message);

    // read
    void read_message(my_client_t *client);

    // handle responses
    void handle_responses(my_client_t *client);
    response_t *fill_response(buffer_t *buff);
    void remove_resp_from_buffer(buffer_t *buff);
    void extract_response_info(response_t *new, buffer_t *buff);
    void execute_response(response_t *resp, my_client_t *cli);
    char *get_resp_data_arg(char *str, char split);

    // stdin
    void handle_stdin(my_client_t *client);
    int is_command(char *line);
    char *get_command_arg(char *line);

    // commands
    void help();
    void logout(my_client_t *client);
    void login(my_client_t *client, char *username);
    void users(my_client_t *client);
    void user(my_client_t *client, char *user_uuid);
    void command_send(my_client_t *client, char *arguments);
    void messages(my_client_t *client, char *user_uuid);
    void subscribe(my_client_t *client, char *team_uuid);
    void subscribed(my_client_t *client, char *team_uuid);
    void unsubscribe(my_client_t *client, char *team_uuid);
    void use(my_client_t *client, char *arguments);
    void list(my_client_t *client);
    void info(my_client_t *client);
    void create(my_client_t *client, char *arguments);

    // handle info
    void handle_user_info(char *data);
    void handle_user_unsubscribe(char *str);
    void handle_user_subscribe(char *str);
    void handle_new_comment(char *str);
    void handle_new_thread(char *str);
    void handle_new_chan(char *str);
    void handle_new_team(char *str);
    void handle_user_login(char *str);
    void handle_user_logout(char *str);
    void handle_recieving_message(char *str);
    void handle_list_team(char *str);
    void handle_list_chan(char *str);
    void handle_list_thread(char *str);
    void handle_list_comment(char *str);
    void handle_list_user(char *str);
    void handle_team_info(char *str);
    void handle_chan_info(char *str);
    void handle_thread_info(char *str);
    void handle_create_team(char *str);
    void handle_create_chan(char *str);
    void handle_create_thread(char *str);
    void handle_create_comment(char *str);
    time_t get_time_from_str(char *str);

#endif /* !HEADER_H_ */
