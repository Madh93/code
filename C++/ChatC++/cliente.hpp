#pragma once

#include "conexiones.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <thread>


const int MAX_BUFF = 512;

class Cliente{

	private:

		char* ip_;
		int puerto_;
		int socket_;

	public:

		Cliente(char* ip, int puerto);
		~Cliente();
		int conectarServidor();
		void recibir();
		void enviar();
};