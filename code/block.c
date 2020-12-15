#include  <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    char buf[1024];
    int n = 0;

    n = read(STDIN_FILENO, buf, 10);
    if (n < 0) {
        perror("Invalid STDFILENO");
        exit(1);
    }
    write(STDOUT_FILENO, buf, n);


    return 0;

}
