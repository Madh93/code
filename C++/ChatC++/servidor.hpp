#pragma once

#include "conexiones.hpp"
#include "cliente.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <thread>


class Servidor{

	private:

		char* ip_;
		int puerto_;
		int socket_;
		Conexiones* conexiones_;

	public:

		Servidor(char* ip, int puerto);
		~Servidor();
		int definirSocket();
		void iniciar();
		void e(void* cs);
		void* escuchar(void *csocket);
		void parar();
};