/*
SHREYA CHAVAN MT2023179

Question 21:

Write a program, call fork and print the parent and child process id.

*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	if(fork())
		printf("Parent process PID: %d \n",getpid());
	else
		printf("Child process PID: %d \n",getpid());
	return 0;
}
