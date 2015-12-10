// Ficheros de cabecera
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>	//netbd.h es necesitada por la estructura hostent
#include <string.h> //memset


int main(void){

	int fd;
	struct sockaddr_in server;
	struct hostent* hos;


	if ((fd = socket(AF_INET,SOCK_STREAM,0)) < 0){

		printf("Error en el connect\n");
		exit(-1);
	}

	if ((hos = gethostbyname("127.0.0.1")) == NULL){

		printf("Error en gethostbyname\n");
		exit(-1);
	}

	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(2121);
	//server.sin_addr = *((struct in_addr *)hos->h_addr);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	if ((connect(fd, (struct sockaddr *)&server, sizeof(server))) < 0){

		printf("error en connect\n");
		exit(-1);
	}

	char buffer[50];

	int tam = recv(fd, buffer, 50, 0);
	buffer[tam] = '\0';

	printf("%s\n", buffer);

}