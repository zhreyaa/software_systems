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
