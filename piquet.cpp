#include "piquet.h"

Piquet::Piquet(double shift, int length = 0): _shift(shift), _length(length) {
}

Piquet::Piquet(const Piquet &other) {
    this->_length = other._length;
    this->_shift = other._shift;
}

Piquet::Piquet(std::string info) {
    if (info.substr(0, 2) != "PK") return;
    bool sign = true;
    if (info[2] == '0') {
        data = info.substr(3);
        sign = false;
    }
    else {
        data = info.substr(2);
    }

    std::string::size_type pos = data.find('+');
    if (pos == std::string::npos)
        return;
    std::string length = data.substr(0, pos);
    std::string shift = data.substr(pos + 1);
    this->_length = std::stoi(length) * (!sign ? -1: 1);
    this->_shift = std::stod(shift);
}

std::string Piquet::toString() const {
    std::string prefix = this->_length >= 0 ? "PK" : "PK0";
    return prefix + std::to_string(std::abs(this->_length)) + "+" + std::to_string(this->_shift);
}

bool Piquet::operator<(const Piquet& other) const {
    return (this->_length < other._length) || (this->_length == other._length && this->_shift < other._shift);
}

bool Piquet::operator>(const Piquet& other) const {
    return (this->_length > other._length) || (this->_length == other._length && this->_shift > other._shift);
}

bool Piquet::operator==(const Piquet &other) const
{
    return (this->_length == other._length && this->_shift == other._shift);
}

Piquet Piquet::operator+(const Piquet& other) const {
    return Piquet(this->_shift + other._shift, this->_length + other._length);
}

Piquet Piquet::operator-(const Piquet& other) const {
    return Piquet(this->_shift - other._shift, this->_length - other._length);
}

Piquet& Piquet::operator++() {
    this->_shift++;
    return *this;
}

Piquet Piquet::operator++(int) {
    Piquet old = *this;
    operator++();
    return old;
}

Piquet &Piquet::operator--() {
    this->_shift--;
    return *this;
}

Piquet Piquet::operator--(int) {
    Piquet old = *this;
    operator--();
    return old;
}

double Piquet::shift() const {
    return this->_shift;
}

bool Piquet::isStandard() const {
    return this->_length == 100.0;
}

int Piquet::length() const {
    return this->_length;
}
