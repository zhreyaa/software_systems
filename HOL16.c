/*
SHREYA CHAVAN MT2023179

Question 16:

Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock

*/

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	struct flock lock;
	int fd;
	fd=open("test.txt",O_RDWR);
	lock.l_type = F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_pid=getpid();
	printf("before entering the critical section  \n");
	    
	fcntl(fd,F_SETLKW,&lock);

	printf("Inside the critical seciton  \n");
	printf("Enter to unlock  \n");
	getchar();
	printf("unlocked \n");
	lock.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("finish\n");
	return 0;
}

//use different terminals and see how you cannot access the critical section when a process is already accesing it

