/*

MT2023179 SHREYA CHAVAN

Question : 19

Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
d. mknod system call
e. mkfifo library function

Date: 1st September, 2023.

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    if (mkfifo("fifo", 0666) == -1) {
        perror("fifo");
        exit(EXIT_FAILURE);
    }

    return 0;
}

