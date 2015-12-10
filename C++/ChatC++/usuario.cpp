#include "usuario.hpp"

Usuario::Usuario(char* nickname, int cliente):

	nickname_(nickname),
	cliente_(cliente){}


Usuario::~Usuario(){

	if (nickname_)
		nickname_ = NULL;
}


char* Usuario::nickname(){

	return nickname_;
}

int Usuario::cliente(){

	return cliente_;
}