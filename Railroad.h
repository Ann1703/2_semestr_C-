#ifndef Railroad_h
#define Railroad_h

#include <vector>
#include "piquet.h"

class Perigon {
private:
    std::vector<Piquet> piquets;

public:
    void addPiquet(const Piquet& p);
    double CLength() const;
    Perigon(const Piquet& p1, const Piquet& p2);
    std::string ToString() const;
};

