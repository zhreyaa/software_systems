/*
SHREYA CHAVAN MT2023179

Question 20:

Find out the priority of your running program. Modify the priority with nice command.

Date: 10th September 2023

*/

#include<sys/types.h>
#include<sched.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/resource.h>
#include<sys/stat.h>


int main()
{
	int pid=getpid();
	int pr=getpriority(PRIO_PROCESS,pid);
	
	printf("Process ID is %d\n",pid);
	printf("Process priority is %d\n",pr);
        
        int updated_nice=nice(4);
	printf("Updated nice key: %d\n",updated_nice);
	int pr_updated=getpriority(PRIO_PROCESS,pid);
	printf("Updated process priority is %d\n",pr_updated);

	while(1);
	return 0;

}
