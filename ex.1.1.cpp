#include <iostream>
#include <string>

class Piquet {
private:
    int number;
    double shift;
    bool IsStandard;

public:
    Piquet(int num, double sh, bool isStd) : number(num), shift(sh), IsStandard(isStd) {}

    std::string toString() const {
        if (number >= 0)
            return "ПК " + std::to_string(number) + "+" + std::to_string(shift);
        else
            return "ПК 0" + std::to_string(-number) + "+" + std::to_string(shift);
    }

    bool operator<(const Piquet& other) const {
        return number < other.number || (number == other.number && shift < other.shift);
    }

    bool operator>(const Piquet& other) const {
        return number > other.number || (number == other.number && shift > other.shift);
    }
};

class Railroad {
private:
    std::vector<Piquet> piquets;

public:
    void addPiquet(const Piquet& p) {
        piquets.push_back(p);
    }

    double calculateLength() const {
        double length = 0.0;
        for (size_t i = 1; i < piquets.size(); ++i) {
            length += piquets[i].IsStandard ? 100.0 : piquets[i].shift;
        }
        return length;
    }

    Perigon(const Piquet& p1, const Piquet& p2) {
        addPiquet(p1);
        addPiquet(p2);
    }

    std::string ToString() const {
        std::string result;
        for (const auto& p : piquets) {
            result += p.toString() + "\n";
        }
        return result;
    }
};

