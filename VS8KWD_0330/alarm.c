#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
int main()
{
    unsigned sec = 1;
    signal(SIGINT, myInt);
    int i;
    for(i = 1; i<8; i++){
        alarm(sec);
        signal(SIGALRM, myVoid);
        printf("Varakozasi ido: %d\n", i);
        pause();
    }
    return 0;
}

void myVoid();
void myVoid(){
    printf("Nincs valasz!");
}

void myInt();
void myInt(){
    printf("Van int valasz!");
    signal(SIGINT, SIG_IGN);
}
