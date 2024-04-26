#include "Perigon.h"

void Perigon::addPiquet(const Piquet& p) {
    piquets.push_back(p);
}

double Perigon::calculateLength() const {
    double length = 0.0;
    for (size_t i = 1; i < piquets.size(); ++i) {
        length += piquets[i].number - piquets[i - 1].number + (piquets[i].shift - piquets[i - 1].shift) / 100.0;
    }
    return length;
}

Perigon::Perigon(const Piquet& start, const Piquet& end) {
    piquets.push_back(start);
    piquets.push_back(end);
}

std::string Perigon::toString() const {
    std::string result = "Perigon: ";
    for (const auto& p : piquets) {
        result += p.toString() + " ";
    }
    return result;
}