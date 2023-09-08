/*
SHREYA CHAVAN MT2023179

Question 10:

Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.

*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){

              int fd=open("dump_file",O_CREAT|O_RDWR,0774);

              write(fd,"Program 10\n",strlen("Program 10\n"));

              off_t value=lseek(fd,10,SEEK_CUR);

              write(fd,"End of the program\n",strlen("End of the program\n"));

              printf("Return value of lseek:%ld\n",value);
              
	      return 0;
}

//after compiling and running use od -c dump_file to check the empty spaces in between the data
