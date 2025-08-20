/**
 * @file        composite.cpp
 * @brief       Demonstrates the Composite Design Pattern in C++.
 *
 * @details     Implementation includes:
 *              - Component (FileSystemComponent)
 *              - Leaf (File)
 *              - Composite (Directory)
 *              - Client
 *
 * @author      Kailasa Marathe
 * @date        2025-08-14
 * @version     1.0
 * @copyright   Copyright (c) 2025 Kailasa Marathe
 *              Licensed under the MIT License.
 *              See LICENSE file in the project root.
 */

#include <iostream>
#include <vector>
using namespace std;
/***
 * @class FileSysteComponent
 * @brief Component: abstract class for file and directory
 *  "- implements default behavior for the interface common to all classes, as
 * appropriate."
 */
class FileSystemComponent {
  public:
    virtual ~FileSystemComponent() = default;
    // Maximizing the Component interface. so accomodate add() too,
    // even if it does not apply to File(leaf).
    virtual void add(unique_ptr<FileSystemComponent> &&) {
        // Default behaviour for subclassess where add() does not apply
        cout << "Add is not valid" << endl;
        throw std::runtime_error("Cannot add to a File");
    };
    virtual string getName() const = 0;
    virtual int getSize() const = 0;
    virtual void display(int indent = 0) const = 0;
};

/***
 * @class File
 * @brief Leaf: Represents file
 */

class File : public FileSystemComponent {
    int size_;
    string name_;

  public:
    File(const string &name, int size) : name_(name), size_(size) {}
    ~File() = default;

    string getName() const override { return name_; }
    int getSize() const override { return size_; }
    void display(int indent) const override {
        cout << string(indent, ' ') << "File: " << name_ << endl;
    }
};

/**
 * @class Directory
 * @brief Composite: Represents directory
 */

class Directory : public FileSystemComponent {
    string name_;
    vector<unique_ptr<FileSystemComponent>> children_;

  public:
    Directory(const string &name) : name_(name) {}
    ~Directory() = default;
    void add(unique_ptr<FileSystemComponent> &&component) override {
        cout << "Adding " << component->getName() << " to " << name_ << endl;
        children_.push_back(move(component));
    }
    string getName() const override { return name_; }
    int getSize() const override {
        int totalSize = 0;
        for (const auto &component : children_) {
            totalSize += component->getSize();
        }
        return totalSize;
    }
    void display(int indent) const override {
        string indentStr(indent, ' ');
        cout << indentStr << "Directory: " << name_ << endl;
        for (auto &component : children_) {
            component->display(indent + 2);
        }
    }
};

int main() {
    std::unique_ptr<FileSystemComponent> root = make_unique<Directory>("Root");
    std::unique_ptr<FileSystemComponent> dir1 = make_unique<Directory>("Dir1");
    std::unique_ptr<FileSystemComponent> file0 = make_unique<File>("File0", 9);
    std::unique_ptr<FileSystemComponent> file1 = make_unique<File>("File1", 10);
    std::unique_ptr<FileSystemComponent> file2 = make_unique<File>("File2", 11);
    std::unique_ptr<FileSystemComponent> file3 = make_unique<File>("File3", 12);

    // Check if file1 is a Directory before doing add(file2)
    // if not, we lose file2 ownership.

    try {
        // nullptr used insteaded of say file2 to prevent move
        file1->add(nullptr);
    } catch (const runtime_error &e) {
        cout << "Exception: " << e.what() << endl;
    }

    dir1->add(move(file1));
    dir1->add(move(file2));
    dir1->add(move(file3));
    root->add(move(dir1));
    root->add(move(file0));

    cout << "===========" << endl;
    root->display();
}
