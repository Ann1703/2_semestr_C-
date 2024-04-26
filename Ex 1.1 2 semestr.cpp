#include <iostream>
#include "Piquet.h"

int main() {
    Piquet p1(12, 28.37);
    Piquet p2(-5, 15.75);

    std::cout << "Piquet 1: " << p1.toString() << std::endl;
    std::cout << "Piquet 2: " << p2.toString() << std::endl;

    std::cout << "Length of Piquet 1: " << p1.getLength() << std::endl;
    std::cout << "Length of Piquet 2: " << p2.getLength() << std::endl;

    if (p1 < p2) {
        std::cout << "Piquet 1 is less than Piquet 2" << std::endl;
    }
    else {
        std::cout << "Piquet 1 is greater than or equal to Piquet 2" << std::endl;
    }

    Piquet p3 = p1 + p2;
    std::cout << "Sum of Piquet 1 and Piquet 2: " << p3.toString() << std::endl;

    return 0;
}