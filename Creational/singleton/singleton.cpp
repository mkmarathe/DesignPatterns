/**
 * @file        singleton.cpp
 * @brief       Demonstrates the Singleton Design Pattern in C++.
 *
 * @details     Shows Singleton pattern ensuring one instance with
 *              global access, using private/protected(for subclassing)
 *              constructor and static method.
 *
 * @author      Kailasa Marathe
 * @date        2025-07-10
 * @version     1.0
 * @copyright   Copyright (c) 2025 Kailasa Marathe
 *              Licensed under the MIT License.
 *              See LICENSE file in the project root.
 */

#include <iostream>

using namespace std;
class singleton {
    static singleton *_instance;
    singleton() {}

  public:
    singleton(singleton &) = delete;
    singleton &operator=(singleton &) = delete;
    static singleton *instance() {
        if (_instance == nullptr) {
            _instance = new singleton;
            cout << "Instance created" << endl;
        }
        cout << "Returning instance" << endl;
        return _instance;
    }
};

singleton *singleton::_instance = nullptr;

int main() {
    singleton *s = singleton::instance();
    singleton *s1 = singleton::instance();
}