#pragma once
#include <vector>
#include <string>
#include <algorithm>
class IntegerCollection {
public:
    IntegerCollection(std::initializer_list<int> values);
    IntegerCollection();


    std::string toString() const;

    IntegerCollection& operator = default; 
    IntegerCollection& operator<<(int value);
    friend std::ostream& operator <<([s](std::ostream& out, const IntegerCollection collection);
    IntegerCollection& operator>>(int value);

    bool isEmpty() const;

    void enqueue(int value);
    void dequeue();
    int findMaxPriorityElement() const;

private:
    std::vector<int> collection;
};