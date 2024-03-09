class Target
{
public:
    virtual void request() = 0;
};

class Adaptee
{
public:
    void specificRequest()
    {
        // Specific request implementation
    }
};

class Adapter : public Target
{
private:
    Adaptee *adaptee;

public:
    Adapter(Adaptee *adaptee) : adaptee(adaptee) {}
    void request() override
    {
        adaptee->specificRequest();
    }
};
