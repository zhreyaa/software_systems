#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int i;
	int count = 10;
	int buf[10];
	// reading in stdin fd = 0
	i=read(0, buf, count);
	printf("\nValue of i : %d \n ", i);
              
	// writing on stdout fd = 1
	write(1,buf,count);


	return 0;
}
