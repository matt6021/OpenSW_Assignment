#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc,char *argv[]){

    int i;

    if(argc < 2){
        printf("Usage : %s [file1 name]...\n",argv[0]);
        return 1;
    }
    
    for(i = 1;i < argc;i++){
        int fd;

        fd = open(argv[i],O_RDONLY);

        if(fd == -1){
            perror(argv[i]);
        }else{
            printf("open success : %s\n",argv[i]);
            close(fd);
        }
    }

    return 0;
}