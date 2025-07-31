/**
 * @file        builder.cpp
 * @brief       Demonstrates the Builder Design Pattern in C++.
 *
 * @details     Implementation includes:
 *              - Builder (Builder)
 *              - ConcreteBuilder (SUVBuilder, TruckBuilder)
 *              - Director (Director)
 *              - Product (SUV, Truck)
 *              - Client code
 *
 * @author      Kailasa Marathe
 * @date        2025-07-28
 * @version     1.0
 * @copyright   Copyright (c) 2025 Kailasa Marathe
 *              Licensed under the MIT License.
 *              See LICENSE file in the project root.
 */

#include <iostream>
using namespace std;

/***
 * @classs SUV
 * @brief concrete product SUV. Note that abstract product is not necessary as
 * the products may not resemble each other.
 *
 */

class SUV {
    string Engine;
    string chassis;
    // Client must not see make*() methods below. Make them
    // protected/private and grant access to concrete builders using friend
    void makechassis() { chassis = "Complete"; }
    void makeEngine() { Engine = "Complete"; }
    friend class SUVBuilder;

  public:
    SUV() : Engine("Empty"), chassis("Empty") {}
    void show() {
        cout << "SUV:\tEngine:" << Engine << "\tChassis:" << chassis << endl;
    }
};

/***
 * @classs Truck
 * @brief concrete product Truck.Note that abstract product is not necessary as
 * the products may not resemble each other.
 */

class Truck {
    string Engine;
    string chassis;
    // Client must not see make*() methods below. Make them
    // protected/private and grant access to concrete builders using friend
    void makechassis() { chassis = "Complete"; }
    void makeEngine() { Engine = "Complete"; }
    friend class TruckBuilder;

  public:
    Truck() : Engine("Empty"), chassis("Empty") {};

    void show() {
        cout << "Truck:\tEngine:" << Engine << "\tChassis:" << chassis << endl;
    }
};

/**
 * @class Builder
 * @brief Builder class, an abstract interface used by Director to
 * build vehicles by part.
 */
class VehicleBuilder {
  public:
    virtual void buildchassis() {} // not pure virtual
    virtual void buildEngine() {}
    virtual ~VehicleBuilder() {}

  protected:
    VehicleBuilder() {};
};

/**
 * @class SUVBuilder
 * @brief ConcreteBuilder, implements Builder
 */
class SUVBuilder : public VehicleBuilder {
    SUV suv;

  public:
    SUVBuilder() {};
    void buildchassis() { suv.makechassis(); }
    void buildEngine() { suv.makeEngine(); }
    SUV getSUV() { return suv; }
};

/**
 * @class TruckBuilder
 * @brief ConcreteBuilder, implements Builder
 */
class TruckBuilder : public VehicleBuilder {
    Truck truck;

  public:
    void buildchassis() { truck.makechassis(); }
    void buildEngine() { truck.makeEngine(); }
    Truck getTruck() { return truck; }
};

/**
 * @class Director
 * @brief constructs vehicles using builder interface
 */
class Director {
  public:
    void construct(VehicleBuilder *b) {
        b->buildchassis();
        b->buildEngine();
    }
};

int main() {
    // create concrete builders
    SUVBuilder suvbuilder;
    TruckBuilder truckbuilder;

    // crete director, and build both vehicles
    Director director;

    suvbuilder.getSUV().show();
    truckbuilder.getTruck().show();

    director.construct(&suvbuilder);
    director.construct(&truckbuilder);

    // as clients know the concrete builder, they are aware of how to get
    // product.
    suvbuilder.getSUV().show();
    truckbuilder.getTruck().show();

    return 0;
}
