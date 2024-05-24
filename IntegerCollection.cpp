#include "IntegerCollection.h"

IntegerCollection::IntegerCollection(std::initializer_list<int> values) : collection(values) {}

IntegerCollection::IntegerCollection() {}

IntegerCollection::~IntegerCollection() {}

std::string IntegerCollection::toString() const {
    std::string result;
    for (int val : collection) {
        result += std::to_string(val) + " ";
    }
    return result;
}

IntegerCollection& IntegerCollection::operator=(const IntegerCollection& other) {
    if (this != &other) {
        collection = other.collection;
    }
    return *this;
}

IntegerCollection& IntegerCollection::operator<<(int value) {
    insert(value);
    return *this;
}

IntegerCollection& IntegerCollection::operator>>(int value) {
    remove();
    return *this;
}

bool IntegerCollection::isEmpty() const {
    return collection.empty();
}

void IntegerCollection::insert(int value) {
    collection.push_back(value);
}

void IntegerCollection::remove() {
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