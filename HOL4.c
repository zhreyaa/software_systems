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
