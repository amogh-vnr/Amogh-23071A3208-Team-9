#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <pthread.h>

#define SOCKET_PATH "/tmp/uds_chat.socket"
#define BUFFER_SIZE 1024

void *handle_client(void *arg) {
    int client_fd = *(int *)arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            close(client_fd);
            break;
        }
        printf("Client: %s", buffer);
    }
    return NULL;
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_un server_addr;

    server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    unlink(SOCKET_PATH);
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, SOCKET_PATH);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 5) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("UDS Server listening on %s\n", SOCKET_PATH);
    
    while (1) {
        client_fd = accept(server_fd, NULL, NULL);
        if (client_fd == -1) {
            perror("Accept failed");
            continue;
        }

        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, &client_fd);
        pthread_detach(thread);
    }

    close(server_fd);
    return 0;
}
