#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
int main()
{
	int x= creat( "filex",O_RDONLY);
	if(x==-1)
		perror("Failed");
	else
		printf("%d",x);
	return 0;

}
