#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(){
    if (signal(SIGALRM, Alarm) == SIG_ERR){
        printf("Hibas handler \"SIGALRM\"!\n");
        return 1;
    }
    pause();
    return 0;
}

void Alarm(int sig);
void Alarm(int sig){
    printf("VS8KWD\nFelszabaditva\n");
    exit(1);
}
