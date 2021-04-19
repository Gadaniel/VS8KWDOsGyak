#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define SIZE 64

int main() {
    int num[2];
    int pid;
    char buff[SIZE];
    if (pipe(num) == -1) {
        perror("Hiba");
        exit(-1);
    }
    pid = fork();
    if (pid == -1) {
        perror("Hiba");
        exit(-1);
    }
    if (pid == 0) {
        printf("Child %d\n", getpid());
        close(num[0]);
        strcpy(buff, "VS8KWD\0");
        write(num[1], buff, sizeof(buff));
        close(num[1]);
    } else {
        printf("Parent%d\n", getpid());
        close(num[1]);
        while (read(num[0], buff, sizeof(buff)) > 0) {
            printf("%s", buff);
        }
        printf("\n");
        close(num[0]);
    }
    wait(NULL);
    return 0;
}