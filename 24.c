/*

MT2023179 SHREYA CHAVAN

Question : 24

Write a program to create a message queue and print the key and message queue id.

Date: 8th September, 2023.

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main() 
{
    key_t key;
    int msgid;
    key = ftok(".", 'B');
    msgid = msgget(key, 0666 | IPC_CREAT);
    printf("Key: %x\n", (unsigned int)key);
    printf("Message Queue ID: %d\n", msgid);
    return 0;
}

