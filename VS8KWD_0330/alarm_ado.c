#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char **argv)
{
    int pid;
    if (argc < 1){
        perror("Hiba");
        exit(1);
    }
    pid = atoi(argv[1]);
    kill(pid, SIGALRM);
}
