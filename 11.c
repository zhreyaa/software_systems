/*
SHREYA CHAVAN MT2023179

Question 11:

Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl

Date: 28th August 2023

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	printf("Process PID:%d \n",getpid());
	int fd1,fd2,fd3,fd4;
	fd1=open("file2",O_RDWR | O_CREAT);
	fd2=dup(fd1);

	printf("Values of fd1 and fd2 are : %d  %d", fd1, fd2);


	fd3 = dup2(fd2,10);

	printf("\nValues of fd2 and fd3 are : %d  %d", fd2, fd3);


	fd4=fcntl(fd1,F_DUPFD);
	printf("\nValues of fd1 and fd4 are : %d  %d \n", fd1, fd4);

	return 0;
}
