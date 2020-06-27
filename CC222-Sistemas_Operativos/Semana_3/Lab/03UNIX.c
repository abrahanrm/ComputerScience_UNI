/* ESTE proceso hace un fork (15) -> sigue ejecutandose, hace un wait(20)-> Se ejecuta el hijo clon --> ejecuta un execve (17) -> desaparece al hijo (17), se ejecuta execve y termina (17) -> No se ejecuatn (18 y 19) que son del hijo
-> finaliza execv (17) -> padre que estaba en wait (20) y sigue en la 21 y 22.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {  
	pid_t  pid;
	time_t t;
	int    status;
	t=time(NULL);
	printf("Hago fork %s\n",ctime(&t));		// Salida linea 26 y 27
	switch (pid=fork()) {						// Ejecuta fork y crea al hijo clon
		case -1: printf("Error de fork\n"); exit(0);
		case  0: execv("/bin/ls", argv);		// se crea y ejecuta el nuevo proceso de ls: línea 28
					printf("Error execv\n");	// No se ejecuta, ESTE PROCESO DESAPARECE,
					exit(0);							// es reemplazado por el execv
		default: waitpid(pid,&status,0);		// padre entra en wait -> se ejecuta el hijo -> desaparece hijo -> execv()
					t=time(NULL);					// padre regresa del wait después que termina execv().
					printf("Termina el hijo %s\n",ctime(&t)); // salida línea 29
	}
}
/* SALIDA
Hago fork Fri Jun 12 14:10:07 2020				// printf de la línea 14
															// printf de la línea 14
01fork.c  02execve.c  03UNIX.c	a.out			// salida de ls del execv (17)  ???
Termina el hijo Fri Jun 12 14:10:07 2020		// Termina el padre
*/