#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main (void){

    pid_t pid;


    pid = fork();

    if(pid < 0){
        printf("fork error\n");
        return 1;
    }

    else if(pid == 0){
        printf("Child process PID : %d\n",(int)getpid());
        printf("Child process PPID : %d\n",(int)getppid());

        sleep(1);

        printf("Child exiting with status : 7\n");

        exit(7);
    }
    else{
        
        
        printf("Parent process PID : %d\n",(int)getpid());
        printf("Parent process PPID : %d\n",(int)getppid());

        exit(0);
    }

    return 0;
}