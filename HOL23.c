/*
SHREYA CHAVAN MT2023179

Question 23:

Write a program to create a Zombie state of the running program.

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

	int main()
{
    // Fork returns process id
    // in parent process
    pid_t child_pid = fork();

    // Parent process
    if (child_pid > 0)
        sleep(50);

    // Child process
    else
        exit(0);

    return 0;
}

//for finding the zombie process use ps aux | grep 'Z' command or ps aux also works
