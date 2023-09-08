/*
SHREYA CHAVAN MT2023179

Question 27:

Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp

*/

#include <unistd.h>
#include <stdio.h>

int main()
{
	char *const envp[2] = {"STEPLIB=SASC.V6.LINKLIB", NULL};	
        execlp("ls","ls","-l","-R",(char*) NULL);
	execl("/usr/bin/ls","ls","-R",(char*) NULL);
	execle("/usr/bin/ls","ls","-R",(char*) NULL,envp);
	char *arg[5];
	arg[0]="ls";
	arg[1]="-l";
	arg[2]="-R";
	arg[3]=NULL;
	execv("/usr/bin/ls",arg);
	execvp("/usr/bin/ls",arg);	
	return 0;
}
