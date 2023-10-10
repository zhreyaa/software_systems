/*

MT2023179 SHREYA CHAVAN

Question : 20

Write two programs so that both can communicate by FIFO -Use one way communication.

Date: 1st September, 2023.

*/

//Writer
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
int main() 
{
    mkfifo("20fifo", 0666);
    int fd = open("20fifo", O_WRONLY);
    const char *message = "Hello, FIFO!";
    write(fd, message, strlen(message));
    printf("Writer process sent: %s\n", message);
    close(fd);
    return 0;
}

