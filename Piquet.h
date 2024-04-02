#include <iostream>
#include <sstream>

class Piquet {
private:
    int number;
    double shift;
    bool isStandard;

public:
    Piquet(int num, double sh, bool standard) : number(num), shift(sh), isStandard(standard) {}

    std::string toString() const {
        std::stringstream ss;
        if (number >= 0)
            ss << "PK" << number << "+" << shift;
        else
            ss << "PK0" << number << "+" << shift;
        return ss.str();
    }

    bool operator<(const Piquet& other) const {
        return (number < other.number) || (number == other.number && shift < other.shift);
    }

    bool operator>(const Piquet& other) const {
        return other < *this;
    }
};
