/*
SHREYA CHAVAN MT2023179

Question 3:

Write a program to create a file and print the file descriptor value. Use creat ( ) system call

*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
int main()
{
	int x= creat( "filex",O_RDONLY);
	if(x==-1)
		perror("Failed");
	else
		printf("%d",x);
	return 0;

}

// execute this program with ./a.out and then check status with ls -la/proc/pid
