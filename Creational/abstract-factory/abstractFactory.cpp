/**
 * @file        abstractFactory.cpp
 * @brief       Demonstrates the Abstract Factory Design Pattern in C++.
 *
 * @details     This example illustrates the Abstract Factory Pattern.
 *
 *              This implementation includes:
 *              - Abstract Factory interface
 *              - Concrete Factories
 *              - Abstract Products
 *              - Concrete Products
 *              - Client code that uses only the abstract interfaces
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

/**
 * @class
 * @brief abstract button product
 */
class button {
  public:
    button() { cout << "Abstract product Button" << endl; }
};

/**
 * @class
 * @brief abstract scrollbar product
 */
class scrollBar {
  public:
    scrollBar() { cout << "Abstract product ScrollBar" << endl; }
};

/**
 * @class
 * @brief concrete button for Wincows
 */
class winButton : public button {
  public:
    winButton() { cout << "Concrete product WinButton" << endl; }
};

/**
 * @class
 * @brief concrete button for Mac
 */
class macButton : public button {
  public:
    macButton() { cout << "Concrete product macButton" << endl; }
};

/**
 * @class
 * @brief concrete sccrollbar for Windows
 */
class winScrollBar : public scrollBar {
  public:
    winScrollBar() { cout << "Concrete product winScrollBar" << endl; }
};

/**
 * @class
 * @brief concrete sccrollbar for Mac
 */
class macScrollBar : public scrollBar {
  public:
    macScrollBar() { cout << "Concreate product macScrollBar" << endl; }
};

/**
 * @class UIFactory
 * @brief Abstract factory class
 */

class UIFactory {
  public:
    UIFactory() { cout << "Abstract factory" << endl; }
    virtual button *drawButton() = 0;
    virtual scrollBar *drawScrollBar() = 0;
    virtual ~UIFactory() {}
};

/**
 * @class WinUI
 * @brief concrete factory class Windows
 */
class WinUI : public UIFactory {
  public:
    WinUI() { cout << "Concrete Windows factory" << endl; }
    button *drawButton() { return new winButton; }
    scrollBar *drawScrollBar() { return new winScrollBar; }
    ~WinUI() {}
};

/**
 * @class MacUI
 * @brief concrete factory class for Mac.
 */
class MacUI : public UIFactory {
  public:
    MacUI() { cout << "Concrete Mac factory" << endl; };
    button *drawButton() { return new macButton; }
    scrollBar *drawScrollBar() { return new macScrollBar; }
    ~MacUI() {}
};

int main() {
    cout << "********Create Mac UI********\n" << endl;
    unique_ptr<UIFactory> mac(new MacUI); // use a selector
    unique_ptr<button> mbutton(mac->drawButton());
    unique_ptr<scrollBar> mscroll(mac->drawScrollBar());

    cout << "\n********Create Windows UI********\n" << endl;

    unique_ptr<UIFactory> win(new WinUI); // use a selector
    unique_ptr<button> wbutton(win->drawButton());
    unique_ptr<scrollBar> wscroll(win->drawScrollBar());
}