#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

typedef struct {
    char s;  // Define a semaphore
    int sum;
} SHM;

int main(int argc, char *argv[]) {
    int shm_id;
    void *shm_addr;
    SHM *shm;
    int key;
    
    int data;
    
    int sum;


    if (argc != 3) {
        printf("Usage: %s key data\n", argv[0]);
        exit(1);
    }

    key = atoi(argv[1]);
    data = atoi(argv[2]);

    // Attach to the existing semaphore and shared memory segment
    shm_id = shmget(key, sizeof(SHM), IPC_CREAT|0666);
  

    shm_addr = shmat(shm_id, 0, 0);

    shm = (SHM *)shm_addr;
    
    if(data < 0) {
       shm->s = data;
    } else {
       shm->s = 1;
       shm->sum = data;
    }

    // Exit gracefully
    exit(0);
}
