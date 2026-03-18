#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main(int argc, char *argv[]){
    char *data;

    int key = ftok("/media/a2625288/home/SO/Pipe/ex2.c", 'A');
    int shmid = shmget(key, 50*sizeof(char), IPC_CREAT | 0644);
    
    data = shmat(shmid, 0, 0);

    if((argc > 1) && (strcmp(argv[1], "apagar"))){
        strcpy(data, argv[1]); 
    }else if((argc > 1) && (!strcmp(argv[1], "apagar"))){
        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);
    }
    else{
        printf("-> %s\n", data);
    }

    return 0;
}