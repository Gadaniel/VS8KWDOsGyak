#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(){
    if (signal(SIGTERM, Term) == SIG_ERR){
        printf("Hibas handler \"SIGTERM\"!\n");
        return 0;
    }

    while(1){
        printf("Pill...\n");
        sleep(3);
    }

    return 0;
}

void Term(int sig);
void Term(int sig){
    signal(sig, SIG_IGN);
    printf("SIGTERM signal: %d\n", sig);
}
