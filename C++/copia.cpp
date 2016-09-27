#include <iostream>

void debug(const char *msg) {
  std::cout << msg << std::endl;
}

class A {

  int *valor;

public:

  A(int v);
  A(const A &obj);
  ~A();

  void mostrar() const;
  int get() const { return *valor; }
};

A::A(int v) {
  debug("Constructor...");
  valor = new int;
  *valor = v;
}

// Sin un constructor de copia, se produciria una violacion de segmento
A::A(const A &obj) {
  debug("Copia...");
  valor = new int;
  *valor = obj.get();
}

A::~A() {
  delete valor;
  debug("Destructor...");
}

void A::mostrar() const {
  std::cout << *valor << std::endl;
}

// Se llama al constructor de copia para crear "obj"
void mostrar(A obj) {
  obj.mostrar();
}

int main () {
  A obj(5);
  mostrar(obj);
  return 0;
}
