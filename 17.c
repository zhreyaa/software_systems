/*

MT2023179 SHREYA CHAVAN

Question : 17

Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl

Date: 1st September, 2023.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_fd[2]; // File descriptors for the pipe

    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Child process
        close(pipe_fd[1]); // Close the write end of the pipe

        // Redirect the standard input (stdin) to read from the pipe
        dup2(pipe_fd[0], STDIN_FILENO);
        close(pipe_fd[0]); // Close the read end of the pipe

        // Execute 'wc' command
        execlp("wc", "wc", (char *)NULL);

        // execlp() will only return if there's an error
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        close(pipe_fd[0]); // Close the read end of the pipe

        // Redirect the standard output (stdout) to write to the pipe
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[1]); // Close the write end of the pipe

        // Execute 'ls -l' command
        execlp("ls", "ls", "-l", (char *)NULL);

        // execlp() will only return if there's an error
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    return 0;
}

