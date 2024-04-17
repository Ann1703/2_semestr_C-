#ifndef piquet_h
#define piquet_h

#include <string>

const int MAX_OFFSET = 100;
const int MAX_LENGTH = 200;

class Piquet {
private:
    std::string name;
    int length;
    bool IsStandard;

public:
    Piquet(const std::string& name, int length);
    std::string toString() const;
    bool operator<(const Piquet& other) const;
    bool operator>(const Piquet& other) const;
};

Piquet::Piquet(const std::string& name, int length) : name(name) {
    if (length <= MAX_LENGTH) {
        this->length = length;
        this->IsStandard = (length == 100);
    }
    else {
        // Handle error for length exceeding MAX_LENGTH
        throw std::invalid_argument("Length exceeds maximum allowed value.");
    }
}

std::string Piquet::toString() const {
    return "Piquet: " + name + ", Length: " + std::to_string(length) + ", IsStandard: " + (IsStandard ? "true" : "false");
}

bool Piquet::operator<(const Piquet& other) const {
    return length < other.length;
}

bool Piquet::operator>(const Piquet& other) const {
    return length > other.length;
}
