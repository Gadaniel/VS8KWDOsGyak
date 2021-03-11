#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>
#include <sys/types.h>
int main()
{
    int ertek;
    pid_t status;
    status = fork();
    if(status == 0){
        exit(69);
    } else {
        perror("Hiba történt!");
    }
    if (WIFEXITED(ertek) == 1){
        printf("Visszateresi ertek: %d", WEXITSTATUS(ertek));
    }
    /// A többit feladat:
	/// Abort:
	/*if(status == 0){
        abort();
    } else {
        perror("Hiba történt!");
    }
    if(WIFSIGNALED(ertek) == 1){
        printf("Visszateresi ertek: %d", WTERMSIG(ertek));
    }*/
	/// 0-val való osztás:
    /*if(status == 0){
        int x = 2;
        int y = 0;
        x = x / y;
    } else {
        perror("Hiba történt!");
    }
    if(WIFSIGNALED(ertek) == 1){
        printf("Visszateresi ertek: %d", WTERMSIG(ertek));
    }*/

    return 0;
}
