#pragma once

#include <iostream>
using namespace std;


class Usuario{

	private:

		char* nickname_;
		int cliente_;

	public:

		Usuario(char* nickname, int cliente);
		~Usuario();
		char* nickname();
		int cliente();
};