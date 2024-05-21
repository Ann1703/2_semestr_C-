#ifndef PIQUET_H
#define PIQUET_H

#include <string>

class Piquet {
public:
    Piquet(double, int);
    Piquet(const Piquet&);
    Piquet(std::string);
    std::string toString() const;

    bool operator<(const Piquet& other) const;
    bool operator>(const Piquet& other) const;
    bool operator==(const Piquet& other) const;

    Piquet operator+(const Piquet& other) const;
    Piquet operator-(const Piquet& other) const;
    Piquet& operator++();
    Piquet operator++(int);
    Piquet& operator--();
    Piquet operator--(int);

    double shift() const;
    bool isStandard() const;

    int length() const;

private:
    double _shift;
    int _length;

};

#endif // PIQUET_H
