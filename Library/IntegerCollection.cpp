#include "IntegerCollection.h"

IntegerCollection::IntegerCollection(std::initializer_list<int> values) : collection(values) {}

IntegerCollection::IntegerCollection() {}

IntegerCollection::~IntegerCollection() {}

std::string IntegerCollection::toString() const {
    std::stringstream;
    for (int val : collection) {
        result += std::to_string(val) + " ";
    }
    return result;
}

IntegerCollection& IntegerCollection::operator<<(int value) {
    enqueue(value);
    return *this;
}

IntegerCollection& IntegerCollection::operator>>(int value) {
    dequeue();
    return *this;
}

bool IntegerCollection::isEmpty() const {
    return collection.empty();
}

void IntegerCollection::enqueue(int value) {
    collection.push_back(value);
}

void IntegerCollection::dequeue() {
    if (!isEmpty()) {
        collection.pop_back();
    }
}

int IntegerCollection::findMaxPriorityElement() const {
    if (!isEmpty()) {
        return *std::max_element(collection.begin(), collection.end());
    }
    return 0;
}