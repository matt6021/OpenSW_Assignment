#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc,char *argv[],char *envp[]){
    pid_t pid;
    int status;

    if(argc < 2){
        printf("Usage: ./03_execve <program path> [OPTION]...\n");
        return 1;
    }

    pid = fork();

    if(pid < 0){
        perror("fork");
        return 1;
    }

    else if(pid == 0){
        execve(argv[1],&argv[1],envp);

        perror("execve");
        _exit(1);
    }

    else{
        if(waitpid(pid,&status,0) == -1){
            perror("waitpid");
            return 1;
        }

        if(WIFEXITED(status)){
            printf("Child exited with status : %d\n",WEXITSTATUS(status));
        }else{
            printf("Child did not terminate normally\n");
        }
    }

    return 0;
}