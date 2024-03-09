class Product {
public:
    virtual void operation() = 0;
};

class ConcreteProduct : public Product {
public:
    void operation() override {
        // Concrete implementation
    }
};

class Factory {
public:
    virtual Product* createProduct() = 0;
};

class ConcreteFactory : public Factory {
public:
    Product* createProduct() override {
        return new ConcreteProduct();
    }
};
