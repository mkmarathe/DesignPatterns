/**
 * @file        observer.cpp
 * @brief       Demonstrates the Observer  Design Pattern in C++.
 *
 * @details     Implementation includes:
 *              - Subject
 *              - ConcreteSubject
 *              - Observer
 *              - ConcreteObserver
 *              - Client
 *
 * @author      Kailasa Marathe
 * @date        2025-09-04
 * @version     1.0
 * @copyright   Copyright (c) 2025 Kailasa Marathe
 *              Licensed under the MIT License.
 *              See LICENSE file in the project root.
 */

#include <iostream>
#include <list>
using namespace std;

class Subject;
class Observer {
   public:
    virtual void update(Subject* theChangedSubject) = 0;
    virtual ~Observer() = default;

   protected:
    Observer() = default;
};

class Subject {
    list<Observer*> _observers;

   public:
    void attach(Observer* o) { _observers.push_back(o); }
    void detach(Observer* o) { _observers.remove(o); };
    void notify() {
        for (auto* val : _observers) {
            val->update(this);
        }
    }
    virtual ~Subject() = default;

   protected:
    Subject() = default;
};

class ConcreteSubject : public Subject {
    int _subjectState;

   public:
    ConcreteSubject() : _subjectState(0) {}
    int getState() const { return _subjectState; }
    void setState(int s) {
        _subjectState = s;
        notify();
    }
    ~ConcreteSubject() = default;
};

class ConcreteObserver : public Observer {
    int _observerState;
    ConcreteSubject* _concreteSubject;
    string _name;

   public:
    ConcreteObserver(ConcreteSubject* cs, const string& name)
        : _concreteSubject(cs), _name(name), _observerState(0) {
        cs->attach(this);
    }
    void update(Subject* theChangedSubject) override {
        // check if itsthe same subject that we are observing
        // simple comparision is fine as the derivation is from simple/single base
        if (theChangedSubject == _concreteSubject) {
            _observerState = _concreteSubject->getState();
            cout << "Observer: " << _name << ", State: " << _observerState << endl;
        }
    }
    ~ConcreteObserver() { _concreteSubject->detach(this); }
    ConcreteObserver(const ConcreteObserver&) = delete;
    ConcreteObserver& operator=(const ConcreteObserver&) = delete;
};
int main() {
    ConcreteSubject subject;
    ConcreteObserver a(&subject, "One");
    ConcreteObserver b(&subject, "Two");

    subject.setState(5);
    subject.setState(8);
}