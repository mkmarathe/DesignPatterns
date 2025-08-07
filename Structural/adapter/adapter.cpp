/**
 * @file        adapter.cpp
 * @brief       Demonstrates the Adapter Design Pattern in C++.
 *
 * @details     Implementation includes:
 *              - Target
 *              - Adaptee
 *              - Adapter
 *              - Client
 *
 * @author      Kailasa Marathe
 * @date        2025-08-07
 * @version     1.0
 * @copyright   Copyright (c) 2025 Kailasa Marathe
 *              Licensed under the MIT License.
 *              See LICENSE file in the project root.
 */
#include <iostream>
using namespace std;

/***
 * @class Target
 * @brief Interface that client uses.
 */
class Target {
  public:
    virtual void request() = 0;
    virtual ~Target() = default;
};

/***
 * @class Adaptee
 * @brief Interface that needs to be adapted by adapter.
 */
class Adaptee {
  public:
    void spefificRequest() { cout << "Adaptees spefificRequest()" << endl; }
};

/***
 * @class Adapter
 * @brief Adapts Adaptee's interface to Target
 */
class Adapter : public Target, private Adaptee {
  public:
    void request() override {
        cout << "Adapter request() --> ";
        // call actual request handler
        spefificRequest();
    }
};

// client

int main() {
    Target *t = new Adapter;
    t->request();
    delete t;
}