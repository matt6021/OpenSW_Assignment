#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main (void){

    pid_t pid;
    int status;

    pid = fork();

    if(pid < 0){
        printf("fork error\n");
        return 1;
    }

    else if(pid == 0){
        printf("Child process PID : %d\n",(int)getpid());
        printf("Child process PPID : %d\n",(int)getppid());
        exit(7);
    }
    else{
        waitpid(pid,&status,0);

        if(WIFEXITED(status)){

            int code = WEXITSTATUS(status);    
            printf("Child exited with status : %d\n",code);    
        }
        printf("Parent process PID : %d\n",(int)getpid());
        printf("Parent process PPID : %d\n",(int)getppid());
    }

    return 0;
}