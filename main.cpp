#include <iostream>

#include "Stage.h"


int main() {
    Piquet p1(28.37, 102);
    Piquet p2(28.37, -12);

    Piquet p3("PK0102+13.45");
    std::cout << p3.toString() << std::endl;
    p3++;
    std::cout << p3.toString() << std::endl;

    Stage stage(p1, p2);

    std::cout << Stage.toString() << std::endl;
    std::cout << "Длина перегона: " << Stage.calculateLength() << std::endl;

    Stage per2("Stage: PK102+28.370000 PK0101+18.70");
    std::cout << per2.toString() << std::endl;
    std::cout << "Длина перегона: " << per2.calculateLength() << std::endl;

    return 0;
}
