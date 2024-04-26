#ifndef PIQUET_H
#define PIQUET_H

#include <string>

class Piquet {
public:
    Piquet(int number, double shift);
    double getLength() const;
    std::string toString() const;
    bool operator<(const Piquet& other) const;
    bool operator>(const Piquet& other) const;
    Piquet operator+(const Piquet& other) const;
    Piquet operator-(const Piquet& other) const;

public:
    int number;
    double shift;
    bool isStandard;
};

#endif