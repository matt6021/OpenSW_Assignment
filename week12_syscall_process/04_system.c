#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h> 

int mysystem(const char *command){

    pid_t pid;
    int status;

    if(command == NULL){
        return 1;
    }

    pid = fork();

    if(pid < 0){
        return -1;
    }

    else if(pid == 0){

        execl("/bin/sh","sh","-c",command,(char *)0);

        _exit(127);

    }
    else{
        
        if(waitpid(pid,&status,0) < 0){
            return -1;
        }
           return status;
        
    }

}

int main (void){

    mysystem("ls -l | wc -l");
    mysystem("find . -name '*.c'");

    printf("Good Bye~\n");

    return 0;
}