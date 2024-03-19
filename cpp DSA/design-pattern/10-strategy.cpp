#include <iostream>
#include <string>

// Strategy interface
class PaymentStrategy {
public:
    virtual void pay(double amount) const = 0;
    virtual ~PaymentStrategy() {}
};

// Concrete strategy: Credit Card payment
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(double amount) const override {
        std::cout << "Paid $" << amount << " using Credit Card." << std::endl;
    }
};

// Concrete strategy: PayPal payment
class PayPalPayment : public PaymentStrategy {
public:
    void pay(double amount) const override {
        std::cout << "Paid $" << amount << " using PayPal." << std::endl;
    }
};

// Concrete strategy: Bitcoin payment
class BitcoinPayment : public PaymentStrategy {
public:
    void pay(double amount) const override {
        std::cout << "Paid $" << amount << " using Bitcoin." << std::endl;
    }
};

// Context class
class PaymentContext {
private:
    PaymentStrategy* strategy;

public:
    PaymentContext(PaymentStrategy* strategy) : strategy(strategy) {}

    void setPaymentStrategy(PaymentStrategy* strategy) {
        this->strategy = strategy;
    }

    void executePayment(double amount) const {
        strategy->pay(amount);
    }
};

int main() {
    // Create payment strategies
    PaymentStrategy* creditCard = new CreditCardPayment();
    PaymentStrategy* payPal = new PayPalPayment();
    PaymentStrategy* bitcoin = new BitcoinPayment();

    // Create context with default payment strategy
    PaymentContext paymentContext(creditCard);

    // Execute payments with different strategies
    paymentContext.executePayment(100.0);
    paymentContext.setPaymentStrategy(payPal);
    paymentContext.executePayment(50.0);
    paymentContext.setPaymentStrategy(bitcoin);
    paymentContext.executePayment(200.0);

    // Cleanup
    delete creditCard;
    delete payPal;
    delete bitcoin;

    return 0;
}
