#include "Piquet.h"

Piquet::Piquet(int number, double shift) : number(number), shift(shift) {
    isStandard = (number == 0);
}

double Piquet::getLength() const {
    return 100.0; // Placeholder value, actual calculation needed
}

std::string Piquet::toString() const {
    if (number >= 0) {
        return "PK" + std::to_string(number) + "+" + std::to_string(shift);
    }
    else {
        return "PK0" + std::to_string(-number) + "+" + std::to_string(shift);
    }
}

bool Piquet::operator<(const Piquet& other) const {
    return (number < other.number) || (number == other.number && shift < other.shift);
}

bool Piquet::operator>(const Piquet& other) const {
    return (number > other.number) || (number == other.number && shift > other.shift);
}

Piquet Piquet::operator+(const Piquet& other) const {
    return Piquet(number + other.number, shift + other.shift);
}

Piquet Piquet::operator-(const Piquet& other) const {
    return Piquet(number - other.number, shift - other.shift);
}