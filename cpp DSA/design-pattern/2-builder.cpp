#include <iostream>
#include <string>
#include <vector>

// Product: Pizza
class Pizza
{
private:
    std::string dough;
    std::string sauce;
    std::vector<std::string> toppings;

public:
    void setDough(const std::string &dough)
    {
        this->dough = dough;
    }

    void setSauce(const std::string &sauce)
    {
        this->sauce = sauce;
    }

    void addTopping(const std::string &topping)
    {
        this->toppings.push_back(topping);
    }

    void showPizza() const
    {
        std::cout << "Pizza with " << dough << " dough and " << sauce << " sauce." << std::endl;
        std::cout << "Toppings:" << std::endl;
        for (const auto &topping : toppings)
        {
            std::cout << "- " << topping << std::endl;
        }
    }
};

// Builder Interface
class PizzaBuilder
{
public:
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildToppings() = 0;
    virtual Pizza *getPizza() = 0;
};

// Concrete Builder
class HawaiianPizzaBuilder : public PizzaBuilder
{
private:
    Pizza *pizza;

public:
    HawaiianPizzaBuilder()
    {
        pizza = new Pizza();
    }

    void buildDough() override
    {
        pizza->setDough("thin crust");
    }

    void buildSauce() override
    {
        pizza->setSauce("tomato");
    }

    void buildToppings() override
    {
        pizza->addTopping("ham");
        pizza->addTopping("pineapple");
        pizza->addTopping("cheese");
    }

    Pizza *getPizza() override
    {
        return pizza;
    }
};

// Director
class PizzaDirector
{
private:
    PizzaBuilder *pizzaBuilder;

public:
    void setPizzaBuilder(PizzaBuilder *builder)
    {
        pizzaBuilder = builder;
    }

    Pizza *getPizza()
    {
        return pizzaBuilder->getPizza();
    }

    void constructPizza()
    {
        pizzaBuilder->buildDough();
        pizzaBuilder->buildSauce();
        pizzaBuilder->buildToppings();
    }
};

int main()
{
    PizzaDirector director;
    HawaiianPizzaBuilder hawaiianPizzaBuilder;

    director.setPizzaBuilder(&hawaiianPizzaBuilder);
    director.constructPizza();

    Pizza *pizza = director.getPizza();
    pizza->showPizza();

    delete pizza; // Don't forget to delete dynamically allocated memory

    return 0;
}
