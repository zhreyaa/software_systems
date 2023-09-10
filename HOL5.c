/*
SHREYA CHAVAN MT2023179

Question 5:

Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.

Date: 28th August 2023

*/

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

// execute the program in the background using ./a.out & 
// then use ls -la/proc/pid/fd for the file descriptor table
