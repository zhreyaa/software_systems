/*
SHREYA CHAVAN MT2023179

Question 9:

Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change

Date: 28th August 2023

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main ()
{
	struct stat s;
	stat("/home/shreya2001/test.txt", &s);
	printf("\nFile test.txt Details : \n");
	printf("Inode no : %ld \n",s.st_ino);
	printf("No of hardlinks : %ld \n",s.st_nlink);
	printf("User ID : %d \n",s.st_uid);
	printf("Group ID : %d \n",s.st_gid);
	printf("Size : %ld \n",s.st_size);
	printf("Block Size: %ld \n",s.st_blksize);
	printf("No of Blocks : %ld \n",s.st_blocks);
	printf("Time of last access : %ld \n",s.st_atime);
	printf("Time of last modification : %ld \n",s.st_mtime);
	printf("Time of last change : %ld \n",s.st_ctime);
	return 0;
}
