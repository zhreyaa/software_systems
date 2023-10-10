/*

MT2023179 SHREYA CHAVAN

Question : 29

Write a program to remove the message queue.

Date: 15th September, 2023.

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main() {
    key_t key;
    int msgid;
    key = ftok(".", 'B');
    msgid = msgget(key, 0666);
    msgctl(msgid, IPC_RMID, NULL);
    printf("Message Queue removed successfully.\n");
    return 0;
}

