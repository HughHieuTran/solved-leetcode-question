class Product
{
    // Product with complex construction
};

class Builder
{
public:
    virtual void buildPart1() = 0;
    virtual void buildPart2() = 0;
    virtual Product *getResult() = 0;
};

class ConcreteBuilder : public Builder
{
private:
    Product *product;

public:
    ConcreteBuilder()
    {
        product = new Product();
    }
    void buildPart1() override
    {
        // Build part 1
    }
    void buildPart2() override
    {
        // Build part 2
    }
    Product *getResult() override
    {
        return product;
    }
};

class Director
{
public:
    Product *construct(Builder *builder)
    {
        builder->buildPart1();
        builder->buildPart2();
        return builder->getResult();
    }
};
