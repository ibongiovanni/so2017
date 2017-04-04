#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
int main(void) { 
	pid_t idHijo;
	pid_t idPropio;
	idPropio = getpid(); //Se obtiene el id del proceso actual
	idHijo = fork(); //Se crea un proceso 'hijo'
	if (idHijo == -1) { //Si hay un código menor que cero, hubo un error
		printf("Error al realizar la bifurcación"); //Se notifica al usuario
		return 1; //Se interrumpe la ejecución del proceso con una salida distinta a cero
	} 
	if (idHijo == 0) //la ejecución de la llamada al sistema fork devuelve un cero al proceso 'hijo'
		printf("Soy el hijo con id %ld id proceso original %ld\n", (long)getpid(), (long)idPropio); 
	else //la ejecución de la llamada al sistema fork devuelve el identificador al proceso 'padre'
		printf("Soy el padre con id %ld id proceso original %ld\n", (long)getpid(), (long)idPropio); 
	return 0; 
}