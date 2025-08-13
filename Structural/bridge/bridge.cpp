/**
 * @file        bridge.cpp
 * @brief       Demonstrates the Bridge Design Pattern in C++.
 *
 * @details     Implementation includes:
 *              - Abstraction (Shape)
 *              - RefinedAbstraction (Circle, Square)
 *              - Implementor (Renderer)
 *              - ConcreteImplementors (OpenGLRendere, DirectXRenderer)
 *              - Client
 *
 * @author      Kailasa Marathe
 * @date        2025-08-12
 * @version     1.0
 * @copyright   Copyright (c) 2025 Kailasa Marathe
 *              Licensed under the MIT License.
 *              See LICENSE file in the project root.
 */

#include <iostream>
using namespace std;

// Implementors
/***
 * @class RendererImp
 * @brief Implementor
 */
class RendererImp {
  public:
    virtual void renderShape() = 0;
};

// Concrete implementors

/**
 * @class DirectXRendererImp
 * @brief Concrete Implementor
 */
class DirectXRendererImp : public RendererImp {
  public:
    void renderShape() override { cout << "Rendering using DirectX" << endl; }
};

/**
 * @class OpenGLRendererImp
 * @brief Concrete Implementor
 */
class OpenGLRendererImp : public RendererImp {
  public:
    void renderShape() override { cout << "Rendering using OpenGL" << endl; }
};

/***
 * @class Shape
 * @brief Abstraction.
 */
class Shape {
  private:
    unique_ptr<RendererImp> renderer;

  protected:
    unique_ptr<RendererImp> &getRenderer() { return renderer; };

  public:
    Shape(unique_ptr<RendererImp> r) : renderer(move(r)) {}
    virtual void draw() = 0;
};

// Refined abstractions
/***
 * @class Circle
 * @brief RefinedAbstraction
 */
class Circle : public Shape {
  public:
    Circle(unique_ptr<RendererImp> r) : Shape(move(r)) {}
    void draw() override {
        cout << "Drawing Circle, ";
        getRenderer()->renderShape();
    }
};

/***
 * @class Square
 * @brief RefinedAbstraction
 */
class Square : public Shape {
  public:
    Square(unique_ptr<RendererImp> r) : Shape(move(r)) {}
    void draw() override {
        cout << "Drawing Square, ";
        getRenderer()->renderShape();
    }
};

int main() {
    // Shape is initialized with required renderer.
    unique_ptr<Shape> c1 =
        make_unique<Circle>(make_unique<OpenGLRendererImp>());
    unique_ptr<Shape> c2 =
        make_unique<Circle>(make_unique<DirectXRendererImp>());
    unique_ptr<Square> s1 =
        make_unique<Square>(make_unique<OpenGLRendererImp>());
    unique_ptr<Square> s2 =
        make_unique<Square>(make_unique<DirectXRendererImp>());

    c1->draw();
    c2->draw();
    s1->draw();
    s2->draw();
}