#include <sys/fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("app filename");
        exit(-1);
    }

    int fd = open(argv[1], O_CREAT, 0775);
    if (fd == -1)
    {
        printf("File open failed !");
        exit(-1);
    }

    printf("%s created !", argv[1]);

    close(fd);

    return 0;
}