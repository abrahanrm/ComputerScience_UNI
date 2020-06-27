//Padre hace un fork y crea un hijo clon -> continua ejecutándose el padre -> se ejecuta el hijo clon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
	pid_t pid, val=2;
	switch (pid=fork()) {									//crea el proceso	hijo: clon -> se ejecuta padre --> hijo
		case -1: printf("Error de fork\n");	exit(0); // errror de fork
		case  0: val--; break; 								// se ejecuta proceso hijo 
		default: val++;		  								// se ejecuta proceso padre
	}
	printf("proceso %d: val=%d\n", getpid(), val);
}
/* SALIDA de los dos procesos:
proceso (pid de papá) 8793: val=3		//	padre
proceso (pid de hijo) 8794: val=1		// hijo
*/
