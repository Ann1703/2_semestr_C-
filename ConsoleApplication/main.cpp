
#include <iostream>
#include "../Library/IntegerCollection.h"

int main() {
    IntegerCollection collection = { 5, 2, 8, 1, 9 };

    std::cout << "Initial Collection: " << collection.toString() << std::endl;
     
    collection << 10;
    std::cout << "After Inserting 10: " << collection.toString() << std::endl;

    collection >> 10;
    std::cout << "After Removing Last Element: " << collection.toString() << std::endl;

    std::cout << "Max Priority Element: " << collection.findMaxPriorityElement() << std::endl;

    return 0;
}