#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char ** argv) {
    char* arr[2];
    arr[0] = argv[1];
    arr[1] = argv[2];
    int pid = 0;
    pid_t pidls[256];
    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            pid = fork();

        }   
        if (pid == 0) {
            execl(arr[i], arr[i], i, NULL);
        } else {
            pidls[i] = pid;
            if ((i != 0) && (i < 1)) pid = fork();
        }
    }
    return 0;
}