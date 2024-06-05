// Piquet.h
#ifndef PIQUET_H
#define PIQUET_H

#include <iostream>
#include <sstream>
#include <iomanip>
/// Класс Piquet, представляющий пикет на железной дороге.
/// Пикет - это условный километровый знак на железной дороге, 
/// который используется для обозначения местоположения объектов.
/// 
/// Класс Piquet предоставляет методы для получения номера пикета,смещения от пикета, длины пикета, а также для сравнения пикетов и сдвига пикетов на заданное расстояние.
class Piquet {
private:
    int number;
    double shift;
    double length;
    bool isStandard;

public:
    // 
     *@ breaf Конструктор по умолчанию
    //
    Piquet() : number(0), shift(0), length(100), isStandard(true) {}

    // 
    *@ breaf Конструктор по пикету (целому числу)
    //
    Piquet(int number) : number(number), shift(0), length(100), isStandard(true) {}

    // 
    *@ breaf Конструктор по пикету и смещению
    //
    Piquet(int number, double shift) : number(number), shift(shift), length(100 + shift), isStandard(false) {}

    // 
    *@ breaf Конструктор по вещественному значению
    //
    Piquet(double length) : number(static_cast<int>(length / 100)), shift(length - 100 * number), length(length), isStandard(false) {}


    int Number() const { return number; }
    double Shift() const { return shift; }
    double Length() const { return length; }
    bool IsStandard() const { return isStandard; }

    //  
    *@ breaf Операторы сравнения
    //
    bool operator==(const Piquet& other) const;

    bool operator!=(const Piquet& other) const;


    bool operator<(const Piquet& other) const;

    bool operator<=(const Piquet& other) const; 

    bool operator>(const Piquet& other) const; 

    bool operator>=(const Piquet& other) const; 
    // 
    *@ breaf Операторы сдвига
    //
       
    Piquet operator+(const double& offset) const; 

    Piquet operator-(const double& offset) const;

    // 
    *@ breaf Метод toString 
    // 
    std::string ToString() const;


    // 
    *@ breaf Метод, указывающий является ли пикет мерным
    //
    bool IsMeasured() const;
};

#endif // PIQUET_H
