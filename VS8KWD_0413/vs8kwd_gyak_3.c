#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char **argv){
    int kill(pid_t pid, int sig);
    if(argc != 2){
        printf("./vs8kwd_gyak9_3 pid\n");
        return 1;
    }
    pid_t pid = (pid_t)atoi(argv[1]);
    kill(pid, SIGALRM);
    return 0;
}
