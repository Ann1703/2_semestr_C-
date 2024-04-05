#include <iostream>

int main() {
    Piquet p1(12, 28.37, true);
    Piquet p2(-12, 28.37, false);

    Perigon perigon(p1, p2);

    std::cout << perigon.ToString() << std::endl;
    std::cout << "Длина перегона: " << perigon.calculateLength() << std::endl;

    return 0;
}