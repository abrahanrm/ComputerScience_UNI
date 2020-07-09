/*  	CONDICION DE CARRERA: recurso (una variable compartida)
Se crean y ejecutan) 10 threads (=procesos) que suman 100 cada uno, se espera Suma= 1000; pero no es así.

Compilar: gcc 01aRecCom.c -lpthread 
 
SALIDAS posibles: Suma; esperamos que Suma= 1000; pero no es así:
Suma=700
Suma=900
Suma=700
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUMTH 10
int suma_total = 0;										// todos los threads comparten suma_total
void suma() {
	int i;
	int suma=suma_total;
	suma = suma + 100;
	for (i=0;i<10000;i++); // consumidor de tiempo
	suma_total=suma;
}
int main() {
	pthread_t th[NUMTH];
	int i;
	for (i=0;i<NUMTH;i++) pthread_create(&th[i], NULL, (void *)suma, NULL); // crea 10 threads para ejecutar suma
	for (i=0;i<NUMTH;i++) pthread_join(th[i], NULL);								// Se ejecutan los 10 threads
	printf("Suma Total=%d\n", suma_total);
}