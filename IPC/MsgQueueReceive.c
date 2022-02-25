// https://dextutor.com/program-for-ipc-using-message-queues/
#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>

struct msgbuf
{
    long mtype; // mtype, must be a nonzero positive value that can be used by the receiving process for message selection
    char mtext[30];
};

int main()
{
    struct msgbuf m;
    int msgid = msgget(124, IPC_CREAT | 0666);
    m.mtype = 1;
    msgrcv(msgid, &m, 30, 1, 0);
    printf("Message re.=> %s \n", m.mtext);
}