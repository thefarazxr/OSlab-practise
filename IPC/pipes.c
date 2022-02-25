#include <stdio.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pip[2];
    pipe(pip); // creates a unidirectional pipe with two end pip[0] and pip[1]
               //  pip[0] -> for READING && pip[1] -> for WRITING
    char receiver_string[30];

    int p = fork();
    if (p > 0) // PARENT
    {
        printf("Hi I'm the PARENT and I'll send your message to my CHILD!\n");
        write(pip[1], "Hey kiddoo!", 20);  // pip[1] for WRITING
        wait(NULL);                        // use wait() here to let the parent know to not exit!
        read(pip[0], receiver_string, 20); // pip[0] for READING
        printf("PARENT : Message Received from CHILD= %s \n", receiver_string);
    }

    if (p == 0)
    {
        printf("Hi I'm his CHILD and I'll send your message to my PARENT!\n");
        read(pip[0], receiver_string, 20); // pip[0] for READING
        printf("CHILD : Message Received from PARENT= %s \n", receiver_string);
        write(pip[1], "Hey DAADDD!", 20); // pip[1] for WRITING
    }
}