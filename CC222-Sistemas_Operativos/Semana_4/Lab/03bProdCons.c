// Productor Consumidor con buffer infinito
// Sincronizado
// Compilar: gcc 03bProdCons.c -lpthread 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define DIM 6
int v[DIM], inicio=0, fin=0;
sem_t sem = 1;
int producir(){
	int i, tiempo = 10000 +rand()&1000;
	for(i=0; i<tiempo;i++);		// consume tiempo
	return 10 + rand()%20;
}
int procesar(int y){
	int i, tiempo = 120000 +rand()&1000;
	for(i=0; i<tiempo;i++);		// consume tiempo
	return y + rand()%25;
}
void productor(){
	int x; 
	for(int i=0; i < DIM; i++){
		x= producir();
		sem_wait(&sem);		// resta 1 y bloquea el segmento crítico entrante
		v[fin] = x;
		fin++;
		sem_post(&sem);		// suma 1 y libera el segmento crítico actual
		printf("Productor    %d\t\t%d\t%d\n", x, inicio, fin);
	}
}
void consumidor(){
	int y;
	for(int i=0; i < DIM; i++){
		while (inicio==fin){}		// espera activa
		sem_wait(&sem);				// resta 1 y bloquea el segmento crítico entrante
		y = v[inicio];
		inicio++;
		sem_post(&sem);				// suma 1 y libera el segmento crítico actual
		procesar(y);
		printf("Consumidor   %d\t\t%d\t%d\n", y, inicio, fin);
	}
}
	
int main() {
	for(int i=0; i<DIM;i++) v[i]=0;	// v[i] = 0
	pthread_t prod, cons;				// define 2 threds
	sem_init(&sem, 0, 1);				// inicia el semáforo (&s, compartidoEntreProcesos=no, inicio=1)	

	printf("Proceso\t   Producto  Inicio    Fin\n");
	pthread_create(&prod, NULL, (void *)productor,  NULL);
	pthread_create(&cons, NULL, (void *)consumidor, NULL);
	pthread_join(prod, NULL);
	pthread_join(cons, NULL);
}
/*
SALIDA
Proceso	  Producto  Inicio    Fin
Productor    16		  0		  1
Productor    25		  0		  2
Productor    25		  0		  3
Consumidor   16		  1		  3
Consumidor   25		  2		  4
Productor    11		  1		  4
Productor    16		  3		  5
Productor    16		  3		  6
Consumidor   25		  3		  4
Consumidor   11		  4		  6
Consumidor   16		  5		  6
Consumidor   16		  6		  6
*/


