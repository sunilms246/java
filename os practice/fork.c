#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
    pid_t pid = fork();
    if(pid < 0){
        printf("Fork faild");
        exit(1);
    }
    else if(pid == 0){
        printf("\nCild proccess id :%d", getpid());
        execl("./abc", "./abc", NULL);
    }
    else{
        wait(NULL);
        printf("Child process complete\nParent process id:%d", getpid());
    }
    return 0;
}