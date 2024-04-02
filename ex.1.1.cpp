#include <iostream>
#include "Piquet.h"
#include "Railroad.h"

int main()
{
    Piquet p1(12, 28.37, true);
    Piquet p2(-5, 15.75, false);

    Railroad railroad;
    railroad.addPiquet(p1);
    railroad.addPiquet(p2);

    std::cout << "Railroad Mileage Information:" << std::endl;
    std::cout << railroad.toString();

    std::cout << "Total Length of Railroad: " << railroad.calculateLength() << " meters" << std::endl;

    return 0;

}
