/**
 * @file        proxy.cpp
 * @brief       Demonstrates the Proxy Design Pattern in C++.
 *
 * @details     Implementation includes:
 *              - Subject (Image)
 *              - Proxy (ProxyImage)
 *              - RealSubject (RealImage)
 *              - Client
 *
 * @author      Kailasa Marathe
 * @date        2025-08-25
 * @version     1.0
 * @copyright   Copyright (c) 2025 Kailasa Marathe
 *              Licensed under the MIT License.
 *              See LICENSE file in the project root.
 */

#include <iostream>
using namespace std;
/***
 * @class Image
 * @brief Subject class, an abstract interface that client uses
 */
class Image {
  public:
    virtual void requestImage() = 0;
    virtual ~Image() = default;
};

/***
 * @class RealImage
 * @brief Real subject that proxy represents
 */

class RealImage : public Image {
    string filename;

  public:
    RealImage(const string f) : filename(f) {
        cout << "RealImage: Loading Image " << endl;
    }
    void requestImage() override {
        cout << "RealImage: " << filename << " Served" << endl;
    }
};

/***
 * @class ProxyImage
 * @brief Provides  an interface identical to Subject's, so that a proxy can be
 * substituted for the real subject.
 */

class ProxyImage : public Image {
    string filename;
    unique_ptr<RealImage> realImg;

  public:
    ProxyImage(const string filename) : filename(filename), realImg(nullptr) {}
    void requestImage() override {
        cout << "Proxy: Image requested " << endl;
        if (!realImg) {
            realImg = make_unique<RealImage>(
                move(filename)); // we dont need filename anymore
        }
        realImg->requestImage();
    }
};

int main() {
    unique_ptr<Image> img = make_unique<ProxyImage>("test.jpg");
    cout << "Client Req 1" << endl;
    img->requestImage();
    cout << "Client Req 2" << endl;
    img->requestImage();
}