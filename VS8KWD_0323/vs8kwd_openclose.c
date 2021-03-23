#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void fseek_filesize(const char *filename)
{
    FILE *fp = NULL;
    long off;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Hibás megnyitás %s\n", filename);
        exit(EXIT_FAILURE);
    }

    if (fseek(fp, 0, SEEK_END) == -1)
    {
        printf("Hibás fseek ugrás %s\n", filename);
        exit(EXIT_FAILURE);
    }

    off = ftell(fp);
    if (off == -1)
    {
        printf("Ftell hiba %s\n", filename);
        exit(EXIT_FAILURE);
    }

    printf("fseek_filesize - Fáljnév: %s, Méret: %ld byte\n", filename, off);

    if (fclose(fp) != 0)
    {
        printf("Sikertelen bezárás %s\n", filename);
        exit(EXIT_FAILURE);
    }
}

void seek_filesize(const char *filename)
{
    int fd;
    off_t off;

    if (filename == NULL)
    {
        printf("Hibás név\n");
        exit(EXIT_FAILURE);
    }

    fd = open(filename, O_RDONLY, S_IRUSR | S_IRGRP);
    if (fd == -1)
    {
        printf("Hiba a megnyitás során %s\n", filename);
        exit(EXIT_FAILURE);
    }

    off = lseek(fd, 0, SEEK_END);
    if (off == -1)
    {
        printf("Lseek hiba %s\n", filename);
        exit(EXIT_FAILURE);
    }

    printf("seek_filesize - Fájlnév: %s, Méret: %lld byte\n", filename, (long long) off);

    if (close(fd) == -1)
    {
        printf("Nem sikerült a bezárás %s\n", filename);
        exit(EXIT_FAILURE);
    }
}

int
main(int argc, const char *argv[])
{
    int i;
    for(i = 0; i < argc; i++)
    {
        seek_filesize(argv[i]);
        fseek_filesize(argv[i]);
        printf("%s \n", argv[i]);
    }

    return 0;
}
