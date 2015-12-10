#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void){

	int status, pid, a=0;

	pid = fork();

	if (pid == 0){	//Soy el hijo

		a++;
		printf("Soy el Hijo y este es mi PID: %d\n", getpid());
		printf("a = , %d\n", a);
	}

	else if (pid > 0){ //Soy el padre

		sleep(2);
		printf("Soy el Padre y este es mi PID: %d\n", getpid());
		printf("a = , %d\n", a);

		wait(&status);
	}

	else
		exit(0);


	return 0;
}