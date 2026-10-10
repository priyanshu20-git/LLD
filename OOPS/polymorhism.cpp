#include <iostream>
#include <vector>

// Base Class
class Animal {
public:
    // Virtual function allows overriding and dynamic dispatch
    virtual void makeSound() {
        std::cout << "Some generic animal sound...\n";
    }

    virtual ~Animal() {} // Virtual destructor for safe cleanup
};

// Derived Class 1
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Dog says: Woof! Woof!\n";
    }
};

// Derived Class 2
class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Cat says: Meow~ Meow~\n";
    }
};

// Derived Class 3
class Cow : public Animal {
public:
    void makeSound() override {
        std::cout << "Cow says: Moo... Moo...\n";
    }
};

int main() {
    // A collection of base class pointers storing different derived objects
    std::vector<Animal*> zoo;
    zoo.push_back(new Dog());
    zoo.push_back(new Cat());
    zoo.push_back(new Cow());

    // Polymorphic behavior in action:
    // The exact same method call triggers different behaviors depending on the object.
    for (Animal* animal : zoo) {
        animal->makeSound(); 
    }

    // Clean up dynamically allocated memory
    for (Animal* animal : zoo) {
        delete animal;
    }

    return 0;
}