/*

MT2023179 SHREYA CHAVAN

Question : 16

Write a program to send and receive data from parent to child vice versa. Use two way
communication.

Date: 1st September, 2023.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int parent_to_child[2];  // Pipe for parent to child communication
    int child_to_parent[2];  // Pipe for child to parent communication
    pid_t child_pid;

    if (pipe(parent_to_child) == -1 || pipe(child_to_parent) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Child process
        close(parent_to_child[1]);  // Close the write end from parent to child
        close(child_to_parent[0]);  // Close the read end from child to parent

        char message_from_parent[100];
        ssize_t bytes_read = read(parent_to_child[0], message_from_parent, sizeof(message_from_parent));

        if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Child received from parent: %s\n", message_from_parent);

        // Send a response from child to parent
        char response[] = "Hello, parent!";
        ssize_t bytes_written = write(child_to_parent[1], response, strlen(response));

        if (bytes_written == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        close(parent_to_child[0]);  // Close the read end in the child
        close(child_to_parent[1]);  // Close the write end in the child
    } else {
        // Parent process
        close(parent_to_child[0]);  // Close the read end from parent to child
        close(child_to_parent[1]);  // Close the write end from child to parent

        char message_to_child[] = "Hello, child!";
        ssize_t bytes_written = write(parent_to_child[1], message_to_child, strlen(message_to_child));

        if (bytes_written == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        // Wait for a response from the child
        char response_from_child[100];
        ssize_t bytes_read = read(child_to_parent[0], response_from_child, sizeof(response_from_child));

        if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Parent received from child: %s\n", response_from_child);

        close(parent_to_child[1]);  // Close the write end in the parent
        close(child_to_parent[0]);  // Close the read end in the parent
    }

    return 0;
}

