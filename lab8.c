#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int MAX = 10;
int JAR = 0; // CRITICAL SECTION VARIABLE

int animalCount = 3;
int put = 2;
int eat = 3;


sem_t semEmpty;		// the semaphore for controlling the access of bees to honey jar.
					// bees lock it because they consume "empty space"; for a bee to produce honey there should be some empty space (think of it as 'bees consume empty space')
					// bears unlock it because they produce "empty space"; when they eat honey, maybe there will be enough empty space for a bee to produce honey.

sem_t semFull;		// the semaphore for controlling the access of bears to honey jar.
					// bears lock it because they consume "honey"; for a bear to consume honey there should be some honey.
					// bees unlock it because they produce "honey"; when they produce, maybe there will be enough honey for a waiting bear.

pthread_mutex_t mutex;	// the mutex to control the access of a singular animal - bee or bear.
						// the semaphores allowed either bears or bees to access honey jar. if bees are allowed, bears wait outside. if bears are allowed, bees wait outside.
						// but what happens if multiple bees or multiple bears tries to access the jar at the same time? because they probably will try that!
						// to ensure that only ONE animal access the jar, we use a mutex lock.
						// mutex can only be unlocked by the animal that locks it! when the bee or bear is done in critical section, it should unlock the mutex.
						
						// to summarize: semaphores determine which type of animal will access the jar.
						// mutex determines which animal will access the jar. only a single animal is allowed to access the jar.


void *bee(void *vargp){
	
	int sleep_time;
	int index = *((int *)vargp);
	printf("\n hello. i am bee #%d :| \n", index);		// another day, another dolla'

	while(1){

		sem_wait(&semEmpty);		// wait for an empty space. if there is empty space in jar, then continues. tell bears to stay out!
		pthread_mutex_lock(&mutex);	// tell other bees to stay out!

		if(JAR + put <= MAX){		// check the jar if there is enough space.
			JAR = JAR + put;		// produce honey
			printf("\n BEE #%d put %d portions of honey in the jar.\n JAR = %d \n", index, put, JAR);
		}
		else{
			printf("\n overflow risk!!! no honey produced \n");
		}
		
		pthread_mutex_unlock(&mutex);	// tell other bees that you are done and they can enter.
		sem_post(&semFull);				// tell bears that you produced some honey.
		
		sleep_time = 1 + rand() % 2;	// randomized sleep time. i randomized them hoping that the threads' running order may change.
		printf("\n BEE #%d is tired. sleeping for %d seconds... \n", index, sleep_time);
		sleep(sleep_time);				// sleep...zzz...bzzz...
	}
}


void *bear(void *vargp){
	
	int sleep_time;
	int index = *((int *)vargp);
	printf("\n hello. i am BEAR #%d :) \n", index);

	while(1){

		sem_wait(&semFull);				// wait for some honey. if there is honey in jar, then continue. tell bees to stay out!
		pthread_mutex_lock(&mutex);		// tell other bears to stay out!

		if(JAR - eat >= 0){				// check the jar if there is enough honey.
			JAR = JAR - eat;			// eat honey :)
			printf("\n BEAR #%d ate %d portions of honey.\n JAR = %d \n", index, eat, JAR);
		}
		else{
			printf("\n not enough honey to appease BEAR #%d's appetite :( \n", index);
		}

		pthread_mutex_unlock(&mutex);	// tell other bears that you are done and they can enter.
		sem_post(&semEmpty);			// tell bees that you ate some honey (i.e. there is some empty space now.)
		
		sleep_time = 1 + rand() % 3;	// randomized sleep time. i randomized them hoping that the threads' running order may change.
		printf("\n BEAR #%d is tired. sleeping for %d seconds... \n", index, sleep_time);
		sleep(sleep_time);				// sleep...
	}
}


int main(){

	int i;

	sem_init(&semEmpty, 0, animalCount);		// initialize semEmpty.
												// initialized to animalCount = 3. You can initialize to any non-negative integer.
												// i just wanted to give the bees a headstart. i advise you to try initializing to 1, 2, 0 and see what happens.
												
	sem_init(&semFull, 0, 0);					// initialize semFull.
												// initialized to 0 because i don't want any bear to enter yet. again, to give a headstart to bees.
												// similar to semEmpty, you can try other values.
												// IDEA!! give positive integers to semFull, and give 0 to semEmpty. see what happens :)
												
	pthread_mutex_init(&mutex, NULL);			// initialize mutex. we don't have any other initializing options here :)

	// i preferred to keep the animals in seperate arrays.
	pthread_t bees[animalCount];
	pthread_t bears[animalCount];

	// arrays to keep the thread arguments. these are just the "numbers" of animals to send into the threads: bee#1, bee#2...
	int bee_args[animalCount];
	int bear_args[animalCount];

	for(i=0; i<animalCount; i++){
		printf("\n creating bee #%d... \n", i);
		bee_args[i] = i;
		pthread_create(&bees[i], NULL, bee, (void *)&bee_args[i]);
		printf("\n creating bear #%d... \n", i);
		bear_args[i] = i;
		pthread_create(&bears[i], NULL, bear, (void *)&bear_args[i]);
	}


	// the following lines doesn't even have a chance to run in my PC. the threads never stop working on my computer.
	// nevertheless, it is good practice to write the closure methods :)
	
	for(i=0; i<animalCount; i++){
		pthread_join(bees[i], NULL);
		pthread_join(bears[i], NULL);
	}

    pthread_exit(NULL);

    sem_destroy(&semEmpty);
    sem_destroy(&semFull);
    pthread_mutex_destroy(&mutex);

    return 0;
}