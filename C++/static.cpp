#include <iostream>

class MiClase {
public:
    static int variable;

    void setValue(int value) {
        variable = value;
    }
};

int MiClase::variable = 5;

int main(void) {


    MiClase A;
    MiClase B;

    std::cout << "Variable: " << MiClase::variable << std::endl;
    std::cout << "Variable: " << B.variable << std::endl;

    A.setValue(1);

    std::cout << "Variable: " << MiClase::variable << std::endl;
    std::cout << "Variable: " << B.variable << std::endl;

    return 0;
}