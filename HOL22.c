/*
SHREYA CHAVAN MT2023179

Question 22:

Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.

Date: 10th September 2023

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd=open("/home/shreya2001/sslab/test.txt",O_RDWR,0777);
	//int i=fork();
	if(fork())
	{
		//int fd=open("/home/shreya2001/sslab/test.txt",O_RDWR,0777);
		printf("In parent! \n");
		//lseek(fd,SEEK_CUR,0);
		char buf[20]="\nHi I am parent! \n";
		write(fd,&buf,sizeof(buf));
	}
	else
	{
		//int fd=open("/home/shreya2001/sslab/test.txt",O_RDWR,0777);
		printf("In child! \n");
		//lseek(fd,SEEK_CUR,0);
		char buff[20]="\nHi I am child \n";
		write(fd,&buff,sizeof(buff));
	}
	return 0;
}

//you can check the file test.txt for the messages from parent and child
