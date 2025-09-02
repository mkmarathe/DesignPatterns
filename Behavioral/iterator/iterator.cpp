/**
 * @file        iterator.cpp
 * @brief       Demonstrates the Iterator Design Pattern in C++.
 *
 * @details     Implementation includes:
 *              - Iterator
 *              - ConcreteIterator
 *              - Aggregate
 *              - ConcreteAggregate
 *              - Client
 *
 * @author      Kailasa Marathe
 * @date        2025-08-28
 * @version     1.0
 * @copyright   Copyright (c) 2025 Kailasa Marathe
 *              Licensed under the MIT License.
 *              See LICENSE file in the project root.
 */

#include <iostream>
using namespace std;

/***
 * @class Iterator
 * @brief Abstract class for iterators to implement traversal over aggregates.
 */
template <class Item>
class Iterator {
   public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual Item& currentItem() = 0;
    virtual ~Iterator() = default;

   protected:
    Iterator() = default;
};

/***
 * @class Aggregate
 * @brief nterface to create an iterataor objct
 */
template <class Item>
class Aggregate {
   public:
    virtual unique_ptr<Iterator<Item>> createIterator() = 0;
    virtual ~Aggregate() = default;
};

/***
 * @class ConcreteAggregate
 * @brief implements iteration creation interface that returns concreate
 * iterator.
 */
template <class Item>
class List : public Aggregate<Item> {
    struct Node {
        Item data;
        unique_ptr<Node> next;
        Node(Item v) : data(v), next(nullptr) {}
    };
    unique_ptr<Node> head;
    Node* tail;

   public:
    List() : head(nullptr), tail(nullptr) {}

    void add(Item val) {
        unique_ptr<Node> newnode = make_unique<Node>(val);
        auto newtail = newnode.get();
        *(tail ? &(tail->next) : &head) = move(newnode);
        tail = newtail;
    }
    /* Concrete Iterator */
    class ListIterator : public Iterator<Item> {
        Node* current;
        Node* head;

       public:
        void first() override { current = head; };
        void next() override {
            if (!isDone()) current = current->next.get();
        };
        bool isDone() override { return current == nullptr; };
        Item& currentItem() override { return current->data; };
        ListIterator(Node* begin) : current(begin), head(begin) {}
    };

    // factory method
    unique_ptr<Iterator<Item>> createIterator() override {
        return make_unique<ListIterator>(head.get());
    }
};

int main() {
    List<int> nums;
    nums.add(1);
    nums.add(2);
    nums.add(3);
    auto it = nums.createIterator();
    while (!it->isDone()) {
        cout << it->currentItem() << endl;
        it->next();
    }
    // reset iterator to the begining
    it->first();
    while (!it->isDone()) {
        cout << it->currentItem() << endl;
        it->next();
    }
}
