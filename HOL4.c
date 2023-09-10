/*
SHREYA CHAVAN MT2023179

Question 4:

Write a program to open an existing file with read write mode. Try O_EXCL flag also.

Date: 28th August 2023

*/

#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd=-1;
	fd = creat("/home/shreya2001/sslab/newfile2.txt",O_RDWR | O_EXCL | O_CREAT);
	//printf("%d \n", fd);
	if(fd>=0)
	{
		printf("\n File created successfully ! ");
	}
	else
	{
		printf("\n Error occured !");
	}

	return 0;

}

