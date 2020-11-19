#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <memory.h>

#define SIZE 4096

/*
* cp 的简单实现
*/
int main(int argc, char **argv)
{

    if (argc < 3)
    {
        printf("cpp source_file destination_file");
        exit(1);
    }

    int fd_src, fd_dst, len;
    char buf[SIZE];
    umask(0);

    fd_src = open(argv[1], O_RDONLY);
    fd_dst = open(argv[2], O_RDWR | O_EXCL | O_CREAT, 0775);

    if (fd_src == -1)
    {
        printf("src file reaf failed !");
        exit(-1);
    }

    if (fd_dst == -1)
    {
        printf("dst file open  failed !");
        exit(-1);
    }

    while ((len = read(fd_src, buf, SIZE)) > 0)
    {
        if (write(fd_dst,buf, len) < 0)
        {
            printf("dst file write   failed !");
            break;
        }
        memset(buf, 0, SIZE);
    }

    if (len == 0)
    {
        printf("all work done !!");
    }

    close(fd_src);
    close(fd_dst);

    return 0;
}