#include "conexiones.hpp"

Conexiones::Conexiones(){}

Conexiones::~Conexiones(){

	lista_.clear();
}

void Conexiones::nueva(char* nickname, int cliente){

	Usuario usuario(nickname,cliente);
	lista_.push_back(usuario);
}

vector<Usuario> Conexiones::lista(){

	return lista_;
}

char* Conexiones::nickname(int user){

	return lista_[user].nickname();
}

int Conexiones::cliente(int user){

	return lista_[user].cliente();
}