#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int fd = open("io.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE); // exit(1);
    }
    char buffer[1024];
    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        exit(EXIT_FAILURE); // exit(1);
    }else if(pid == 0){
        strcpy(buffer, "This is a test message from child process\n");
    }else{
        sleep(1);
        strcpy(buffer, "This is a test message from parent process\n");
    }
    ssize_t byte_write = write(fd, buffer, strlen(buffer));
    if (byte_write == -1) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE); // exit(1);
    }
    printf("write success\n");
    close(fd);
    if(pid == 0){
        printf("child process exit\n");
    }else{
        printf("parent process exit\n");
    }
    return 0;

}