#include "servidor.hpp"
#include <pthread.h>


Servidor::Servidor(char* ip, int puerto):

	ip_(ip),
	puerto_(puerto),
	socket_(0),
	conexiones_(NULL){
		conexiones_ = new Conexiones;
	}


Servidor::~Servidor(){

	if (conexiones_){
		delete conexiones_;
		conexiones_ = NULL;
	}
}

int Servidor::definirSocket(){

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

    if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) < 0){
        cout << "No se ha podido hacer bind con el puerto: " << strerror(errno) << endl;
       	exit(1);
    }

    if (listen(s,5) < 0){
        cout << "Fallo en listen: " << strerror(errno) << endl;
    	exit(1);
    }
  
    return s;
}


void Servidor::iniciar(){

    struct sockaddr_in fsin;
    int csocket;
    socklen_t alen = sizeof(fsin);

    socket_ = definirSocket();
    
    while (1){

        //pthread_t thread;
        csocket = accept(socket_, (struct sockaddr *)&fsin, &alen);
  
        if(csocket < 0){
			cout << "Fallo en accept: " << strerror(errno) << endl;
			exit(1);
        }

		char nick[30];
		bool nick_found = false;
		int tam = recv(csocket, nick, 30, 0);
		nick[tam] = '\0';

		cout << "nick = " << nick << endl;



		for (int i=0; i<conexiones_->lista().size(); i++){
			if (nick == conexiones_->nickname(i)){
				nick_found = true;
				send(csocket, "El nick ya existe!\n", 20, 0);	
			}
		}

		if (!nick_found){

			conexiones_->nueva(nick,csocket);
			cout << "Nuevo usuario: " << nick << endl;
			cout << "size: " << conexiones_->lista().size() << endl;
			thread t1(&Servidor::e, this, (void*)csocket);
			t1.join();
			//int a=10;
			//pthread_create(&thread, NULL, escuchar, (void)a);
		}
    }
}

void Servidor::e(void* cs){

	escuchar(cs);
}

void* Servidor::escuchar(void *csocket){

	int cs;

	char saludo[30] = "Bienvenido a el chat ;)\n\n";
	send(cs, saludo, strlen(saludo), 0);	

	while (1){

		char buffer[MAX_BUFF];
		const char* message;
		int tam;

		tam = recv(cs, buffer, MAX_BUFF, 0);
		char *pos;
		if ((pos=strchr(buffer, '\n')) != NULL)
		    *pos = '\0';

		if (tam > 0)
			cout << "msg: " << buffer << endl;


		for (int i=0; i<conexiones_->lista().size(); i++){

			string msg = "";
			char* user = conexiones_->nickname(i);
			msg.append(user);
			msg.append(": ");
            msg.append(buffer);
            //msg.append("\n");

            message = msg.c_str();
            cout << "SERVER: " << message << endl;

			//if (cs != conexiones_->cliente(i))
				//send(conexiones_->cliente(i), message, strlen(message), 0);	
				send(cs, message, strlen(message), 0);	
		}
	}
	return NULL;
}

void Servidor::parar(){}


int main(){ 


	Servidor chat((char*)"127.0.0.1",2121);
	chat.iniciar();

	return 0;
}


//g++ -o servidor usuario.cpp conexiones.cpp servidor.cpp -pthread -std=c++11
