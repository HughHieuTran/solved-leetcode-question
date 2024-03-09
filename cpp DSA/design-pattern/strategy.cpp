class Strategy
{
public:
    virtual void algorithm() = 0;
};

class ConcreteStrategy1 : public Strategy
{
public:
    void algorithm() override
    {
        // Strategy 1 implementation
    }
};

class ConcreteStrategy2 : public Strategy
{
public:
    void algorithm() override
    {
        // Strategy 2 implementation
    }
};

class Context
{
private:
    Strategy *strategy;

public:
    Context(Strategy *strategy) : strategy(strategy) {}
    void setStrategy(Strategy *strategy)
    {
        this->strategy = strategy;
    }
    void execute()
    {
        strategy->algorithm();
    }
};
