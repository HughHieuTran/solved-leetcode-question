class Component
{
public:
    virtual void operation() = 0;
};

class ConcreteComponent : public Component
{
public:
    void operation() override
    {
        // Concrete component operation
    }
};

class Decorator : public Component
{
protected:
    Component *component;

public:
    Decorator(Component *component) : component(component) {}
    void operation() override
    {
        component->operation();
    }
};

class ConcreteDecorator : public Decorator
{
public:
    ConcreteDecorator(Component *component) : Decorator(component) {}
    void operation() override
    {
        Decorator::operation();
        // Additional operation
    }
};
