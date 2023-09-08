/*
SHREYA CHAVAN MT2023179

Question 25:

Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).

*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
pid_t p;
printf("Before fork\n");
p=fork();

if(p==0)
{
printf("I am child1 with pid %d\n", getpid());
printf("I am child1, My parentid is %d\n", getppid());
}

else
{
pid_t q;
printf("Inside second child who becomes parent\n");
q=fork();

if(q==0)
{
printf("I am child2 with pid %d\n", getpid());
printf("I am child2, My parentid is %d\n", getppid());
}

else
{
pid_t r;
printf("Inside second parent\n");
r=fork();

if(r==0)
{
        sleep(10);
printf("I am third child with pid %d\n", getpid());
printf("I am third child, My parentid is %d\n", getppid());
printf("My third child is completed\n");
}

else
{
        waitpid(r,WIFEXITED(2), WCONTINUED);
printf("I am parent of all %d\n", getpid());
}
}
}
return 0;
}


