#pragma once
#include <vector>
#include <string>
#include <algorithm>
class IntegerCollection {
public:
    IntegerCollection(std::initializer_list<int> values);
    IntegerCollection();
    ~IntegerCollection();

    std::string toString() const;

    IntegerCollection& operator=(const IntegerCollection& other);
    IntegerCollection& operator<<(int value);
    IntegerCollection& operator>>(int value);

    bool isEmpty() const;

    void insert(int value);
    void remove();
    int findMaxPriorityElement() const;

private:
    std::vector<int> collection;
};