#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>
#include <sys/types.h>
int main()
{
    pid_t status;
    status = fork();
    if(status == 0){
        execlp("date", "child", NULL);
    } else {
        perror("Valami hiba történt");
    }
    return 0;
}
