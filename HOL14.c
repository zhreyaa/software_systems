/*
SHREYA CHAVAN MT2023179

Question 14:

Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.

Date: 28th August 2023

*/

#include<sys/select.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		perror("Not given proper file!");
		return -1;
	}

        argv[1];
        struct stat f_st;

	if(stat(argv[1],&f_st)==-1)
	{
		perror("Error in stat\n");
		return 0;
	}

	printf("%s \n",argv[1]);
	printf("%u\n",f_st.st_mode);

              switch (f_st.st_mode & S_IFMT) 
           {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
 	   }
return 0;
}


