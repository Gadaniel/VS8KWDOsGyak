#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    signal(SIGALRM, myVoid);
    printf("Varakozok az alarmra.");
    pause();
    printf("Megjott az alarm.");
    return 0;
}

void myVoid();
void myVoid() {}
