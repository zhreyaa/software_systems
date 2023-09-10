/*
SHREYA CHAVAN MT2023179

Question 24:

Write a program to create an orphan process.

Date: 10th September 2023

*/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
  
int main()
{      int pid = fork();
  
    if (pid > 0)
        printf("In parent process\n");
  
    else
     {  //printf("Child process PPID: %d \n",getppid());
        sleep(30);
        printf("In child process \n");
	printf("Child process PPID: %d \n",getppid());
    }
  
    return 0;
}

//for finding the orphan process use ps and the child pid
