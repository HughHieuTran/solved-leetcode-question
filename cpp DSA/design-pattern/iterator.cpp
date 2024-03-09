#include <vector>

template <typename T>
class Iterator
{
public:
    virtual T next() = 0;
    virtual bool hasNext() = 0;
};

template <typename T>
class ConcreteIterator : public Iterator<T>
{
private:
    std::vector<T> data;
    size_t index;

public:
    ConcreteIterator(std::vector<T> data) : data(data), index(0) {}
    T next() override
    {
        return data[index++];
    }
    bool hasNext() override
    {
        return index < data.size();
    }
};
