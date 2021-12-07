#include "../../../includes/http/post/post.h"


/*
    *    trail/http/post/post.c
    *    Date: 12/6/21
    *    Author: 0x1CA3
*/


void directory_check_post(char *data, char *post_data, char *directory) {
    if (directory == NULL) {
        sprintf(data, "POST / HTTP/1.1\r\n\r\n%s", post_data);
    } else {
        sprintf(data, "POST %s HTTP/1.1\r\n\r\n%s", directory, post_data);
    }
}

bool requests_post(int port, char *website, char *directory, char *post_data) {
    int fd;
    char p[64];
    struct addrinfo* h_i;
    struct sockaddr_in server;
    struct addrinfo *r_d = NULL;
    char i_host[INET6_ADDRSTRLEN];
    char host[64], data[1024], buffer[3048];

    sprintf(p, "%d", port);
    getaddrinfo(website, p, 0, &r_d);
    directory_check_post(data, post_data, directory);

    for (h_i = r_d; h_i != NULL; h_i = h_i->ai_next) {
        if (h_i->ai_addr->sa_family == AF_INET) {
            struct sockaddr_in *i_addr = (struct sockaddr_in *)h_i->ai_addr;
            inet_ntop(AF_INET, &i_addr->sin_addr, i_host, sizeof(i_host));
            break;
        }
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(i_host);
    server.sin_port = htons(port);

    fd = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(fd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        fprintf(stderr, "%s", connection_error());
        return false;
    }

    if (send(fd, data, strlen(data), 0) == -1) {
        fprintf(stderr, "%s", send_data_error());
        return false;
    }

    if (read(fd, buffer, sizeof(buffer)) == -1) {
        fprintf(stderr, "%s", read_data_error());
        return false;
    }

    printf("%s", buffer);
    close(fd);
    
    return true;
}