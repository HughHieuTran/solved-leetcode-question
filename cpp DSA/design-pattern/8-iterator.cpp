#include <iostream>
#include <vector>

// Iterator interface
template<typename T>
class Iterator {
public:
    virtual bool hasNext() const = 0;
    virtual T next() = 0;
    virtual ~Iterator() {}
};

// Concrete Iterator for iterating over a vector
template<typename T>
class VectorIterator : public Iterator<T> {
private:
    const std::vector<T>& vec;
    size_t index;

public:
    VectorIterator(const std::vector<T>& v) : vec(v), index(0) {}

    bool hasNext() const override {
        return index < vec.size();
    }

    T next() override {
        return vec[index++];
    }
};

// Aggregate interface
template<typename T>
class Aggregate {
public:
    virtual Iterator<T>* createIterator() const = 0;
    virtual ~Aggregate() {}
};

// Concrete aggregate class representing a vector
template<typename T>
class VectorAggregate : public Aggregate<T> {
private:
    std::vector<T> data;

public:
    void add(const T& item) {
        data.push_back(item);
    }

    Iterator<T>* createIterator() const override {
        return new VectorIterator<T>(data);
    }
};

int main() {
    VectorAggregate<int> numbers;
    numbers.add(1);
    numbers.add(2);
    numbers.add(3);

    // Create an iterator for the vector
    Iterator<int>* iterator = numbers.createIterator();

    // Iterate over the elements using the iterator
    while (iterator->hasNext()) {
        std::cout << iterator->next() << " ";
    }
    std::cout << std::endl;

    delete iterator;

    return 0;
}
