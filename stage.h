#ifndef Stage_H
#define Stage_H

#include "piquet.h"
#include <vector>

class Stage {
public:
    Stage();
    Stage(const Piquet&, const Piquet&);
    Stage(std::string);

    void addPiquet(const Piquet&);
    void insertPiquet(const Piquet&, int);
    double calculateLength() const;
    std::string toString() const;

private:
    std::vector<Piquet> _piquets;
};

#endif // Stage_H
