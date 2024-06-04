#include "Piquet.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Piquet::Piquet(int number = 0) : number(number), shift(0), length(100), isStandard(true) {}

Piquet::Piquet(int number) : number(number), shift(0), length(100), isStandard(true) {}

Piquet::Piquet(int number, double shift) : number(number), shift(shift), length(100 + shift), isStandard(false) {}

Piquet::Piquet(double length) : number(static_cast<int>(length / 100)), shift(length - 100 * number), length(length), isStandard(false) {}

int Piquet::Number() const { return number; }

double Piquet::Shift() const { return shift; }

double Piquet::Length() const { return length; }

bool Piquet::IsStandard() const { return isStandard; }

bool Piquet::operator==(const Piquet& other) const {
    return number == other.number && shift == other.shift;
}

bool Piquet::operator!=(const Piquet& other) const {
    return !(*this == other);
}

bool Piquet::operator<(const Piquet& other) const {
    if (number < other.number) {
        return true;
    }
    else if (number == other.number && shift < other.shift) {
        return true;
    }
    return false;
}

bool Piquet::operator<=(const Piquet& other) const {
    return (*this < other || *this == other);
}

bool Piquet::operator>(const Piquet& other) const {
    return !(*this <= other);
}

bool Piquet::operator>=(const Piquet& other) const {
    return !(*this < other);
}

Piquet Piquet::operator+(const double& offset) const {
    return Piquet(number, shift + offset);
}

Piquet Piquet::operator-(const double& offset) const {
    return Piquet(number, shift - offset);
}

std::string Piquet::ToString() const {
    std::stringstream ss;
    ss << "ПК" << (number >= 0 ? "" : "0") << std::abs(number) << "+" << std::fixed << std::setprecision(2) << shift;
    return ss.str();
}

bool Piquet::IsMeasured() const {
    return isStandard;
}