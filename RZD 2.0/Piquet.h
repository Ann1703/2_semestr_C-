// Piquet.h
#ifndef PIQUET_H
#define PIQUET_H

#include <iostream>
#include <sstream>
#include <iomanip>

class Piquet {
private:
    int number;
    double shift;
    double length;
    bool isStandard;

public:
    // Конструктор по умолчанию
    Piquet() : number(0), shift(0), length(100), isStandard(true) {}

    // Конструктор по пикету (целому числу)
    Piquet(int number) : number(number), shift(0), length(100), isStandard(true) {}

    // Конструктор по пикету и смещению
    Piquet(int number, double shift) : number(number), shift(shift), length(100 + shift), isStandard(false) {}

    // Конструктор по вещественному значению
    Piquet(double length) : number(static_cast<int>(length / 100)), shift(length - 100 * number), length(length), isStandard(false) {}

    // Геттеры
    int Number() const { return number; }
    double Shift() const { return shift; }
    double Length() const { return length; }
    bool IsStandard() const { return isStandard; }

    // Операторы сравнения
    bool operator==(const Piquet& other) const {
        return number == other.number && shift == other.shift;
    }

    bool operator!=(const Piquet& other) const {
        return !(*this == other);
    }

    bool operator<(const Piquet& other) const {
        if (number < other.number) {
            return true;
        }
        else if (number == other.number && shift < other.shift) {
            return true;
        }
        return false;
    }

    bool operator<=(const Piquet& other) const {
        return (*this < other || *this == other);
    }

    bool operator>(const Piquet& other) const {
        return !(*this <= other);
    }

    bool operator>=(const Piquet& other) const {
        return !(*this < other);
    }

    // Операторы сдвига
    Piquet operator+(const double& offset) const {
        return Piquet(number, shift + offset);
    }

    Piquet operator-(const double& offset) const {
        return Piquet(number, shift - offset);
    }

    // Метод toString
    std::string ToString() const {
        std::stringstream ss;
        ss << "ПК" << (number >= 0 ? "" : "0") << std::abs(number) << "+" << std::fixed << std::setprecision(2) << shift;
        return ss.str();
    }

    // Метод, указывающий является ли пикет мерным
    bool IsMeasured() const {
        return isStandard;
    }
};
 
#endif // PIQUET_H
