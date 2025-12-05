#include <stdio.h>
#include <unistd.h>

int main (void){

    pid_t pid = getpid();

    while(1){
        printf("pid = %d\n",pid);
        sleep(1);
    }

    return 0;
}