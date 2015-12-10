#include "cliente.hpp"
#include "unistd.h"
#include <ctime>


Cliente::Cliente(char* ip, int puerto):

	ip_(ip),
	puerto_(puerto),
	//csocket(0),
	socket_(conectarServidor()){

		thread t1(&Cliente::recibir, this);
		thread t2(&Cliente::enviar, this);
		t1.join();
		t2.join();
	}


Cliente::~Cliente(){}


int Cliente::conectarServidor(){

	struct sockaddr_in sin;
	int s;

	s = socket(AF_INET, SOCK_STREAM, 0);

	if (s<0){
        cout << "No se ha podido crear el socket: " << strerror(errno) << endl;
       	exit(1);
    }

	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr(ip_);
	sin.sin_port = htons(puerto_);

	if (connect(s, (struct sockaddr*)&sin, sizeof(sin)) < 0){
        cout << "Error en connect: " << strerror(errno) << endl;
       	exit(1);
    }

	return s;
}

void Cliente::recibir(){

   time_t now = time(0);
   char* dt = ctime(&now);
   cout << "Hilo RECIBIR: " << dt << endl;	

	while (1){

		char buffer[MAX_BUFF];
		int tam;

		tam = recv(socket_, buffer, MAX_BUFF, 0);
		buffer[tam] = '\0';
		printf("%s\n", buffer);	
	}	
}

void Cliente::enviar(){

   time_t now = time(0);
   char* dt = ctime(&now);
   cout << "Hilo ENVIAR: " << dt << endl;	

	char nick[30];
	printf("Introduzca un nick: ");
	scanf("%s", nick);
	printf("Aqui va el nick otra vez: %s\n\n", nick);

	send(socket_, nick, strlen(nick), 0);
	usleep(1000000);	

	char buffer[MAX_BUFF];

	while (1){

		//char buffer[MAX_BUFF];
		printf("Enviar mensaje: ");
		fgets(buffer, MAX_BUFF, stdin);

		send(socket_, buffer, strlen(buffer), 0);	
	}
}


int main(){ 


	Cliente chat((char*)"127.0.0.1",2121);

	return 0;
}


//g++ -o cliente usuario.cpp conexiones.cpp cliente.cpp -pthread -std=c++11
