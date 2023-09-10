/*
SHREYA CHAVAN MT2023179

Question 15:

Write a program to display the environmental variable of the user (use environ).

Date: 28th August 2023

*/

#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main() {
    char **env = environ;

    printf("Environmental variables:\n");
    while (*env) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}

