// Lector escritor, El lector tiene prioridad
// Compilar: gcc 04LecEsc.c -lpthread 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define DIM 4
int nlec = 3;
sem_t slec, sesc;
void realizar_lect(){
	int i, tiempo = 10000 +rand()&1000;
	for(i=0; i<tiempo;i++);		// consume tiempo
}
void realizar_escr(){
	int i, tiempo = 10000 +rand()&1000;
	for(i=0; i<tiempo;i++);		// consume tiempo
}
void lector(){
	for(int i=0; i < DIM; i++){
		sem_wait(&slec);
		nlec++;
		if (nlec==1) sem_wait(&sesc);
		sem_post(&slec);
		realizar_lect();
		sem_wait(&slec);
		nlec--;
		if (nlec==0) sem_post(&sesc);
		sem_post(&slec);
		printf("Lector      %d\n", nlec);
	}
}
void escritor(){
	for(int i=0; i < DIM; i++){
		sem_wait(&sesc);
		realizar_escr();
		sem_post(&sesc);
		printf("Escritor\n");
	}
}
int main() {
	pthread_t lec, esc;
	sem_init(&slec, 0, 1);				// inicia el semáforo (&slec, compartidoEntreProcesos=no, inicio=1)
	sem_init(&sesc, 0, 1);				// inicia el semáforo (&sesc, compartidoEntreProcesos=no, inicio=1)
	printf("Proceso\t   nlec\n");
	pthread_create(&lec, NULL, (void *)lector,  NULL);
	pthread_create(&esc, NULL, (void *)escritor, NULL);
	pthread_join(lec, NULL);
	pthread_join(esc, NULL);
}
/*
SALIDA
Proceso	   nlec
Escritor
Escritor
Escritor
Escritor
Lector      3
Lector      3
Lector      3
Lector      3
*/