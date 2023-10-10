/*

MT2023179 SHREYA CHAVAN

Question : 20

Write two programs so that both can communicate by FIFO -Use one way communication.

Date: 1st September, 2023.

*/

//Reader
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
int main()
{
    int fd = open("20fifo", O_RDONLY);
    char buffer[100];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    printf("Reader process received: %.*s\n", (int)bytesRead, buffer);
    close(fd);
    unlink("20fifo");
    return 0;
}

