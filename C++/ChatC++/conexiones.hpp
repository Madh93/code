#pragma once
#include "usuario.hpp"
#include "vector"

class Conexiones{

	private:

		vector<Usuario> lista_;

	public:

		Conexiones();
		~Conexiones();
		void nueva(char* nickname, int cliente);
		vector<Usuario> lista();
		char* nickname(int user);
		int cliente(int user);
};