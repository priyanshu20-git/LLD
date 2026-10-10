#include <iostream>
#include <string>

// Abstract Class
class Appliance {
public:
    // Pure virtual function (makes this class abstract)
    virtual void turnOn() = 0;

    // Concrete method shared by all appliances
    void displayPowerStatus() {
        std::cout << "Appliance is connected to the power grid.\n";
    }

    virtual ~Appliance() {} // Virtual destructor
};

// Derived Class


/*The override keyword  is used in Object-Oriented Programming to explicitly 
tell the compiler that a method in a derived/subclass is intended to replace a virtual method inherited from a base class.*/


class WashingMachine : public Appliance {
public:
    // Must implement the pure virtual function
    void turnOn() override {
        std::cout << "Washing machine is filling with water and starting wash cycle.\n";
    }
};

int main() {
    // Appliance a; // Error: Cannot instantiate abstract class

    WashingMachine wm; // Valid
    wm.displayPowerStatus(); // Inherited concrete method
    wm.turnOn();             // Implemented abstract method

    return 0;
}