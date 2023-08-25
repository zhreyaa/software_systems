#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	printf("%d \n",getpid());
	int fd1,fd2,fd3,fd4;
	fd1=open("file2",O_RDWR | O_CREAT);
	fd2=dup(fd1);

	printf("\n Values of fd1 and fd2 are : %d  %d", fd1, fd2);


	fd3 = dup2(fd2,10);

	printf("\n Values of fd2 and fd3 are : %d  %d", fd2, fd3);


	fd4=fcntl(fd1,F_DUPFD);
	printf("\n Values of fd1 and fd4 are : %d  %d ", fd1, fd4);

	return 0;
}
