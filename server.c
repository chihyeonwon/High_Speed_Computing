#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

typedef struct {
   char s; // semaphore
   int sum;
} SHM;

main(int argc, char*argv[])
{
   int shm_id;
   void *shm_addr;
   SHM *shm;
   int key;
   int sum;

   sum = 0;

   if(argc != 2) {
      printf("usage: %s key\n", argv[0]);
      exit(1);
   }

   key = atoi(argv[1]);

   shm_id = shmget(key, sizeof(SHM), IPC_CREAT|0666);
   
   shm_addr = shmat(shm_id, 0, 0);
   
   shm = (SHM *)shm_addr;
   
   // Initialize the shared memory
   shm->s = 1;
   shm->sum = 0;

   do {
      // Wait semaphore to be available
      while(shm->s <= 0);
      
      sum = sum + 1;
      shm->sum = shm->sum + sum;
      
      shm->s = shm->s - 1;
      
   } while(shm->s >=0);

   shmdt((void *)shm_addr);
   
   shmctl(shm_id, IPC_RMID, 0);
   

   exit(0);
}

