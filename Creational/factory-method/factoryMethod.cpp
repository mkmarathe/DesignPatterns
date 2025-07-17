/**
 * @file        factoryMethod.cpp
 * @brief       Demonstrates the Factory Method Design Pattern in C++.
 *
 * @details     Implementation includes:
 *              - Product (Vehicle)
 *              - ConcreteProduct (Car, Truck)
 *              - Creator (VehicleFactory)
 *              - ConcreteCreator (CarFactory, TruckFactory)
 *              - Factory Method is manufactureVehicle()
 *              - Client code
 *
 * @author      Kailasa Marathe
 * @date        2025-07-17
 * @version     1.0
 * @copyright   Copyright (c) 2025 Kailasa Marathe
 *              Licensed under the MIT License.
 *              See LICENSE file in the project root.
 */
#include <iostream>
using namespace std;
/**
 * @class Vehicle
 * @brief Product
 */
class Vehicle {
  public:
    virtual void start() = 0;
    virtual void drive() = 0;
    virtual void stop() = 0;
};

/**
 * @class Car
 * @brief ConcreteProduct
 */
class Car : public Vehicle {
  public:
    void start() override { cout << "Car: Start" << endl; }
    void drive() override { cout << "Car: Drive" << endl; }
    void stop() override { cout << "Car: Stop" << endl; }
};

/**
 * @class Truck
 * @brief ConcreteProduct
 */
class Truck : public Vehicle {
  public:
    void start() override { cout << "Truck: Start" << endl; }
    void drive() override { cout << "Truck: Drive" << endl; }
    void stop() override { cout << "Truck: Stop" << endl; }
};

/**
 * @class VehicleFactory
 * @brief Creator
 */
class VehicleFactory {
  public:
    // Factory Method. Can have default implementation
    virtual Vehicle *manufactureVehicle() = 0;
    ~VehicleFactory() {}
};

/**
 * @class CarFactory
 * @brief ConcreteCreator
 */
class CarFactory : public VehicleFactory {
  public:
    Vehicle *manufactureVehicle() { return new Car(); }
};

/**
 * @class TruckFactory
 * @brief ConcreteCreator
 */
class TruckFactory : public VehicleFactory {
  public:
    Vehicle *manufactureVehicle() { return new Truck(); }
};

// driver  or client program

void useVehicle(Vehicle *v) {
    v->start();
    v->drive();
    v->stop();
}

int main() {
    // create factories.
    VehicleFactory *carfactory = new CarFactory;
    VehicleFactory *truckfactorry = new TruckFactory;

    // create vehicles in respective factories using factory method.
    Vehicle *car = carfactory->manufactureVehicle();
    Vehicle *truck = truckfactorry->manufactureVehicle();

    // use.
    useVehicle(car);
    useVehicle(truck);

    // cleanup
    delete car;
    delete carfactory;
    delete truck;
    delete truckfactorry;
}
