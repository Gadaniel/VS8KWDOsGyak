#include <stdio.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NAME "VS8KWD"
#define SIZE 64

int main() {
    pid_t pid;
    int fifo;
    int fopen;
    char buff[SIZE];

    pid = fork();
    if (pid == -1) {
        perror("Hiba");
        exit(-1);
    }
    if (pid == 0) {
        printf("Child: %d\n", getpid());
        fopen = open(NAME, O_RDWR);
        if (fopen == -1) {
            perror("Hiba");
            exit(-1);
        }
        strcpy(buff, "VS8KWD\0");
        write(fopen, buff, SIZE);    
        close(fopen);
		exit(1);
	} else {
        printf("Parent: %d\n", getpid());
        fifo = mkfifo(NAME, 0666);
        if (fifo == -1) {
            perror("Hiba");
            exit(-1);
        }
        close(fifo);
		wait(NULL);
        printf("Parent: %d\n", getpid());
        fopen = open(NAME, O_RDWR);
        if (fopen == -1) {
            perror("open()");
            exit(-1);
        }
        printf("0\n");
        while (read(fifo, buff, SIZE) > 0) {
            printf("%s", buff);
        }
        printf("\n");
        close(fopen);
        unlink(NAME);
        exit(1);
	}
    return 0;
}