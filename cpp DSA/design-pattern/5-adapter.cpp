#include <iostream>
#include <string>

// Existing class with incompatible interface
class OldLogger {
public:
    void logMessage(const std::string& message) {
        std::cout << "OldLogger: " << message << std::endl;
    }
};

// New interface expected by the client
class LoggerInterface {
public:
    virtual void log(const std::string& message) = 0;
};

// Adapter class to make OldLogger compatible with LoggerInterface
class LoggerAdapter : public LoggerInterface {
private:
    OldLogger oldLogger;

public:
    void log(const std::string& message) override {
        oldLogger.logMessage(message);
    }
};

// New system using LoggerInterface
class NewSystem {
private:
    LoggerInterface* logger;

public:
    NewSystem(LoggerInterface* logger) : logger(logger) {}

    void doSomething() {
        logger->log("Logging from NewSystem");
    }
};

int main() {
    // Using the adapter to make OldLogger compatible with NewSystem
    LoggerAdapter adapter;
    NewSystem newSystem(&adapter);
    newSystem.doSomething();

    return 0;
}
