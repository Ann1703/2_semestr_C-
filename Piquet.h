#ifndef piquet_h
#define piquet_h

#include <string>

class Piquet {
private:
    int number;
    double shift;
    bool IsStandard;

public:
    Piquet(int number, double shift, bool IsStandard);
    std::string toString() const;
    bool operator<(const Piquet& other) const;
    bool operator>(const Piquet& other) const;
};
