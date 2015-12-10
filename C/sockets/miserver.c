// Ficheros de cabecera
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>


int main(void){

	int fd1, fd2;
	struct sockaddr_in server;
	struct sockaddr_in client;

	if ((fd1 = socket(AF_INET,SOCK_STREAM,0)) < 0){

		perror("Error en socket()");
		exit(-1);
	}

	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(2121);
	server.sin_addr.s_addr = INADDR_ANY;


	if ((bind(fd1, (struct sockaddr *)&server, sizeof(server))) < 0){

		perror("Error en bind()");
		exit(-1);
	}

	printf("BIENVENIDO AL SERVIDOR JAJAJA\n");

	if (listen(fd1,5) < 0){
		
		printf("error en listen()\n");
		exit(-1);
	}

	while (1){

		int longitud = sizeof(client);
		if ((fd2 = accept(fd1, (struct sockaddr *)&client, &longitud)) < 0){
			printf("error en accept()\n");
			exit(-1);
		}

		char* saludo = "Bienvenido al chat!";
		char buffer[100];
		send(fd2, saludo, strlen(saludo), 0);

		close(fd2);
	}

	close(fd1);

	return 0;
}