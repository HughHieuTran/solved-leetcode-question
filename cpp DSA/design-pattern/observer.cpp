#include <vector>

class Observer
{
public:
    virtual void update() = 0;
};

class Subject
{
private:
    std::vector<Observer *> observers;

public:
    void attach(Observer *observer)
    {
        observers.push_back(observer);
    }
    void notify()
    {
        for (Observer *observer : observers)
        {
            observer->update();
        }
    }
};

class ConcreteObserver : public Observer
{
public:
    void update() override
    {
        // Update implementation
    }
};
