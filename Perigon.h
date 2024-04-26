#pragma once
#ifndef PERIGON_H
#define PERIGON_H

#include "piquet.h"
#include <vector>

class Perigon {
private:
    std::vector<Piquet> piquets;

public:
    void addPiquet(const Piquet& p);
    double calculateLength() const;
    Perigon(const Piquet& start, const Piquet& end);
    std::string toString() const;
};

#endif