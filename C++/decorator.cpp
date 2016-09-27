#include <iostream>

class Firearm {
public:
  virtual float noise() const = 0;
  virtual int bullets() const = 0;
};

class Rifle : public Firearm {
public:
  float noise () const { return 150.0; }
  int bullets () const { return 5; }
};

/* Decorators */

class FirearmDecorator : public Firearm {
protected:
  Firearm* _gun;
public:
  FirearmDecorator(Firearm* gun): _gun(gun) {};
  virtual float noise () const { return _gun->noise(); }
  virtual int bullets () const { return _gun->bullets(); }
};

class Silencer : public FirearmDecorator {
public:
  Silencer(Firearm* gun) : FirearmDecorator(gun) {};
  float noise () const { return _gun->noise() - 55; }
  int bullets () const { return _gun->bullets(); }
};

class Magazine : public FirearmDecorator {
public:
  Magazine(Firearm* gun) : FirearmDecorator(gun) {};
  float noise () const { return _gun->noise(); }
  int bullets () const { return _gun->bullets() + 5; }
};

/* Using decorators */

int main() {

  Firearm* gun = new Rifle();
  std::cout << "Gun: " << gun << std::endl;
  std::cout << "Noise: " << gun->noise() << std::endl;
  std::cout << "Bullets: " << gun->bullets() << std::endl;

  // char gets a silencer
  gun = new Silencer(gun);
  std::cout << "Gun with Silencer: " << gun << std::endl;
  std::cout << "Noise: " << gun->noise() << std::endl;
  std::cout << "Bullets: " << gun->bullets() << std::endl;

  // char gets a new magazine
  gun = new Magazine(gun);
  std::cout << "Gun with Silencer+Magazine: " << gun << std::endl;
  std::cout << "Noise: " << gun->noise() << std::endl;
  std::cout << "Bullets: " << gun->bullets() << std::endl;

  // Bad memory allocation example

  return 0;
}
