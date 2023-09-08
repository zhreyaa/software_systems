/*
SHREYA CHAVAN MT2023179

Question 17:

Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.

*/

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,fd;
	struct
	{
                int ticket_no;
	}db;
        
	printf("Enter ticket number: ");
	scanf("%d",&db.ticket_no);
	fd=open("db", O_CREAT|O_RDWR,0744);
        write(fd,&db,sizeof(db));
	close(fd);
	fd=open("db",O_RDONLY);
	read(fd,&db,sizeof(db));
	printf("Ticket no: %d\n",db.ticket_no);
	close(fd);
}

