#include <iostream>
#include <vector>
#include <memory>

// Base Class
class Car {
public:
    // Virtual destructor is essential when using polymorphism to prevent memory leaks
    virtual ~Car() = default;

    // Pure virtual function makes Car an abstract class and 
    // forces derived classes to implement their own drive() behavior.
    virtual void drive() const = 0;
};

// Derived Class 1: Electric Car
class ElectricCar : public Car {
public:
    void drive() const override {
        std::cout << "Electric Car: Gliding silently with instant torque. No gear shifting required!\n";
    }
};

// Derived Class 2: Manual Car
class ManualCar : public Car {
public:
    void drive() const override {
        std::cout << "Manual Car: Engaging the clutch, shifting gears, and revving the engine.\n";
    }
};

int main() {
    // Create a collection (vector) of base class smart pointers
    std::vector<std::unique_ptr<Car>> garage;

    // Store different types of cars in the same collection
    garage.push_back(std::make_unique<ElectricCar>());
    garage.push_back(std::make_unique<ManualCar>());

    std::cout << "--- Starting the Fleet (Dynamic Polymorphism in Action) ---\n\n";

    // Loop through the garage and call drive()
    // The compiler doesn't know which drive() to call until the program runs!
    for (const auto& car : garage) {
        car->drive();
    }

    return 0;
}