class Subject
{
public:
    virtual void request() = 0;
};

class RealSubject : public Subject
{
public:
    void request() override
    {
        // Real subject request implementation
    }
};

class Proxy : public Subject
{
private:
    RealSubject *realSubject;

public:
    Proxy() : realSubject(new RealSubject()) {}
    void request() override
    {
        // Perform additional operations if needed
        realSubject->request();
        // Perform additional operations if needed
    }
};
