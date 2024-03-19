#include <iostream>

class Singleton {
public:
    // Static method to get the singleton instance
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    // Method to perform some operation
    void someOperation() {
        std::cout << "Performing some operation..." << std::endl;
    }

private:
    // Private constructor to prevent instantiation
    Singleton() {}

    // Private copy constructor and assignment operator to prevent cloning
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

int main() {
    // Access the singleton instance
    Singleton& singleton = Singleton::getInstance();
    singleton.someOperation();

    // Attempting to create another instance will return the same instance
    Singleton& singleton2 = Singleton::getInstance();
    std::cout << std::boolalpha << (&singleton == &singleton2) << std::endl;  // Outputs: true

    return 0;
}
