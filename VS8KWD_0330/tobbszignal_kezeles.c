#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

unsigned int Interrupts = 0;

int main(void)
{
    if (signal(SIGINT, InterruptHandler) == SIG_ERR){
        printf("Hibas handler \"SIGINT\"\n");
        return 0;
    }

    if (signal(SIGQUIT, QuitHandler) == SIG_ERR){
        printf("Hibas handler \"SIGQUIT\"\n");
        return 0;
    }

    while(Interrupts < 2){
        printf("Varakozas\n");
        sleep(1);
    }

    printf("Megerkezett a \"SIGINT\"");
    return 0;
}

void InterruptHandler(int sig);
void InterruptHandler(int sig){
    printf("SIGINT signal: %d\n", sig);
    Interrupts++;
}

void QuitHandler(int sig);
void QuitHandler(int sig){
    printf("SIGQUIT signal: %d\n", sig);
}
