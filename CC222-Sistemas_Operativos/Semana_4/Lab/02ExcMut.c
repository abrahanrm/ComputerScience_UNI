// Problema de Exclusión Mutua con espera ocupada/activa: Algoritmo de Peterson, para dos procesos
// Compilar: gcc 02ExcMut.c -lpthread 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int i=1, j=0, turn, sumaTotal = 0; 
int flag[2];

void procesos() {																// procesos Pi y Pj	
	int mm, indice =0;														//	Sección no crítica
	do {
		indice++;
		flag[i] = 1;															// th[i] listo para entrar a CPU
		turn = j;	

		while(flag[j] && turn == j);
		printf("Sección    crítica P%d, indice: %d\n", i, indice);	//	mi sección crítica: Sección crítica
		sumaTotal++;															   // mi sección crítica
		for(int k=0; k<10000; k++);										   // mi sección crítica: tiempo de espera
		flag[i] = 0;	
		printf("Sección no crítica P%d, indice: %d\n", i, indice);	//	Sección no crítica
		mm = i;
		i = j;
		j = mm;
		if(indice >= 5) break;
	} while (1);
}

int main() {
	int k, dos = 2;
	pthread_t th[dos];
	for (k=0;k<dos;k++) pthread_create(&th[k], NULL, (void *)procesos, NULL);
	for (k=0;k<dos;k++) pthread_join(th[k], NULL);
	printf("suma total: %d\n", sumaTotal);
}
/*
SALIDA:

Sección    crítica P1, indice: 1
Sección no crítica P1, indice: 1
Sección    crítica P0, indice: 2
Sección no crítica P0, indice: 2
Sección    crítica P1, indice: 3
Sección no crítica P1, indice: 3
Sección    crítica P0, indice: 4
Sección    crítica P0, indice: 1
Sección no crítica P0, indice: 1
Sección    crítica P1, indice: 2
Sección no crítica P0, indice: 4
Sección no crítica P0, indice: 2
Sección    crítica P1, indice: 3
Sección    crítica P1, indice: 5
Sección no crítica P1, indice: 3
Sección    crítica P0, indice: 4
Sección no crítica P0, indice: 5
Sección no crítica P1, indice: 4
Sección    crítica P0, indice: 5
Sección no crítica P0, indice: 5
suma total: 10
*/