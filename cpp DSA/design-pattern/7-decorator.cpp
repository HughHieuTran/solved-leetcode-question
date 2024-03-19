#include <iostream>
#include <string>

// Component interface
class Coffee {
public:
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
    virtual ~Coffee() {}
};

// Concrete component
class SimpleCoffee : public Coffee {
public:
    std::string getDescription() const override {
        return "Simple coffee";
    }

    double cost() const override {
        return 1.0; // $1
    }
};

// Decorator base class
class CoffeeDecorator : public Coffee {
protected:
    Coffee* decoratedCoffee;

public:
    CoffeeDecorator(Coffee* coffee) : decoratedCoffee(coffee) {}

    std::string getDescription() const override {
        return decoratedCoffee->getDescription();
    }

    double cost() const override {
        return decoratedCoffee->cost();
    }
};

// Concrete decorator: Milk
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    std::string getDescription() const override {
        return CoffeeDecorator::getDescription() + ", Milk";
    }

    double cost() const override {
        return CoffeeDecorator::cost() + 0.5; // Additional $0.5 for milk
    }
};

// Concrete decorator: Sugar
class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    std::string getDescription() const override {
        return CoffeeDecorator::getDescription() + ", Sugar";
    }

    double cost() const override {
        return CoffeeDecorator::cost() + 0.3; // Additional $0.3 for sugar
    }
};

int main() {
    // Create a simple coffee
    Coffee* coffee = new SimpleCoffee();
    std::cout << "Description: " << coffee->getDescription() << ", Cost: $" << coffee->cost() << std::endl;

    // Add milk to the coffee
    Coffee* milkCoffee = new MilkDecorator(coffee);
    std::cout << "Description: " << milkCoffee->getDescription() << ", Cost: $" << milkCoffee->cost() << std::endl;

    // Add sugar to the coffee
    Coffee* sugarCoffee = new SugarDecorator(milkCoffee);
    std::cout << "Description: " << sugarCoffee->getDescription() << ", Cost: $" << sugarCoffee->cost() << std::endl;

    delete coffee;
    delete milkCoffee;
    delete sugarCoffee;

    return 0;
}
