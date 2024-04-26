#include "Railroad.h"

double Railroad::getLength() const {
    double totalLength = 0.0;
    for (size_t i = 1; i < piquets.size(); ++i) {
        totalLength += piquets[i].IsStandard ? 100.0 : piquets[i].shift;
    }
    return totalLength;
}

void Railroad::addPiquet(const Piquet& p) {
    piquets.push_back(p);
}

void Railroad::Stage(const Piquet& p1, const Piquet& p2) {
    addPiquet(p1);
    addPiquet(p2);
}

std::string Railroad::ToString() const {
    std::string result;
    for (const auto& p : piquets) {
        result += p.toString() + "\n";
    }
    return result;
}
