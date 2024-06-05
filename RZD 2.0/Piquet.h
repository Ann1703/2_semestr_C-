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


    int Number() const { return number; }
    double Shift() const { return shift; }
    double Length() const { return length; }
    bool IsStandard() const { return isStandard; }

    /// Операторы сравнения
    bool operator==(const Piquet& other) const;

    bool operator!=(const Piquet& other) const;


    bool operator<(const Piquet& other) const;

    bool operator<=(const Piquet& other) const; 

    bool operator>(const Piquet& other) const; 

    bool operator>=(const Piquet& other) const; 

    // Операторы сдвига
    Piquet operator+(const double& offset) const; 

    Piquet operator-(const double& offset) const;

    // Метод toString
    std::string ToString() const;


    // Метод, указывающий является ли пикет мерным
    bool IsMeasured() const;
};

#endif // PIQUET_H
