#include<stdio.h>
#include<fcntl.h>

int main()
{
	int f1,f2,f3,f4,f5;
	f1 = open("F1",O_CREAT|O_RDONLY | O_EXCL);
	f2 = creat("F2",O_RDONLY | O_EXCL);
	f3 = creat("F3",O_RDWR | O_EXCL);
	f4 = creat("F4",O_RDWR | O_EXCL);
	f5 = creat("F5",O_RDWR | O_EXCL);
	printf("%d",f1);
	while(1);

	return 0;
}
