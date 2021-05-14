#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdlib.h>
#include<unistd.h>
#define SHMKEY 67L
#define KEY 41L
#define PERM 00666

int main()
{
	int shmid;		
	key_t key;		
	int size=512;		
	int shmflg;		
struct vmi {
		int  hossz;
		char szoveg[512-sizeof(int)]; 
	} *segm;
	key = SHMKEY; 

	shmflg = 0; 
	if ((shmid=shmget(key, size, shmflg)) < 0) { 
	   printf("Nincs meg szegmens! Keszitsuk el!\n");
	   shmflg = 00666 | IPC_CREAT; 
	   if ((shmid=shmget(key, size, shmflg)) < 0) {
		  
	      perror("Az shmget() system-call sikertelen!\n");
	      exit(-1);
	   }
	} else printf("Van mar ilyen shm szegmens!\n");

	printf("\nAz shm szegmens azonositoja %d: \n", shmid);
	shmflg = 00666 | SHM_RND;	
	segm = (struct vmi *)shmat(shmid, NULL, shmflg);

	if (segm == (void *)-1) {
		perror("Sikertelen attach!\n");
		exit(-1);
	}
	
	
	


int 	id; 
 
	if ((id = semget(KEY, 1, 0)) < 0) { 
		if ((id = semget(KEY, 1, PERM | IPC_CREAT)) < 0) { 
		 	perror(" A szemafor nem nyitható meg. "); 
			exit(-1);
		}
	}
	else    {
		perror(" Már létezik a szemafor. ");
		exit(0);
	}

	if (semctl(id, 0, SETVAL, 1) < 0) { 

		perror(" Nem lehetett inicializálni. ");
	} else {
		puts(" Kész és inicializált a szemafor. ");
	}
	struct sembuf up[1]  =  {0,  1, SEM_UNDO}; 
struct sembuf down[1] = {0, -1, SEM_UNDO};
puts(" Itt fut a nem kritikus szakasz. ");

	semop(id, down, 1);  

	puts("    Itt fut a kritikus szakasz. "); 
	strcpy(segm->szoveg,"valami szoveg benne"); 
	sleep(3);
	semop(id, up, 1);    
	puts(" Itt ismet nem kritikus szakasz fut. ");
	if (semctl(id, 0, IPC_RMID, 0) < 0) { 

		perror(" Nem siker�lt t�r�lni.");
		exit(-1);
	}

	puts(" A szemafort megszuntettuk. \n");
	shmdt(segm);
	return 0;
	}
	
	
