#include <iostream>
#include <string>

// Base Class (Parent)
class Vehicle {
protected: // Protected allows derived classes to access these variables directly
    std::string brand;
    int speed;

public:
    Vehicle(std::string b, int s) : brand(b), speed(s) {}

    void accelerate(int increase) {
        speed += increase;
        std::cout << brand << " accelerated. Current speed: " << speed << " km/h.\n";
    }

    void displayInfo() {
        std::cout << "Brand: " << brand << " | Current Speed: " << speed << " km/h\n";
    }
};

// Derived Class (Child) inheriting publicly from Vehicle
class ElectricCar : public Vehicle {
private:
    int batteryCapacity; // Unique property specific to ElectricCar

public:
    // Constructor initializes both base class members and its own
    ElectricCar(std::string b, int s, int battery) : Vehicle(b, s), batteryCapacity(battery) {}

    // Unique method specific to ElectricCar
    void chargeBattery() {
        std::cout << "Plugged in. Charging the " << brand << "'s " << batteryCapacity << " kWh battery...\n";
    }
};

int main() {
    // Create an object of the derived class
    ElectricCar myCar("Tesla Model 3", 50, 75);

    // Using inherited methods from the Vehicle base class
    myCar.displayInfo();
    myCar.accelerate(30);

    // Using the derived class's own unique method
    myCar.chargeBattery();

    return 0;
}