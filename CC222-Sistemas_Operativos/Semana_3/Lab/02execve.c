// Este proceso crea un proceso execve, el cual toma datos de sus argumentos -> desaparece ESTE proceso -> es sustituido
// por el proceso creado. 
#include <stdio.h>
#include <unistd.h>
int main() {
	char *arg[]={"ls","-lR","/",NULL}; 			// argumentos para execve, 
	char *argp[]={NULL};								// argumentos para execve
	execve("/bin/ls", arg, argp);					// se genera un nuevo proceso y desaparece ESTE proceso.
	printf("\n (execve produjo un error, si no se puede crear ececve); en caso contrario este mensaje no se escribe)\n");
															// porque el proceso inicial está muerto
}


/* SALIDA: ejecuta ls en todos los direcorios
-rwxrwxrwx 1 carlos carlos   1013 Mar 28  2007  dll.lnk
-rwxrwxrwx 1 carlos carlos     41 Mar 26  2007  indice.prg

/home/carlos/Escritorio/Caracas/Project2010/Proyectos/MCI/blinker:
total 144
-rwxrwxrwx 1 carlos carlos 140433 Mar 27  2007 blinker.zip
drwxrwxrwx 4 carlos carlos   4096 Mar 29  2018 clipper5

/home/carlos/Escritorio/Caracas/Project2010/Proyectos/MCI/blinker/clipper5:
total 24
drwxrwxrwx 2 carlos carlos  4096 Mar 29  2018 BIN
*/
