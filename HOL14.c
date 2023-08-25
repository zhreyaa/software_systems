#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	int flags,accessmode;
	int fd=open("test.txt",O_WRONLY);
	flags=fcntl(fd,F_GETFL);
        if(flags==-1)
	      exit(0);
if(flags & O_SYNC)
printf("Writes are synchronized\n");

accessmode=flags&O_ACCMODE;
if(accessmode==O_RDONLY)
	printf("File is READ only\n");
else if(accessmode==O_WRONLY||accessmode==O_RDWR)
	printf("File is writable\n");

return 0;
}


