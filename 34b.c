/*

MT2023179 SHREYA CHAVAN

Question : 34

Write a program to create a concurrent server.
a. use fork
b. use pthread_create

Date: 22nd September, 2023.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

void* handle_client(void* arg) {
    int client_socket = *((int*)arg);
    free(arg);

    // Handle client requests here.
    // You can read and write data with the client using client_socket.
    
    // For this example, we'll just send a simple message to the client.
    const char* response = "Hello from the server!";
    ssize_t bytes_sent = send(client_socket, response, strlen(response), 0);
    if (bytes_sent == -1) {
        perror("Error sending data");
        close(client_socket);
        pthread_exit(NULL);
    }

    // Close the client socket
    close(client_socket);
    pthread_exit(NULL);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(12345); // Port number
    server_address.sin_addr.s_addr = INADDR_ANY; // Listen on all available network interfaces

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Error binding");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Error listening");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 12345...\n");

    while (1) {
        // Accept incoming connection
        client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_length);
        if (client_socket == -1) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        printf("Accepted connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Create a thread to handle the client
        pthread_t thread;
        int* client_sock = malloc(sizeof(int));
        *client_sock = client_socket;

        if (pthread_create(&thread, NULL, handle_client, (void*)client_sock) != 0) {
            perror("Error creating thread");
            close(client_socket);
            free(client_sock);
        }
    }

    // Close the server socket (unreachable in this example)
    close(server_socket);

    return 0;
}

