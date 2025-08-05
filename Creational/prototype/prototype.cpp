/**
 * @file        prototype.cpp
 * @brief       Demonstrates the Prototype Design Pattern in C++.
 *
 * @details     This example illustrates the Prototype Pattern.
 *
 *              This implementation includes:
 *              - Prototype
 *              - ConcretePrototype
 *              - Client
 *
 * @author      Kailasa Marathe
 * @date        2025-08-05
 * @version     1.0
 * @copyright   Copyright (c) 2025 Kailasa Marathe
 *              Licensed under the MIT License.
 *              See LICENSE file in the project root.
 */

#include <iostream>
#include <memory>
using namespace std;

/**
 * @class Vehicle
 * @brief Prototype class, interface for cloning.
 */
class Vehicle {
  public:
    virtual unique_ptr<Vehicle> clone() = 0;
    virtual void setColor(string c) = 0;
    virtual void setType(string t) = 0;
    virtual void display() = 0;
    ~Vehicle() {}
};
/**
 * @class Car
 * @brief A ConcretPrototype class, implements operation for cloning itself.
 */
class Car : public Vehicle {
    string color;
    string type;

  public:
    Car() : color("Black"), type("Car") {
        cout << " ---> Creating Car instance as prototype" << endl;
    }
    unique_ptr<Vehicle> clone() override {
        // deep copy. currently only string, uses its copy ctor
        return make_unique<Car>(*this);
    }
    void setColor(string c) override { color = c; }
    void setType(string t) override { type = t; }
    void display() override {
        cout << "\tType: " << type << " Color: " << color << endl;
    }
};
/**
 * @class Motorcycle
 * @brief A ConcretPrototype class, implements operation for cloning itself.
 */
class Motorcycle : public Vehicle {
    string color;
    string type;

  public:
    Motorcycle() : color("Blue"), type("Motorcycle") {
        cout << " ---> Creating Motorcycle instance as prototype" << endl;
    }
    unique_ptr<Vehicle> clone() override {
        // deep copy. currently only string, uses its copy ctor
        return make_unique<Motorcycle>(*this);
    }
    void setColor(string c) override { color = c; }
    void setType(string t) override { type = t; }
    void display() override {
        cout << "\tType: " << type << " Color: " << color << endl;
    }
};

int main() {
    unique_ptr<Vehicle> carproto = make_unique<Car>();
    carproto->display();
    unique_ptr<Vehicle> mcproto = make_unique<Motorcycle>();
    mcproto->display();

    cout << " ---> Creating clones of :" << endl;

    cout << "      Car:" << endl;
    unique_ptr<Vehicle> c = carproto->clone();
    c->setColor("White");
    c->display();

    cout << "      Motorycycle:" << endl;
    unique_ptr<Vehicle> m = mcproto->clone();
    m->setColor("yellow");
    m->display();
}