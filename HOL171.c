#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{

struct
        {
               
                int ticket_no;
        }db;

int fd,input;
fd=open("db",O_RDWR);

        struct flock lock;
        lock.l_type=F_WRLCK;
        lock.l_whence=SEEK_SET;        
        lock.l_start=(input-1)*sizeof(db);
        lock.l_len=sizeof(db);
        lock.l_pid=getpid();

printf("Before entering the critical section \n");
fcntl(fd,F_SETLKW,&lock);
printf("Inside the critical section \n");

read(fd,&db,sizeof(db));
printf("Current ticket number: %d\n",db.ticket_no);
db.ticket_no++;

lseek(fd,0,SEEK_SET);
write(fd,&db,sizeof(db));

printf("Press enter to unlock\n");
getchar();

lock.l_type=F_UNLCK;
fcntl(fd,F_SETLK,&lock);
printf("Exited critical section\n");

}
