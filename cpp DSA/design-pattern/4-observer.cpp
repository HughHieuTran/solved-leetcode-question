#include <iostream>
#include <vector>
#include <algorithm>

// Forward declaration of observer interface
class Observer;

// Subject interface
class Subject {
public:
    virtual void registerObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
};

// Observer interface
class Observer {
public:
    virtual void update(float temperature) = 0;
};

// Concrete subject
class WeatherStation : public Subject {
private:
    float temperature;
    std::vector<Observer*> observers;

public:
    void setTemperature(float temp) {
        temperature = temp;
        notifyObservers();
    }

    void registerObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers() override {
        for (Observer* observer : observers) {
            observer->update(temperature);
        }
    }
};

// Concrete observer
class Display : public Observer {
private:
    float temperature;

public:
    void update(float temperature) override {
        this->temperature = temperature;
        display();
    }

    void display() {
        std::cout << "Current temperature is: " << temperature << " degrees Celsius." << std::endl;
    }
};

int main() {
    WeatherStation weatherStation;
    Display display1, display2;

    // Register observers
    weatherStation.registerObserver(&display1);
    weatherStation.registerObserver(&display2);

    // Simulate weather changes
    weatherStation.setTemperature(25.5f);

    // Remove one observer
    weatherStation.removeObserver(&display1);

    // Simulate another weather change
    weatherStation.setTemperature(30.0f);

    return 0;
}
