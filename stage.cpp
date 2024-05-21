#include "Stage.h"

Stage::Stage() {
    this->_piquets = std::vector<Piquet>();
}

Stage::Stage(const Piquet& start, const Piquet& end) {
    _piquets.push_back(start);
    _piquets.push_back(end);
}

Stage::Stage(std::string info)
{
    if (info.substr(0, 9) != "Stage: ")
        return;
    std::string data = info.substr(9);
    std::string::size_type prev_pos = 0, pos = 0;

    while((pos = data.find(' ', pos)) != std::string::npos)
    {
        std::string substring(data.substr(prev_pos, pos - prev_pos) );
        this->addPiquet(Piquet(substring));
        prev_pos = ++pos;
    }
    std::string substring(data.substr(prev_pos, pos - prev_pos) );
    this->addPiquet(Piquet(substring));
}

void Stage::addPiquet(const Piquet& p) {
    this->_piquets.push_back(p);
}

void Stage::insertPiquet(const Piquet &p, int index)
{
    if (index > this->_piquets.size() || index < 0)
        return;

    this->_piquets.insert(this->_piquets.begin() + index, p);
}

double Stage::calculateLength() const {
    double length = 0.0;
    for(size_t i = 0; i < _piquets.size(); ++i) {
        length += this->_piquets[i].length();
    }
    return length;
}

std::string Stage::toString() const {
    std::string result = "Stage: ";
    for(size_t i = 0; i < _piquets.size(); ++i) {
        result += this->_piquets[i].toString() + " ";
    }
    return result;
}
