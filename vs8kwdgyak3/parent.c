#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
    pid_t pid;
    pid = fork();
    if(pid == 0){
        execl("./child.out", "child", NULL);
    }
    return 0;
}
