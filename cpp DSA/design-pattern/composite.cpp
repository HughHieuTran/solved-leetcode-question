#include <vector>

class Component
{
public:
    virtual void operation() = 0;
};

class Leaf : public Component
{
public:
    void operation() override
    {
        // Leaf operation
    }
};

class Composite : public Component
{
private:
    std::vector<Component *> children;

public:
    void add(Component *component)
    {
        children.push_back(component);
    }
    void operation() override
    {
        for (Component *component : children)
        {
            component->operation();
        }
    }
};
