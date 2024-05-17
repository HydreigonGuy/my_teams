/*
** EPITECH PROJECT, 2022
** server
** File description:
** header
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include <netinet/in.h>
    #include <time.h>
    #include <stdio.h>
    #include <stdlib.h>

    #define MAX_BACKLOG     100
    #define BUFF_SIZE       2049
    #define READ_SIZE       1024

    enum Status {
        READ,
        WRITE,
        EXCEPT,
        SHUTDOWN,
        DISCONNECTED
    };

    typedef struct response_s {
        int code;
        char *data;
        char *msg;
    } response_t;

    typedef struct comment_s {
        char *body;
        char *id;
        time_t time;
        char *user_id;
        struct comment_s *next;
    } comment_t;

    typedef struct thread_s {
        char *title;
        char *message;
        char *id;
        time_t time;
        char *user_id;
        comment_t *comments;
        struct thread_s *next;
    } thread_t;

    typedef struct channel_s {
        char *name;
        char *description;
        char *id;
        thread_t *threads;
        struct channel_s *next;
    } channel_t;

    typedef struct messages_s {
        char *userid;
        char *body;
        time_t time;
        struct messages_s *next;
    } messages_t;

    typedef struct user_s {
        char *name;
        char *id;
        int connections;
        messages_t *messages;
    } user_t;

    typedef struct user_list_s {
        user_t *user;
        struct user_list_s *next;
    } user_list_t;

    typedef struct team_s {
        char *name;
        char *description;
        char *id;
        user_list_t *users;
        channel_t *channels;
        struct team_s *next;
    } team_t;

    typedef struct database_s {
        user_list_t *users;
        team_t *teams;
    } database_t;

    typedef struct my_server_s {
        int server_socket;
        struct sockaddr_in address;
        int can_accept;
        int stdin_ready;
        database_t *data;
    } my_server_t;

    typedef struct buffer_s {
        char *buff;
        int start;
        int end;
    } buffer_t;

    typedef struct path_s {
        team_t *team;
        channel_t *chan;
        thread_t *thread;
    } path_t;

    typedef struct connection_s {
        int fd;
        user_t *user;
        enum Status status;
        int ready;
        buffer_t *read_buff;
        buffer_t *write_buff;
        path_t *path;
        struct connection_s *next;
    } connection_t;

    // miscellaneous
    int handle_help(int ac, char **av);
    void destroy_buffer(buffer_t *buff);
    void close_server(my_server_t *server);

    // settup
    int handle_args(char *port_str);
    int start_server(int port);
    my_server_t *fill_server_info(int port);
    int bind_server(my_server_t *);
    int make_server_listen(my_server_t *);

    // socket selection
    void check_select(my_server_t *, connection_t *);
    void set_all_unready(my_server_t *, connection_t *);
    int get_select_num(int server, connection_t *);
    void set_status(connection_t *connect);

    // accepting selection
    void handle_accept(my_server_t *, connection_t **);
    void create_connection(connection_t **, int socket);
    path_t *create_new_path(void);
    buffer_t *create_buffer(void);
    int accept_connection(my_server_t *);

    // running server
    int run_server(my_server_t *);

    // write
    void create_response(buffer_t *, int code, char *data, char *message);
    void send_response(connection_t *connect);
    void write_on_socket(int fd, buffer_t *buff);
    void message_everyone(connection_t *, int code, char *data, char *msg);
    char *create_2_comma_resp(char *s1, char *s2);
    char *create_2_a_data(char *s1, char *s2);
    char *create_3_a_data(char *s1, char *s2, char *s3);
    char *create_4_a_data(char *s1, char *s2, char *s3, char *s4);
    void message_subed(connection_t *, team_t *team, int code, char *data);
    char *time_to_str(time_t timestamp);

    // read
    void read_message(connection_t *connect);
    int read_socket(int fd, buffer_t *buff);

    // handle responses
    void handle_responses(my_server_t *server, connection_t *connect);
    void remove_resp_from_buffer(buffer_t *buff);
    response_t *fill_response(buffer_t *buff);
    void extract_response_info(response_t *new, buffer_t *buff);
    void execute_response(my_server_t *, connection_t *, response_t *,
    connection_t *);

    // end
    void handle_connection_ends(connection_t **connect);
    void close_connection(connection_t *connect);
    void destroy_connections(connection_t **connect);

    // stdin
    int handle_stdin(my_server_t *server);

    // destroy data
    void destroy_database(database_t *data);
    void destroy_user_list(user_list_t *list);
    void destroy_user(user_t *user);
    void destroy_comments(comment_t *comments);
    void destroy_threads(thread_t *threads);
    void destroy_channels(channel_t *channels);
    void destroy_teams(team_t *teams);

    // commands
    void login(char *name, my_server_t *, connection_t *, connection_t *);
    void logout_user(connection_t *connect, connection_t *all);
    void change_path(char *data, connection_t *con, team_t *teams);
    int handle_wrong_path_change(path_t *path, char *data);
    void subscribe(char *data, team_t *, connection_t *, connection_t *all);
    void unsubscribe(char *data, team_t *, connection_t *, connection_t *);
    void create(char *data, connection_t *con, database_t *, connection_t *);
    void send_user(connection_t *connect, user_t *user);
    void send_users(connection_t *connect, user_list_t *users);
    void send_team_info(connection_t *con, team_t *team);
    void send_chan_info(connection_t *con, channel_t *chan);
    void send_thread_info(connection_t *con, thread_t *thread);
    void send_teams_info(connection_t *con, team_t *team);
    void send_chans_info(connection_t *con, channel_t *chan);
    void send_threads_info(connection_t *con, thread_t *thread);
    void send_comments_info(connection_t *con, comment_t *msg);
    void send_user_list(connection_t *connect, user_t *user);
    void send_sebscribed(connection_t *con, char *data, team_t *teams);
    void send_path_info(connection_t *con);
    void send_path_list(connection_t *con, team_t *teams);
    void fill_thread_resp_time(char *data, thread_t *thread, int c);
    void send_message(connection_t *, user_list_t *, char *, connection_t *);
    void send_user_messages(connection_t *con, char *user_id);

    // get data
    char *get_user_id(char *name, user_list_t **users);
    user_t *get_user_by_id(char *id, user_list_t *users);
    char *get_users_str(user_t *user);
    team_t *get_team_by_id(char *id, team_t *teams);
    team_t *get_team_by_name(char *name, team_t *teams);
    channel_t *get_chan_by_name(char *name, channel_t *chans);

    // create data
    database_t *fill_server_data(void);
    void create_user(char *name, user_list_t **users);
    char *create_id(void);
    int create_new_team(char *, database_t *, connection_t *, connection_t *);
    int create_new_chan(char *, team_t *, connection_t *, connection_t *);
    int create_new_thread(char *, channel_t *, connection_t *,
    connection_t *);
    int create_new_comment(char *, path_t *, connection_t *, connection_t *);
    char *get_sep_a_arg(char *data, int arg);
    void create_message(user_t *user, char *user_id, char *body);

    // save data
    void saveComments(FILE *file, comment_t *comment_l);
    void saveThread(FILE *file, thread_t *thread);
    void saveChannel(FILE *file, channel_t *chan);
    void saveTeam(FILE *file, team_t *team);
    void saveUsers(FILE *file, user_list_t *user_l);
    void saveTeams(FILE *file, team_t *teams);
    void createDatabase(database_t *db);

    // load data
    FILE *openFile(char *fileName, char *mode);
    database_t *loadDatabase(void);
    channel_t *getChannel(char *line, size_t len, FILE *file);
    channel_t *getChannelList(char *line, size_t len, FILE *file);
    user_list_t *fillUserInTeam(user_list_t *user_list, char *token);
    team_t *getTeam(char *line, size_t len, FILE *file, user_list_t *user_l);
    team_t *getTeamList(char *line, size_t len, FILE *file, user_list_t *user_l);
    comment_t *getComment(char *line);
    void fillComments(thread_t *thread, char *line, size_t len, FILE *file);
    thread_t *getThread(char *line, size_t len, FILE *file);
    thread_t *getThreadList(char *line, size_t len, FILE *file);
    messages_t *getMessage(char *token);
    void fillMessages(user_t *user, char *token);
    user_t *getUser(char *line);
    void fillUserList(user_list_t *user_list, char *line);
    user_list_t *getUserList(char *line, size_t len, FILE *file);

#endif /* !SERVER_H_ */
