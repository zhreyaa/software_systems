#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
int main (int argc, char* argv[])
{

	char buf;
	int i=0;
	int w=0;
	if(argc!=3)
	{
		printf("You didn't give enough args!");
	}
	int fd_r = open(argv[1], O_RDONLY);
	int fd_w = open(argv[2],O_WRONLY | O_CREAT,0744);
	if(fd_r ==-1 || fd_w==-1)
	{
		printf("Kyu nahi khuli file kya pata ! ");
	}
	i = read(fd_r, &buf, 1);
	while(i)
	{
		w = write(fd_w, &buf, 1);
		i = read(fd_r, &buf ,1);	
	}

	return 0;
}
