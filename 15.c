/*

MT2023179 SHREYA CHAVAN

Question : 15

Write a simple program to send some data from parent to the child process.

Date: 1st September, 2023.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipe_fd[2];  // File descriptors for the pipe
    pid_t child_pid;
    char message[] = "Hello, child process!";

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Child process
        close(pipe_fd[1]);  // Close the write end since the child only reads

        char buffer[100];
        ssize_t bytes_read = read(pipe_fd[0], buffer, sizeof(buffer));

        if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Child received: %s\n", buffer);

        close(pipe_fd[0]);  // Close the read end in the child
    } else {
        // Parent process
        close(pipe_fd[0]);  // Close the read end since the parent only writes

        ssize_t bytes_written = write(pipe_fd[1], message, strlen(message));

        if (bytes_written == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        printf("Parent sent: %s\n", message);

        close(pipe_fd[1]);  // Close the write end in the parent
    }

    return 0;
}

