/*  	CONDICION DE CARRERA
Se crean y ejecutan 10 threads (=procesos) que suman 100 cada uno, se espera Suma= 1000, y es así.

Compilar: gcc 01bRecCom.c -lpthread 
 
SALIDAS: Suma; esperamos que Suma= 1000; SI es así:
Suma=1000
Suma=1000
...
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUMTH 10
int suma_total = 0;			// todos los threads comparten suma_total
void suma() {
	int i;
	for (i=0;i<100000;i++); // consumidor de tiempo
	suma_total +=100;
}
int main() {
	pthread_t th[NUMTH];
	int i;
	for (i=0;i<NUMTH;i++) pthread_create(&th[i], NULL, (void *)suma, NULL); // crea 10 threads para ejecutar suma
	for (i=0;i<NUMTH;i++) pthread_join(th[i], NULL);								// Se ejecutan los 10 threads
	printf("Suma=%d\n", suma_total);
}