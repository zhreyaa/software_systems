#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
int fd1 = open("/home/shreya2001/test.txt", O_RDWR);
int mode = fcntl(fd1, F_GETFL,0);
printf("File mode : %d \n",mode);

close(fd1);
}
