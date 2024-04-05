#include "piquet.h"

Piquet::Piquet(int number, double shift, bool IsStandard) : number(num), shift(sh), IsStandard(isStd) {}

std::string Piquet::toString() const {
    if (number >= 0)
        return "ПК " + std::to_string(number) + "+" + std::to_string(shift);
    else
        return "ПК 0" + std::to_string(-number) + "+" + std::to_string(shift);
}

bool Piquet::operator<(const Piquet& other) const {
    return number < other.number || (number == other.number && shift < other.shift);
}

bool Piquet::operator>(const Piquet& other) const {
    return number > other.number || (number == other.number && shift > other.shift);
}