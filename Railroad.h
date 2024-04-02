#include <iostream>
#include <sstream>
#include "Piquet.h"
#include <vector>

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
            length += piquets[i].isStandard ? 100.0 : piquets[i].shift;
        }
        return length;
    }

    std::string toString() const {
        std::stringstream ss;
        for (const auto& p : piquets) {
            ss << p.toString() << std::endl;
        }
        return ss.str();
    }
};
